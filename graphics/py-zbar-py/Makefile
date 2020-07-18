# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zbar-py
PORTVERSION=	1.0.4
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Interface to the zbar bar-code reading library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzbar.so:graphics/zbar
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

USES=		iconv:wchar_t python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/zbar/_zbar.so

.include <bsd.port.mk>
