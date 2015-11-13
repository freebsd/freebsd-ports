# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	mongo-c-driver
PORTVERSION=	1.1.9
CATEGORIES=	devel

MAINTAINER=	waitman@waitman.net
COMMENT=	C Driver for MongoDB

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/lib/libbson-1.0.so:${PORTSDIR}/devel/libbson
LIB_DEPENDS+=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb

USES=		autoreconf gmake libtool pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-pthread

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig" V=1

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmongoc-priv.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmongoc-1.0.so.0.0.0

.include <bsd.port.mk>
