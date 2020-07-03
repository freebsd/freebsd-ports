# $FreeBSD$

PORTNAME=	libfastcommon
PORTVERSION=	1.0.43
CATEGORIES=	devel

MAINTAINER=	daniel@blodan.se
COMMENT=	C common functions library used mainly by FastDFS and FastDHT

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	happyfish100
GH_TAGNAME=	V1.0.43

USE_LDCONFIG=	yes

MAKE_ENV=	DESTDIR=${STAGEDIR}

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh

do-install:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh install

.include <bsd.port.mk>
