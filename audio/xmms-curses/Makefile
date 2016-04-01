# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmms-curses
PORTVERSION=	0.2.2
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Ncurses program for (remote) controlling multimedia/xmms

BUILD_DEPENDS=	xmms:multimedia/xmms
RUN_DEPENDS=	xmms:multimedia/xmms
LIB_DEPENDS=	libpthread-stubs.so:devel/libpthread-stubs

USES=		gettext iconv
USE_GNOME=	gtk12
USE_XORG=	x11 xau xcb xdmcp xext xi

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${CC} ${CFLAGS} -lpthread -lncurses \
		`xmms-config --cflags --libs` -o xmms-curses *.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmms-curses ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmms-curses.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
