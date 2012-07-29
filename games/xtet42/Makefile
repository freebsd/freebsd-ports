# New ports collection makefile for:   xtet42
# Date created:        14 Feb 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	xtet42
PORTVERSION=	2.21
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://utenti.gufi.org/~gmarco/files/distfiles/

MAINTAINER=	gmarco@gufi.org
COMMENT=	One or two player T*tris game

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-setgid=games
USE_XORG=	x11

MAN6=	xtet42.6

post-patch:
	@${REINPLACE_CMD} -e 's,^hiscoredir.*,hiscoredir=${DATADIR},' \
		${WRKSRC}/Makefile.in

do-install:
	${MKDIR} ${DATADIR}
	@${CHOWN} root:games ${DATADIR}
	@${CHMOD} 775 ${DATADIR}
	${INSTALL} -c -m 2755 -g games ${WRKSRC}/xtet42 ${PREFIX}/bin
	${INSTALL} -c -m 664  -g games ${WRKSRC}/xtet42.hiscore ${DATADIR}/.xtet42.hiscore
	${INSTALL} -c -m 664  -g games ${WRKSRC}/xtet42.hiscore.single ${DATADIR}/.xtet42.hiscore.single
	${INSTALL} -c -m 664  -g games /dev/null ${DATADIR}/.xtet42.unlock
	${INSTALL} -c -m 664  -g games /dev/null ${DATADIR}/.xtet42.log
	${INSTALL_MAN} ${WRKSRC}/xtet42.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
