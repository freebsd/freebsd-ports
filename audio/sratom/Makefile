# Created by: Michael Beer <beerml@sigma6audio.de>
# $FreeBSD$

PORTNAME=	sratom
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	beerml@sigma6audio.de
COMMENT=	Sratom is a library for serialising LV2 atoms to/from RDF

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	libserd-0.so:devel/serd libsord-0.so:devel/sord
RUN_DEPENDS=	lv2>=1.14.0:audio/lv2

USES=		pkgconfig python:build tar:bzip2 waf
USE_CSTD=	c99
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsratom-0.so.${PORTVERSION}

.include <bsd.port.mk>
