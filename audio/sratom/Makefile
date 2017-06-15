# Created by: Michael Beer <beerml@sigma6audio.de>
# $FreeBSD$

PORTNAME=	sratom
PORTVERSION=	0.6.0
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	beerml@sigma6audio.de
COMMENT=	Sratom is a library for serialising LV2 atoms to/from RDF

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libserd-0.so:devel/serd libsord-0.so:devel/sord
BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2

USES=		pkgconfig python:build tar:bzip2 waf

USE_LDCONFIG=	yes

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsratom-0.so.0.6.0

.include <bsd.port.mk>
