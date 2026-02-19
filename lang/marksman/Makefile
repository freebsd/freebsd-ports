PORTNAME=	marksman
DISTVERSION=	2024-12-18
CATEGORIES=	lang textproc

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Language server for Markdown
WWW=		https://github.com/artempyanykh/marksman

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dotnet>=9.0.10:lang/dotnet
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	dotnet:lang/dotnet-host \
		${LOCALBASE}/lib/libicuuc.so:devel/icu

USES=		gssapi:mit ssl

USE_GITHUB=	yes
GH_ACCOUNT=	artempyanykh

PLIST_FILES=	bin/${PORTNAME}

DOTNET_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/}

DOTNET_CMD=	${SETENV} HOME=${WRKDIR} ${LOCALBASE}/bin/dotnet

.include "Makefile.nuget"
.include "../../shells/powershell/nuget.mk"

post-patch:
	${REINPLACE_CMD} -e 's|net8\.0|net9.0|g' \
		${WRKSRC}/Tests/Tests.fsproj \
		${WRKSRC}/Benchmarks/Benchmarks.fsproj \
		${WRKSRC}/LanguageServerProtocol/LanguageServerProtocol.fsproj \
		${WRKSRC}/MarkdigPatches/MarkdigPatches.csproj
	@sdk_ver=$$(${LOCALBASE}/bin/dotnet --version 2>/dev/null || echo "9.0.111") && \
		${REINPLACE_CMD} -e "s|8\.0\.100|$$sdk_ver|" ${WRKSRC}/global.json

do-build:
	cd ${WRKSRC}/Marksman && \
	${DOTNET_CMD} nuget add source ${DISTDIR}/nuget || true && \
	${DOTNET_CMD} nuget disable source nuget.org || true && \
	${DOTNET_CMD} restore Marksman.fsproj -r linux-${DOTNET_ARCH} -s ${DISTDIR}/nuget --packages ${WRKDIR}/packages && \
	${DOTNET_CMD} publish Marksman.fsproj -c Release \
		-r linux-${DOTNET_ARCH} --sc --no-restore -p:PublishReadyToRun=false \
		-p:PublishSingleFile=true -p:PublishTrimmed=true \
		-p:TrimMode=partial -p:DebugType=embedded \
		-p:EnableCompressionInSingleFile=true -o bin/publish

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Marksman/bin/publish/marksman ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
