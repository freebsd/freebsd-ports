# Created by: trevor
# $FreeBSD$

PORTNAME=	rmap
PORTVERSION=	1.2
PORTREVISION=	12
CATEGORIES=	astro geography
MASTER_SITES=	http://reza.net/rmap/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates images of the Earth centered at a particular location

LICENCE=	GPLv2 # (or later)

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

USES=		gmake
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/rmap man/man1/rmap.1.gz %%DATADIR%%/earth.rez \
		%%DATADIR%%/rmap.colors
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
