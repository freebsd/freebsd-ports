# Created by: ijliao
# $FreeBSD$

PORTNAME=	pixelize
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://lashwhip.com/pub/ \
		http://www.c-s.li/ports/ \
		http://lashwhip.com/pixelize/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Use many scaled down images to try to duplicate another image

LICENSE=	GPLv2

USES=		gnome pkgconfig
USE_GNOME=	gtk20
PLIST_FILES=	bin/make_db bin/pixelize

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|" -e "s|CFLAGS = -g|CFLAGS+= |" \
		-e "s|gtk-config|${GTK_CONFIG}|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/make_db ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pixelize ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
