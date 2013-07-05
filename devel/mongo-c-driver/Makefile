# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	mongo-c-driver
PORTVERSION=	0.7.1
CATEGORIES=	devel
MASTER_SITES=	GH
PKGNAMESUFFIX=	-devel
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	waitman@waitman.net
COMMENT=	C Driver for MongoDB

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb
GH_PROJECT=	mongo-c-driver
GH_TAGNAME=	v0.7.1
GH_COMMIT=	g98826a

WRKSRC=		${WRKDIR}/mongodb-mongo-c-driver-17ff925
USE_GMAKE=	yes

USE_LDCONFIG=	yes

PLIST_FILES=	include/mongo.h \
		include/bson.h \
		lib/libmongoc.a \
		lib/libmongoc.so.0.7 \
		lib/libmongoc.so.0.7.1 \
		lib/libmongoc.so \
		lib/libbson.a \
		lib/libbson.so.0.7.1 \
		lib/libbson.so.0.7 \
		lib/libbson.so

.include <bsd.port.mk>
