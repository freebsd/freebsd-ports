# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	affenspiel
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/affenspiel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Little puzzle game with monkey for X Window System

LICENSE=	unknown
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_NAME=	just Copyright

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11 xt

MAKE_ARGS=	CC="${CC}" LIBS="-L${LOCALBASE}/lib -lX11" \
		DEBUG="${CFLAGS} -I${LOCALBASE}/include" \
		FILE_CONFIG=-DSAVED_GAME_NAME='\"affenspiel.saved\"'

PORTDOCS=	COPYRIGHT README
PLIST_FILES=	bin/affenspiel

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/affenspiel ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
