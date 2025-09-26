PORTNAME=	dotnet-host
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.9
CATEGORIES=	lang devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Host runtime binary for the .NET platform
WWW=		https://dot.net

LICENSE=	MIT

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	eng/native/functions.cmake:7: 'i386' is an unsupported architecture.

BUILD_DEPENDS=	bash:shells/bash

USES=		cmake:indirect llvm:noexport

USE_GITHUB=	yes
GH_ACCOUNT=	dotnet
GH_PROJECT=	runtime

DATADIR=	${PREFIX}/share/dotnet

PLIST_FILES=	bin/dotnet \
		share/dotnet/LICENSE.TXT \
		share/dotnet/THIRD-PARTY-NOTICES.TXT \
		share/dotnet/dotnet

DOTNET_ARCH=	${ARCH:S|amd64|x64|:C|aarch64|arm64|}

.if defined(WITH_DEBUG)
BUILD_TYPE=	Debug
.else
BUILD_TYPE=	Release
.endif

do-build:
	cd ${WRKSRC} && ${SETENVI} ${MAKE_ENV} src/native/corehost/build.sh -ci -c ${BUILD_TYPE}

post-build:
	${ELFCTL} -e +noaslr ${WRKSRC}/artifacts/bin/freebsd-${DOTNET_ARCH}.${BUILD_TYPE}/corehost/dotnet

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/artifacts/bin/freebsd-${DOTNET_ARCH}.${BUILD_TYPE}/corehost/dotnet \
		${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT ${WRKSRC}/THIRD-PARTY-NOTICES.TXT \
		${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/dotnet ${STAGEDIR}${PREFIX}/bin/dotnet

.include <bsd.port.mk>
