# Created by: Jacques Vidrine <nectar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stella
PORTVERSION=	5.1.3
PORTREVISION=	2
CATEGORIES=	emulators

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Multi-platform Atari 2600 VCS emulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/License.txt

BROKEN_aarch64=		fails to compile: Checking for compiler version... 5.0.0, bad; Please ensure you are using GCC 4.7 / Clang 3.4 or above
BROKEN_armv6=		fails to compile: Checking for compiler version... 5.0.0, bad; Please ensure you are using GCC 4.7 / Clang 3.4 or above
BROKEN_armv7=		fails to compile: Checking for compiler version... 5.0.0, bad; Please ensure you are using GCC 4.7 / Clang 3.4 or above

LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	stella-emu

CONFLICTS_INSTALL=	rubygem-stella

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		compiler:c++11-lib gmake tar:xz
USE_SDL=	sdl2
HAS_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stella ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/emucore/stella.pro ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
