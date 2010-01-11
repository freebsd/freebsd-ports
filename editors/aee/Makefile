# New ports collection makefile for:	aee
# Date created:		19 Aug 1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	aee
PORTVERSION=	2.2.15b
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://mahon.cwx.net/sources/

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	An easy editor with both curses and X11 interfaces

OPTIONS=	XAE "Build X11 version 'xae'" off

.include <bsd.port.pre.mk>

.if !defined(WITH_XAE)
ALL_TARGET=	main
PLIST_SUB=	XAE="@comment "
.else
USE_XORG=	x11
ALL_TARGET=	both
PLIST_SUB=	XAE=""
.endif

PLIST_FILES=	bin/aee bin/rae lib/help.ae %%XAE%%bin/xae %%XAE%%bin/rxae

MAN1=		aee.1

post-patch:
	@${REINPLACE_CMD} -e 's|cc|${CC}|g' ${WRKSRC}/create.mk.aee
	@${REINPLACE_CMD} -e 's|cc|${CC}|g' ${WRKSRC}/create.mk.xae
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/create.mk.xae

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aee ${PREFIX}/bin
	${LN} ${PREFIX}/bin/aee ${PREFIX}/bin/rae
	${INSTALL_MAN} ${WRKSRC}/aee.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/help.ae ${PREFIX}/lib
.if defined(WITH_XAE)
	${INSTALL_PROGRAM} ${WRKSRC}/xae ${PREFIX}/bin
	${LN} ${PREFIX}/bin/xae ${PREFIX}/bin/rxae
.endif

.include <bsd.port.post.mk>
