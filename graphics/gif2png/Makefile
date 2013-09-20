# Created by: saper@system.pl
# $FreeBSD$

PORTNAME=	gif2png
PORTVERSION=	2.5.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	saper@saper.info
COMMENT=	Converts GIF images to a PNG format

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_PYTHON_RUN=	yes
GNU_CONFIGURE=	yes

MAN1=		${PORTNAME}.1 web2png.1
PLIST_FILES=	bin/${PORTNAME} bin/web2png

CPPFLAGS+=	`libpng-config --I_opts`
LDFLAGS+=	`libpng-config --L_opts`

NO_STAGE=	yes
.include <bsd.port.mk>
