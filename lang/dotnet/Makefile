PORTNAME=	dotnet
DISTVERSIONPREFIX=	v
DISTVERSION=	${DOTNETVERSION}.0
CATEGORIES=	lang devel
MASTER_SITES=	https://github.com/dotnet/dotnet/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/release.json?dummy=/:dotnetmanifest \
		LOCAL/arrowd/dotnet/:bootstrap
DISTFILES=	release.json-${PORTVERSION}:dotnetmanifest \
		${BOOTSTRAP_SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}:bootstrap \
		${BOOTSTRAP_SDK_DISTNAME}${EXTRACT_SUFX}:bootstrap
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Open-source developer platform and a cross-platform runtime for cloud, mobile, desktop, and IoT apps
WWW=		https://dot.net

LICENSE=	MIT

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake-core \
		git:devel/git \
		ggrep:textproc/gnugrep \
		terminfo-db>0:misc/terminfo-db
LIB_DEPENDS=	libicuuc.so:devel/icu \
		libinotify.so:devel/libinotify \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	terminfo-db>0:misc/terminfo-db

USES=		autoreconf:build gssapi:mit llvm:noexport nodejs pkgconfig \
		python:build,3.9+ shebangfix ssl

USE_GITHUB=	yes

SHEBANG_FILES=	src/diagnostics/src/Tools/dotnet-trace/*.sh \
		src/source-build-externals/src/azure-activedirectory-identitymodel-extensions-for-dotnet/updateAssemblyInfo.sh

BINARY_ALIAS=   grep=${LOCALBASE}/bin/ggrep
DOTNET_ENV=	PYTHON=${PYTHON_CMD}

DIST_SUBDIR=	dotnet

BOOTSTRAP_DOTNETVERSION=			8.0
BOOTSTRAP_SDKVERSION=				${BOOTSTRAP_DOTNETVERSION}.100
BOOTSTRAP_SDKVERSIONSUFFIX=			-rtm.23551.1
BOOTSTRAP_SOURCEBUILT_ARTIFACTS_DISTNAME=	Private.SourceBuilt.Artifacts.${BOOTSTRAP_SDKVERSION}${BOOTSTRAP_SDKVERSIONSUFFIX}.freebsd.13-x64
BOOTSTRAP_SDK_DISTNAME=				dotnet-sdk-${BOOTSTRAP_SDKVERSION}-freebsd-x64

DOTNETVERSION=			8.0
SDKVERSION=			${DOTNETVERSION}.100
SDKVERSIONSUFFIX=		-rtm.23551.1
SOURCEBUILT_ARTIFACTS_DISTNAME=	Private.SourceBuilt.Artifacts.${SDKVERSION}${SDKVERSIONSUFFIX}.freebsd.13-x64
SDK_DISTNAME=			dotnet-sdk-${SDKVERSION}-freebsd-x64

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1400000
LIB_DEPENDS+=	libcrypto.so.111:misc/compat13x
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
	${MKDIR} ${STAGEDIR}${PREFIX}/dotnet
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}/artifacts/x64/Release/${SDK_DISTNAME}${EXTRACT_SUFX} -C ${STAGEDIR}${PREFIX}/dotnet ${EXTRACT_AFTER_ARGS}
	${ELFCTL} -e +noaslr ${STAGEDIR}${PREFIX}/dotnet/dotnet

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/dotnet/dotnet
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/dotnet/sdk/${SDKVERSION}/AppHostTemplate/apphost
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/dotnet/packs/Microsoft.NETCore.App.Host.freebsd-x64/${DISTVERSION}/runtimes/freebsd-x64/native/apphost
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/dotnet/packs/Microsoft.NETCore.App.Host.freebsd-x64/${DISTVERSION}/runtimes/freebsd-x64/native/singlefilehost
	${FIND} ${STAGEDIR}${PREFIX}/dotnet -name "*.so" -exec ${STRIP_CMD} -s "{}" ";"

	${RLN} ${STAGEDIR}${PREFIX}/dotnet/dotnet ${STAGEDIR}${PREFIX}/bin/dotnet

bootstrap-makesum:
	@cd ${WRKSRC}/artifacts/x64/Release && sha256 ${SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}
	@${ECHO_CMD} -n "SIZE (${SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}) = "
	@${STAT} -f %z ${WRKSRC}/artifacts/x64/Release/${SOURCEBUILT_ARTIFACTS_DISTNAME}${EXTRACT_SUFX}

	@cd ${WRKSRC}/artifacts/x64/Release && sha256 ${SDK_DISTNAME}${EXTRACT_SUFX}
	@${ECHO_CMD} -n "SIZE (${SDK_DISTNAME}${EXTRACT_SUFX}) = "
	@${STAT} -f %z ${WRKSRC}/artifacts/x64/Release/${SDK_DISTNAME}${EXTRACT_SUFX}

	@${ECHO_CMD}

.include <bsd.port.post.mk>
