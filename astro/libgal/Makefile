PORTNAME=	libgal
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	astro hamradio
MASTER_SITES=	http://homepage.mac.com/pclwillmott/GAL/ \
		LOCAL/db

MAINTAINER=	db@FreeBSD.org
COMMENT=	General Astrodynamics Library
WWW=		http://homepage.mac.com/pclwillmott/GAL/

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX} --enable-shared=yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
