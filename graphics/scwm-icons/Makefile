PORTNAME=	scwm-icons
PORTVERSION=	0.99.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/scwm/scwm/0.99.6.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Icon collection for the scwm window manager

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/scwm/pixmaps
.for dir in icons mini-icons startup
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.xpm \
		${STAGEDIR}${PREFIX}/share/scwm/pixmaps
.endfor

.include <bsd.port.mk>
