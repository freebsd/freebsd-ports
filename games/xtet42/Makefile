# Created by: gmarco@giovannelli.it
# $FreeBSD$

PORTNAME=	xtet42
PORTVERSION=	2.21
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://utenti.gufi.org/~gmarco/files/distfiles/

MAINTAINER=	gmarco@gufi.org
COMMENT=	One or two player T*tris game

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-setgid=games
USE_XORG=	x11

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's,^hiscoredir.*,hiscoredir=${DATADIR},' \
		${WRKSRC}/Makefile.in

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@${CHMOD} 775 ${STAGEDIR}${DATADIR}
	@${STRIP_CMD} ${WRKSRC}/xtet42
	${INSTALL} -c -m 755 ${WRKSRC}/xtet42 ${STAGEDIR}${PREFIX}/bin
	${INSTALL} -c -m 664 ${WRKSRC}/xtet42.hiscore ${STAGEDIR}${DATADIR}/.xtet42.hiscore
	${INSTALL} -c -m 664 ${WRKSRC}/xtet42.hiscore.single ${STAGEDIR}${DATADIR}/.xtet42.hiscore.single
	${INSTALL} -c -m 664 /dev/null ${STAGEDIR}${DATADIR}/.xtet42.unlock
	${INSTALL} -c -m 664 /dev/null ${STAGEDIR}${DATADIR}/.xtet42.log
	${INSTALL_MAN} ${WRKSRC}/xtet42.6 ${STAGEDIR}${MANPREFIX}/man/man6

.include <bsd.port.mk>
