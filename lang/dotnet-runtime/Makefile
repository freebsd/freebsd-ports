PORTNAME=	dotnet-host
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.0
PORTREVISION=	1
CATEGORIES=	lang devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Host runtime binary for the .NET platform
WWW=		https://dot.net

LICENSE=	MIT

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	eng/native/functions.cmake:7: 'i386' is an unsupported architecture.

BUILD_DEPENDS=	bash:shells/bash

USES=		cmake:indirect llvm:noexport ssl

USE_GITHUB=	yes
GH_ACCOUNT=	dotnet
GH_PROJECT=	runtime

PLIST_FILES=	bin/dotnet \
		dotnet/LICENSE.TXT \
		dotnet/THIRD-PARTY-NOTICES.TXT \
		dotnet/dotnet

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
	${MKDIR} ${STAGEDIR}${PREFIX}/dotnet
	${INSTALL_PROGRAM} ${WRKSRC}/artifacts/bin/freebsd-${DOTNET_ARCH}.${BUILD_TYPE}/corehost/dotnet \
		${STAGEDIR}${PREFIX}/dotnet/
	${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT ${WRKSRC}/THIRD-PARTY-NOTICES.TXT \
		${STAGEDIR}${PREFIX}/dotnet/
	${RLN} ${STAGEDIR}${PREFIX}/dotnet/dotnet ${STAGEDIR}${PREFIX}/bin/dotnet

.include <bsd.port.mk>
