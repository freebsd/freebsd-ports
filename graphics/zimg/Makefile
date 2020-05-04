# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	zimg
PORTVERSION=	5.0.0
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image-generator that uses ASCII input files to create PNGs/EDFs

LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png

CONFLICTS_INSTALL=	sekrit-twc-zimg-* # include/zimg.h

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dynaload-cc="${CC}" \
		--with-dynaload-cflags="${CFLAGS} -shared" \
		--with-gd-includes="${LOCALBASE}/include" \
		--with-gd-lib="${LOCALBASE}/lib"

PLIST_FILES=	include/zimg.h bin/zimg \
		man/man1/zimg.1.gz

CFLAGS+=	-DHAVE_GD_FREETYPE

.include <bsd.port.mk>
