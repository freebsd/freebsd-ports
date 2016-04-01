# Created by: Jacques Vidrine <nectar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stella
PORTVERSION=	4.6.1
CATEGORIES=	emulators
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Multi-platform Atari 2600 VCS emulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libpng.so:graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_SDL=	sdl2
USES=		compiler:c++11-lib gmake
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
