# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jsonnet
PORTVERSION=	0.9.3
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	JSON data templating language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		compiler:c++11-lib gmake
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

ALL_TARGET=	jsonnet libjsonnet.so
CXXFLAGS+=	-fPIC -Iinclude -Ithird_party/md5
PLIST_FILES=	bin/jsonnet include/libjsonnet.h lib/libjsonnet.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/lib${PORTNAME}.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
