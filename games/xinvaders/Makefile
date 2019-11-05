# Created by: swallace
# $FreeBSD$

PORTNAME=	xinvaders
PORTVERSION=	2.1.1
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade/invaders

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shoot-em-up them nasty little bugs

NO_CDROM=	don't sell for profit

USES=		gettext xorg
USE_XORG=	x11 xmu xaw xt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-scorefile=/var/games/xinvaders.scores

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

DESKTOP_ENTRIES="XInvaders" "Space Invaders game for X" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" "${PORTNAME}" "" ""

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(prefix)/games|$$(prefix)/bin| ; \
		 /install-exec-am:/s|install-exec-local|| ; \
		 /install-data-am:/s|install-data-local||' ${WRKSRC}/Makefile.in

post-install:
	(cd ${FILESDIR} && ${INSTALL_DATA} Vaders.ad \
		${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Vaders)
	(cd ${WRKSRC} && ${INSTALL_DATA} icon.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.xpm)
	${MKDIR} ${STAGEDIR}/var/games
	${ECHO_CMD} "0" > ${STAGEDIR}/var/games/xinvaders.scores.sample

.include <bsd.port.mk>
