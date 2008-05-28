# New ports collection makefile for:	linux-xjoypad
# Date created:			17 Apr 2006
# Whom:				Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	xjoypad
PORTVERSION=	1
PORTREVISION=	1
CATEGORIES=	emulators linux
MASTER_SITES=	http://members.chello.at/erich.kitzmueller/ammoq/down/
PKGNAMEPREFIX=	linux-
DISTNAME=	xjoypad

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Joy-Device to X mapping (lets you play Linux games with a joypad)

BUILD_DEPENDS=	${X11BASE}/lib/libX11.a:${PORTSDIR}/x11/libX11
RUN_DEPENDS=	/boot/modules/linux_js.ko:${PORTSDIR}/devel/linux-js

USE_XORG=	x11
WRKSRC=		${WRKDIR}/xjoypad/
USE_LINUX=	yes
USE_X_PREFIX=	yes
USE_ZIP=	yes

FILES=		xjoypad.c sendevent.c
CFLAGS+=	-I ${PREFIX}/include
LIB_X11=	${PREFIX}/lib/libX11.a
LIB_XAU=	${PREFIX}/lib/libXau.a
LIB_XDMCP=	${PREFIX}/lib/libXdmcp.a

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o xjoypad ${FILES} -lcompat -lm ${LIB_X11} ${LIB_XAU} ${LIB_XDMCP})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjoypad ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
