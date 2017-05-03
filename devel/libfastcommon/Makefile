# $FreeBSD$

PORTNAME=	libfastcommon
PORTVERSION=	1.0.36
CATEGORIES=	devel

MAINTAINER=	daniel@blodan.se
COMMENT=	C common functions library used mainly by FastDFS and FastDHT

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	happyfish100
GH_TAGNAME=	aa4f5b29c76b3a87b54ca177808afc7f103f0b2b

USE_LDCONFIG=	yes

MAKE_ENV +=	DESTDIR=${STAGEDIR}

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh

do-install:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh install

.include <bsd.port.mk>
