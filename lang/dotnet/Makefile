PORTNAME=	dotnet
DISTVERSION?=	${DOTNETVERSION}.10
PORTREVISION?=	0
CATEGORIES=	lang devel
MASTER_SITES=	${NO_RELEASE_JSON:Uhttps\://github.com/dotnet/dotnet/releases/download/${GH_TAGNAME}/release.json?dummy=/\:dotnetmanifest} \
		LOCAL/arrowd/dotnet/:bootstrap
DISTFILES=	${NO_RELEASE_JSON:Urelease.json-${PORTVERSION}\:dotnetmanifest} \
		${BOOTSTRAP_SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}:bootstrap \
		${BOOTSTRAP_SDK_DISTNAME}${EXTRACT_SUFX}:bootstrap
DIST_SUBDIR=	dotnet
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Open-source developer platform and a cross-platform runtime for cloud, mobile, desktop, and IoT apps
WWW=		https://dot.net

LICENSE=	MIT

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake-core \
		git:devel/git \
		ggrep:textproc/gnugrep \
		terminfo-db>0:misc/terminfo-db
LIB_DEPENDS=	libbrotlienc.so:archivers/brotli \
		libicuuc.so:devel/icu \
		libinotify.so:devel/libinotify \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	terminfo-db>0:misc/terminfo-db \
		dotnet:lang/dotnet-host

USES=		autoreconf:build gssapi:mit llvm:noexport pkgconfig \
		python:build,3.9+ shebangfix ssl

USE_GITHUB=	yes
GH_TAGNAME?=	v${SDKVERSION}

SHEBANG_FILES+=	src/diagnostics/src/Tools/dotnet-trace/*.sh

BINARY_ALIAS=	grep=${LOCALBASE}/bin/ggrep
DOTNET_ENV+=	PYTHON=${PYTHON_CMD}

BOOTSTRAP_DOTNETVERSION?=			9.0
BOOTSTRAP_SDKVERSION?=				${BOOTSTRAP_DOTNETVERSION}.110
BOOTSTRAP_SDKVERSIONSUFFIX?=			-servicing.25421.1
BOOTSTRAP_SOURCEBUILT_ARTIFACTS_DISTNAME=	Private.SourceBuilt.Artifacts.${BOOTSTRAP_SDKVERSION}${BOOTSTRAP_SDKVERSIONSUFFIX}.freebsd.13-${DOTNET_ARCH}
BOOTSTRAP_SDK_DISTNAME=				dotnet-sdk-${BOOTSTRAP_SDKVERSION}-freebsd-${DOTNET_ARCH}

DOTNETVERSION?=		9.0
SDKVERSION?=		${DOTNETVERSION}.111
SDKVERSIONSUFFIX?=	-servicing.25475.17
SDKSERVICESUFFIX?=	-servicing.25476.1
MANIFESTSUFFIX=		${DOTNETVERSION}.100
DOTNET_ARCH=		${ARCH:S|amd64|x64|:C|aarch64|arm64|}
SDK_DISTNAME?=		dotnet-sdk-${SDKVERSION}-${SDK_RID}
SDK_RID?=		freebsd.${_OSVERSION_MAJOR}-${DOTNET_ARCH}
DOTNET_BUILD_SH_EXTRA_FLAGS?=	--source-build
.ifndef NO_RELEASE_JSON
DOTNET_BUILD_SH_SOURCELINK_FLAG=	--release-manifest release.json
.else
DOTNET_BUILD_SH_SOURCELINK_FLAG=	--source-repository https://github.com/dotnet/dotnet \
					--source-version ${GH_TAGNAME}
.endif

ARTIFACTS_SUBDIR?=	/artifacts/assets/Release
SOURCEBUILT_ARTIFACTS_DISTNAME?=Private.SourceBuilt.Artifacts.${SDKVERSION}${SDKSERVICESUFFIX}.freebsd-${DOTNET_ARCH}

PLIST_SUB=	DOTNET_ARCH=${DOTNET_ARCH} FULL_DOTNETVERSION=${DISTVERSION} \
		DOTNETVERSION=${DOTNETVERSION} SDKVERSION=${SDKVERSION} \
		SDK_RID=${SDK_RID} SDKVERSIONSUFFIX=${SDKVERSIONSUFFIX} \
		SDKSERVICESUFFIX=${SDKSERVICESUFFIX} MANIFESTSUFFIX=${MANIFESTSUFFIX}

.if defined(DOTNET_PORTABLE)
SDK_RID=		freebsd-${DOTNET_ARCH}
PORTABLE_BUILD_FLAG=	/p:PortableBuild=true
PLIST_SUB+=	NONPORTABLE="@comment "
.else
PLIST_SUB+=	NONPORTABLE=
.endif

.include <bsd.port.pre.mk>

.if ${DOTNETVERSION:R} == 8 && ${ARCH} == aarch64
BROKEN=		"crossgen2" exited with code 139
.endif

.if ${SSL_DEFAULT} == base && ${DOTNETVERSION:R} > 8
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-base-openssl
.endif

.if ${OSVERSION} >= 1400000
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libssl.so.111:misc/compat13x
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	VXSORT=
.else
PLIST_SUB+=	VXSORT="@comment "
.endif

post-extract:
.ifndef NO_RELEASE_JSON
	${CP} ${DISTDIR}/${DIST_SUBDIR}/release.json-${PORTVERSION} ${WRKSRC}/release.json
.endif

	@${MKDIR} ${WRKDIR}/packages
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/${BOOTSTRAP_SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX} \
		-C ${WRKDIR}/packages \
		${EXTRACT_AFTER_ARGS}

	@${MKDIR} ${WRKDIR}/bootstrap_sdk
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/${BOOTSTRAP_SDK_DISTNAME}${EXTRACT_SUFX} \
		-C ${WRKDIR}/bootstrap_sdk \
		${EXTRACT_AFTER_ARGS}

	${ELFCTL} -e +noaslr ${WRKDIR}/bootstrap_sdk/dotnet

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${DOTNET_ENV} ./build.sh \
		${DOTNET_BUILD_SH_SOURCELINK_FLAG} \
		--clean-while-building \
		--with-sdk ${WRKDIR}/bootstrap_sdk \
		--with-packages ${WRKDIR}/packages \
		${DOTNET_BUILD_SH_EXTRA_FLAGS} \
		-- \
		-maxcpucount:${MAKE_JOBS_NUMBER} \
		${PORTABLE_BUILD_FLAG}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}${ARTIFACTS_SUBDIR}/${SDK_DISTNAME}${EXTRACT_SUFX} -C ${STAGEDIR}${DATADIR} ${EXTRACT_AFTER_ARGS}
.if ${DOTNETVERSION:R} == 8
	${RM} -r ${STAGEDIR}${DATADIR}/packs/NETStandard.Library.Ref
.else
	${FIND} ${WRKSRC}/artifacts/packages/Release -name "*freebsd*.nupkg" -exec \
		${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/library-packs/ \;
.endif

	${STRIP_CMD} ${STAGEDIR}${DATADIR}/sdk/${SDKVERSION}/AppHostTemplate/apphost
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/packs/Microsoft.NETCore.App.Host.${SDK_RID}/${DISTVERSION}/runtimes/${SDK_RID}/native/apphost
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/packs/Microsoft.NETCore.App.Host.${SDK_RID}/${DISTVERSION}/runtimes/${SDK_RID}/native/singlefilehost
.if ${DOTNETVERSION:R} > 8
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/packs/runtime.${SDK_RID}.Microsoft.DotNet.ILCompiler/${DISTVERSION}/tools/ilc
.endif
	${FIND} ${STAGEDIR}${DATADIR} -name "*.so" -exec ${STRIP_CMD} -s "{}" ";"

bootstrap-makesum:
	cd ${WRKSRC}${ARTIFACTS_SUBDIR} && sha256 ${SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}
	@${ECHO_CMD} -n "SIZE (${DIST_SUBDIR}/${SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}) = "
	@${STAT} -f %z ${WRKSRC}${ARTIFACTS_SUBDIR}/${SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}

	@cd ${WRKSRC}${ARTIFACTS_SUBDIR} && sha256 ${SDK_DISTNAME}${EXTRACT_SUFX}
	@${ECHO_CMD} -n "SIZE (${DIST_SUBDIR}/${SDK_DISTNAME}${EXTRACT_SUFX}) = "
	@${STAT} -f %z ${WRKSRC}${ARTIFACTS_SUBDIR}/${SDK_DISTNAME}${EXTRACT_SUFX}

	@${ECHO_CMD}

.include <bsd.port.post.mk>
