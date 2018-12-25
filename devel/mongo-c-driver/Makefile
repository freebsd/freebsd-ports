# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	mongo-c-driver
PORTVERSION=	1.8.1
CATEGORIES=	devel

MAINTAINER=	ports@bsdserwis.com
COMMENT=	C Driver for MongoDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2 \
		libbson-1.0.so:devel/libbson

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb

USES=		cmake pkgconfig
#USES=		cmake:noninja pkgconfig
USE_LDCONFIG=	yes
LDFLAGS+=	-pthread

.include <bsd.port.mk>
