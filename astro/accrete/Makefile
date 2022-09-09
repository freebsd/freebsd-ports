PORTNAME=	accrete
PORTVERSION=	1.0
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Physical simulation of solar system planet formation
WWW=		https://sourceforge.net/projects/accrete/

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX=${STAGEDIR}${PREFIX} \
		CDEBUG="" COPT=""
PLIST_FILES=	bin/accrete

.include <bsd.port.mk>
