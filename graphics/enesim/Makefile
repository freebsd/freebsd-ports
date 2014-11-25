# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	enesim
PORTVERSION=	20121003
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://files.roorback.net/e17/extra/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Rendering library focused on flexibility and extensibility

LICENSE=	LGPL21

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USE_EFL=	eina libtool_hack
USES=		pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-static

BROKEN=		Don't build with EFL 1.11
DEPRECATED=	Unused by EFL 1.11
EXPIRATION_DATE=2014-12-31

.include <bsd.port.mk>
