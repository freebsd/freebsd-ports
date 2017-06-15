# Created by: lx@redundancy.redundancy.org
# $FreeBSD$

PORTNAME=	wmalbum
PORTVERSION=	0.1.5
PORTREVISION=	11
CATEGORIES=	audio windowmaker
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp to display album covers for XMMS

LIB_DEPENDS=	libxmms.so:multimedia/xmms \
		libgdk_pixbuf_xlib.so:graphics/gdk-pixbuf

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

PLIST_FILES=	bin/wmalbum \
		man/man1/wmalbum.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmalbum/wmalbum ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmalbum.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
