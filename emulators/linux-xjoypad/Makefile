# New ports collection makefile for:	linux-xjoypad
# Date created:			17 Apr 2006
# Whom:				Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	xjoypad
PORTVERSION=	1
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://members.chello.at/erich.kitzmueller/ammoq/down/
PKGNAMEPREFIX=	linux-
DISTNAME=	xjoypad

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Joy-Device to X mapping (lets you play Linux games with a joypad)

RUN_DEPENDS=	/boot/modules/linux_js.ko:${PORTSDIR}/devel/linux-js

USE_XORG=	x11 xau xdmcp
WRKSRC=		${WRKDIR}/xjoypad/
USE_ZIP=	yes

FILES=		xjoypad.c sendevent.c
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lcompat -lX11 -lXau -lXdmcp

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o xjoypad ${FILES} ${LDFLAGS} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjoypad ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
