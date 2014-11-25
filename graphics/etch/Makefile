# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	etch
PORTVERSION=	20121003
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://files.roorback.net/e17/extra/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Etch is an abstract time based animation library

LICENSE=	LGPL21

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USE_EFL=	eina enesim libtool_hack
USES=		pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-static

BROKEN=		Don't build with EFL 1.11
DEPRECATED=	Unused by EFL 1.11
EXPIRATION_DATE=2014-12-31

.include <bsd.port.mk>
