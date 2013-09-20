# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	libmimedir
PORTVERSION=	0.5.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for parsing RFC2425 MIME Directory Profile information

USES=		bison
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

NO_STAGE=	yes
regression-test:
	cd ${WRKSRC} && ./test

.include <bsd.port.mk>
