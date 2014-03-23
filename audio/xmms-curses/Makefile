# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmms-curses
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	A ncurses program for (remote) controlling multimedia/xmms

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs

USES=		gettext iconv
NO_STAGE=	yes
USE_GNOME=	gtk12
USE_XORG=	x11 xau xcb xdmcp xext xi

MAN1=	${PORTNAME}.1

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS} -lncurses `xmms-config --cflags --libs` -o xmms-curses *.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmms-curses ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
.if !exists(${PREFIX}/etc/${PORTNAME}.conf)
	${INSTALL_DATA}	${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc
.endif

.include <bsd.port.mk>
