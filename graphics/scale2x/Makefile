# Ports collection makefile for:	scale2x
# Date created:			2006/12/01
# Whom:				chinsan
#
# $FreeBSD$
#

PORTNAME=	scale2x
PORTVERSION=	2.4
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time graphics effect able to increase the size of small bitmaps

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		scalex.1 scalerx.1
PLIST_FILES=	bin/scalex bin/scalerx

CPPFLAGS=	`libpng12-config --I_opts`
LDFLAGS=	`libpng12-config --L_opts`

.include <bsd.port.mk>
