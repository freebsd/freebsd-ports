PORTNAME=	py3c
PORTVERSION=	1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Py3c helps you port C extensions to Python 3
WWW=		https://github.com/encukou/py3c

LICENSE=	MIT

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	encukou

NO_BUILD=	yes

do-install:
	${SETENVI} ${WRK_ENV} ${MAKE_CMD}         \
	 prefix=${PREFIX}                         \
	 pkgconfigdir=${PREFIX}/libdata/pkgconfig \
	 DESTDIR=${STAGEDIR}                      \
	 -C ${WRKSRC}                             \
	 install

.include <bsd.port.mk>
