# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	mongo-c-driver
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMESUFFIX=	-devel

MAINTAINER=	waitman@waitman.net
COMMENT=	C Driver for MongoDB

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb

USES=		gmake

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
