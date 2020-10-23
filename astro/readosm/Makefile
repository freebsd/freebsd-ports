# Created by: Loïc BARTOLETTI <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	readosm
PORTVERSION=	1.1.0
CATEGORIES=	astro geography devel
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/
DISTNAME=	${PORTNAME}-${PORTVERSION}a

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Extract valid data from within an Open Street Map input file

LICENSE=	MPL11 LGPL21 GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
USE_LDCONFIG=	yes

.include <bsd.port.mk>
