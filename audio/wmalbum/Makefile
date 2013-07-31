# Created by: lx@redundancy.redundancy.org
# $FreeBSD$

PORTNAME=	wmalbum
PORTVERSION=	0.1.5
PORTREVISION=	7
CATEGORIES=	audio windowmaker
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A dockapp to display album covers for xmms

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		gdk_pixbuf_xlib.2:${PORTSDIR}/graphics/gdk-pixbuf

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

MAN1=		wmalbum.1
PLIST_FILES=	bin/wmalbum

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmalbum/wmalbum ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmalbum.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
