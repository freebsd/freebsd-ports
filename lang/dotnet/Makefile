PORTNAME=	dotnet
DISTVERSIONPREFIX=	v
DISTVERSION=	${DOTNETVERSION}.0
PORTREVISION=	2
CATEGORIES=	lang devel
MASTER_SITES=	https://github.com/dotnet/dotnet/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/release.json?dummy=/:dotnetmanifest \
		https://github.com/sec/dotnet-core-freebsd-source-build/releases/download/9.0.0-rc.2-native/:bootstrap
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
LIB_DEPENDS=	libbrotlienc.so:archivers/brotli \
		libicuuc.so:devel/icu \
		libinotify.so:devel/libinotify \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	terminfo-db>0:misc/terminfo-db \
		dotnet:lang/dotnet-runtime

USES=		autoreconf:build gssapi:mit llvm:noexport pkgconfig \
		python:build,3.9+ shebangfix ssl

USE_GITHUB=	yes

SHEBANG_FILES=	src/diagnostics/src/Tools/dotnet-trace/*.sh

BINARY_ALIAS=	grep=${LOCALBASE}/bin/ggrep
DOTNET_ENV=	PYTHON=${PYTHON_CMD}

BOOTSTRAP_DOTNETVERSION=			9.0
BOOTSTRAP_SDKVERSION=				${BOOTSTRAP_DOTNETVERSION}.100
BOOTSTRAP_SDKVERSIONSUFFIX=			-rc.2.24474.1
BOOTSTRAP_SDKVERSIONBINSUFFIX=			-rc.2.24474.11
BOOTSTRAP_SOURCEBUILT_ARTIFACTS_DISTNAME=	Private.SourceBuilt.Artifacts.${BOOTSTRAP_SDKVERSION}${BOOTSTRAP_SDKVERSIONSUFFIX}.freebsd.13-${DOTNET_ARCH}
BOOTSTRAP_SDK_DISTNAME=				dotnet-sdk-${BOOTSTRAP_SDKVERSION}${BOOTSTRAP_SDKVERSIONBINSUFFIX}-freebsd-${DOTNET_ARCH}

DOTNETVERSION=		9.0
SDKVERSION=		${DOTNETVERSION}.100
SDKVERSIONSUFFIX=	-rtm.24529.1
SDK_DISTNAME=		dotnet-sdk-${SDKVERSION}-${SDK_RID}
SDK_RID=		freebsd.${_OSVERSION_MAJOR}-${DOTNET_ARCH}
DOTNET_ARCH=		${ARCH:S|amd64|x64|:C|aarch64|arm64|}

PLIST_SUB=	DOTNET_ARCH=${DOTNET_ARCH} FULL_DOTNETVERSION=${PORTVERSION} \
		DOTNETVERSION=${DOTNETVERSION} \
		SDKVERSION=${SDKVERSION} SDKVERSIONSUFFIX=${SDKVERSIONSUFFIX} \
		SDK_RID=${SDK_RID}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
PLIST_SUB+=	VXSORT=
.else
PLIST_SUB+=	VXSORT="@comment "
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

post-patch:
	${REINPLACE_CMD} -e 's|linux-${DOTNET_ARCH}|freebsd-${DOTNET_ARCH}|g' \
		${WRKDIR}/bootstrap_sdk/sdk/${BOOTSTRAP_SDKVERSION}${BOOTSTRAP_SDKVERSIONBINSUFFIX}/Microsoft.NETCoreSdk.BundledVersions.props

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${DOTNET_ENV} ./build.sh \
		--release-manifest release.json \
		--clean-while-building \
		--with-sdk ${WRKDIR}/bootstrap_sdk \
		--with-packages ${WRKDIR}/packages \
		--source-build \
		-- \
		-maxcpucount:${MAKE_JOBS_NUMBER}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/dotnet
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}/artifacts/assets/Release/${SDK_DISTNAME}${EXTRACT_SUFX} -C ${STAGEDIR}${PREFIX}/dotnet ${EXTRACT_AFTER_ARGS}
	${FIND} ${WRKSRC}/artifacts/packages/Release -name "*freebsd*.nupkg" -exec \
		${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/dotnet/library-packs/ \;

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/dotnet/sdk/${SDKVERSION}/AppHostTemplate/apphost
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/dotnet/packs/Microsoft.NETCore.App.Host.${SDK_RID}/${DISTVERSION}/runtimes/${SDK_RID}/native/apphost
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/dotnet/packs/Microsoft.NETCore.App.Host.${SDK_RID}/${DISTVERSION}/runtimes/${SDK_RID}/native/singlefilehost
	${FIND} ${STAGEDIR}${PREFIX}/dotnet -name "*.so" -exec ${STRIP_CMD} -s "{}" ";"

	${RLN} ${STAGEDIR}${PREFIX}/dotnet/dotnet ${STAGEDIR}${PREFIX}/bin/dotnet

.include <bsd.port.post.mk>
