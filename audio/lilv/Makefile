# Created by: Michael Beer <beerml@sigma6audio.de>
# $FreeBSD$

PORTNAME=	lilv
PORTVERSION=	0.24.0
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	beerml@sigma6audio.de
COMMENT=	Lilv makes the use of LV2 plugins as simple as possible

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	libserd-0.so:devel/serd libsord-0.so:devel/sord libsratom-0.so:audio/sratom libsndfile.so:audio/libsndfile

USES=		pkgconfig python:build tar:bzip2 waf

USE_LDCONFIG=	yes

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	@${MV} ${STAGEDIR}${PREFIX}/share/man/man1 ${STAGEDIR}${PREFIX}/man/
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/man
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblilv-0.so.0.24.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lilv-bench
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lv2apply
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lv2bench
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lv2info
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lv2ls

.include <bsd.port.mk>
