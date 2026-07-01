PORTNAME=	cld
PORTVERSION=	20150113
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	LOCAL/demon
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	chromium_compact_language_detector-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python bindings for compact language detector library
WWW=		https://code.google.com/p/chromium-compact-language-detector/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
LIB_DEPENDS=	libcld2.so:devel/cld2

USES=		python
USE_PYTHON=	flavors

post-patch:
	${REINPLACE_CMD} -e "s#\.\./cld2#${LOCALBASE}/include/cld#" ${WRKSRC}/setup.py ${WRKSRC}/setup_full.py

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py build
	cd ${WRKSRC} && ${PYTHON_CMD} setup_full.py build

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py install -c -O1 --prefix=${PREFIX} --root=${STAGEDIR}
	cd ${WRKSRC} && ${PYTHON_CMD} setup_full.py install -c -O1 --prefix=${PREFIX} --root=${STAGEDIR}

.include <bsd.port.mk>
