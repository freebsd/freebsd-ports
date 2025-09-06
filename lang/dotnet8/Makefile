PORTNAME=	dotnet
DISTVERSIONPREFIX=	v
DISTVERSION=	${DOTNETVERSION}.6
PORTREVISION=	5
CATEGORIES=	lang devel
MASTER_SITES=	https://github.com/dotnet/dotnet/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/release.json?dummy=/:dotnetmanifest \
		LOCAL/arrowd/dotnet/:bootstrap
PKGNAMESUFFIX=	8
DISTFILES=	release.json-${PORTVERSION}:dotnetmanifest \
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
LIB_DEPENDS=	libicuuc.so:devel/icu \
		libinotify.so:devel/libinotify \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	terminfo-db>0:misc/terminfo-db \
		dotnet:lang/dotnet-host

USES=		autoreconf:build gssapi:mit llvm:noexport nodejs pkgconfig \
		python:build,3.9+ shebangfix ssl

USE_GITHUB=	yes

SHEBANG_FILES=	src/diagnostics/src/Tools/dotnet-trace/*.sh \
		src/source-build-externals/src/azure-activedirectory-identitymodel-extensions-for-dotnet/updateAssemblyInfo.sh

BINARY_ALIAS=	grep=${LOCALBASE}/bin/ggrep
DOTNET_ENV=	PYTHON=${PYTHON_CMD} PATH=${PATH}:${LLVM_PREFIX}/bin

BOOTSTRAP_DOTNETVERSION=			8.0
BOOTSTRAP_SDKVERSION=				${BOOTSTRAP_DOTNETVERSION}.100
BOOTSTRAP_SDKVERSIONSUFFIX=			-rtm.23551.1
BOOTSTRAP_SOURCEBUILT_ARTIFACTS_DISTNAME=	Private.SourceBuilt.Artifacts.${BOOTSTRAP_SDKVERSION}${BOOTSTRAP_SDKVERSIONSUFFIX}.freebsd.13-${DOTNET_ARCH}
BOOTSTRAP_SDK_DISTNAME=				dotnet-sdk-${BOOTSTRAP_SDKVERSION}-freebsd-${DOTNET_ARCH}

DOTNETVERSION=			8.0
SDKVERSION=			${DOTNETVERSION}.106
SDKVERSIONSUFFIX=		-servicing.24272.10
SOURCEBUILT_ARTIFACTS_DISTNAME=	Private.SourceBuilt.Artifacts.${SDKVERSION}${SDKVERSIONSUFFIX}.freebsd.13-${DOTNET_ARCH}
SDK_DISTNAME=			dotnet-sdk-${SDKVERSION}-freebsd-${DOTNET_ARCH}
DOTNET_ARCH=				${ARCH:S|amd64|x64|:C|aarch64|arm64|}

PLIST_SUB=			DOTNET_ARCH=${DOTNET_ARCH} FULL_DOTNETVERSION=${PORTVERSION} \
				DOTNETVERSION=${DOTNETVERSION} \
				SDKVERSION=${SDKVERSION} SDKVERSIONSUFFIX=${SDKVERSIONSUFFIX} \
				BOOTSTRAP_SDKVERSION=${BOOTSTRAP_SDKVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1400000
LIB_DEPENDS+=	libcrypto.so.111:misc/compat13x
.endif

.if ${ARCH} == aarch64
BROKEN=		"crossgen2" exited with code 139
.endif

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/release.json-${PORTVERSION} ${WRKSRC}/release.json

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
		--release-manifest release.json \
		--clean-while-building \
		--with-sdk ${WRKDIR}/bootstrap_sdk \
		--with-packages ${WRKDIR}/packages \
		-- \
		-maxcpucount:${MAKE_JOBS_NUMBER}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}/artifacts/${DOTNET_ARCH}/Release/${SDK_DISTNAME}${EXTRACT_SUFX} -C ${STAGEDIR}${DATADIR} ${EXTRACT_AFTER_ARGS}
	${RM} -r ${STAGEDIR}${DATADIR}/packs/NETStandard.Library.Ref

	${STRIP_CMD} ${STAGEDIR}${DATADIR}/sdk/${SDKVERSION}/AppHostTemplate/apphost
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/packs/Microsoft.NETCore.App.Host.freebsd-${DOTNET_ARCH}/${DISTVERSION}/runtimes/freebsd-${DOTNET_ARCH}/native/apphost
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/packs/Microsoft.NETCore.App.Host.freebsd-${DOTNET_ARCH}/${DISTVERSION}/runtimes/freebsd-${DOTNET_ARCH}/native/singlefilehost
	${FIND} ${STAGEDIR}${DATADIR} -name "*.so" -exec ${STRIP_CMD} -s "{}" ";"

bootstrap-makesum:
	cd ${WRKSRC}/artifacts/${DOTNET_ARCH}/Release && sha256 ${SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}
	@${ECHO_CMD} -n "SIZE (${SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}) = "
	@${STAT} -f %z ${WRKSRC}/artifacts/${DOTNET_ARCH}/Release/${SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}

	@cd ${WRKSRC}/artifacts/${DOTNET_ARCH}/Release && sha256 ${SDK_DISTNAME}${EXTRACT_SUFX}
	@${ECHO_CMD} -n "SIZE (${SDK_DISTNAME}${EXTRACT_SUFX}) = "
	@${STAT} -f %z ${WRKSRC}/artifacts/${DOTNET_ARCH}/Release/${SDK_DISTNAME}${EXTRACT_SUFX}

	@${ECHO_CMD}

.include <bsd.port.post.mk>
