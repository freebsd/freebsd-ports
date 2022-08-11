PORTNAME=	eterm-bg
PORTVERSION=	0.9.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.eterm.org/download/
DISTNAME=	Eterm-bg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image files for background of Eterm

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Eterm/pix/scale
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Eterm/pix/tile
	${INSTALL_DATA} ${WRKSRC}/bg/scale/* \
		${STAGEDIR}${PREFIX}/share/Eterm/pix/scale
	${INSTALL_DATA} ${WRKSRC}/bg/tile/* \
		${STAGEDIR}${PREFIX}/share/Eterm/pix/tile

.include <bsd.port.mk>
