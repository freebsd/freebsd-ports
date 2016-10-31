# $FreeBSD$

PORTNAME=	libfastcommon
PORTVERSION=	1.0.30
CATEGORIES=	devel

MAINTAINER=	daniel@blodan.se
COMMENT=	C common functions library used mainly by FastDFS and FastDHT

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	happyfish100
GH_TAGNAME=	b80de986b2a269cd15d56e4978c6df844a9c2e59

USE_LDCONFIG=	yes

MAKE_ENV +=	DESTDIR=${STAGEDIR}

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh

do-install:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh install

.include <bsd.port.mk>
