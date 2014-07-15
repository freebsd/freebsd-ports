# Created by: saper@system.pl
# $FreeBSD$

PORTNAME=	gif2png
PORTVERSION=	2.5.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	saper@saper.info
COMMENT=	Converts GIF images to a PNG format

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USE_PYTHON_RUN=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} bin/web2png \
		man/man1/gif2png.1.gz \
		man/man1/web2png.1.gz

CPPFLAGS+=	`libpng-config --I_opts`
LDFLAGS+=	`libpng-config --L_opts`

.include <bsd.port.mk>
