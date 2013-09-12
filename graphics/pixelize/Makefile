# Created by: ijliao
# $FreeBSD$

PORTNAME=	pixelize
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://lashwhip.com/pub/ \
		http://www.c-s.li/ports/ \
		http://lashwhip.com/pixelize/
MASTER_SITE_SUBDIR=	apps/graphics/misc

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Use many scaled down images to try to duplicate another image

LICENSE=	GPLv2

USES=		pkgconfig
USE_GNOME=	gtk20 imlib
PLIST_FILES=	bin/make_db bin/pixelize

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|" -e "s|CFLAGS = -g|CFLAGS+= |" \
		-e "s|gtk-config|${GTK_CONFIG}|g" \
		-e "s|imlib-config|${IMLIB_CONFIG}|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make_db ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pixelize ${PREFIX}/bin

.include <bsd.port.mk>
