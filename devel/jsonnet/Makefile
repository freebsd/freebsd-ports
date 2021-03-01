# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jsonnet
PORTVERSION=	0.15.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	JSON data templating language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib gmake
USE_CXXSTD=	c++11

USE_GITHUB=	yes
GH_ACCOUNT=	google

USE_LDCONFIG=	yes

ALL_TARGET=	jsonnet jsonnetfmt libjsonnet.so
CXXFLAGS+=	-fPIC -Iinclude -Ithird_party/md5
PLIST_FILES=	bin/jsonnet bin/jsonnetfmt include/libjsonnet.h lib/libjsonnet.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/jsonnetfmt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/lib${PORTNAME}.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
