# New ports collection makefile for:   xtet42
# Date created:        14 Feb 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	xtet42
PORTVERSION=	2.21
CATEGORIES=	games
MASTER_SITES=	http://www.gufi.org/~gmarco/files/distfiles/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	A one or two player t*tris game

USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-setgid=games

MAN6=	xtet42.6

do-install:
	${MKDIR} ${PREFIX}/lib/X11/xtet42
	@${CHOWN} root:games ${PREFIX}/lib/X11/xtet42
	@${CHMOD} 775 ${PREFIX}/lib/X11/xtet42
	${INSTALL} -c -m 2755 -g games ${WRKSRC}/xtet42 ${PREFIX}/bin
	${INSTALL} -c -m 664  -g games ${WRKSRC}/xtet42.hiscore ${PREFIX}/lib/X11/xtet42/.xtet42.hiscore
	${INSTALL} -c -m 664  -g games ${WRKSRC}/xtet42.hiscore.single ${PREFIX}/lib/X11/xtet42/.xtet42.hiscore.single
	${INSTALL} -c -m 664  -g games /dev/null ${PREFIX}/lib/X11/xtet42/.xtet42.unlock
	${INSTALL} -c -m 664  -g games /dev/null ${PREFIX}/lib/X11/xtet42/.xtet42.log
	${INSTALL_MAN} ${WRKSRC}/xtet42.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
