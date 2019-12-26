# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mwlib.rl
PORTVERSION=	0.14.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate Pdfs from Mediawiki Markup

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/texvc:print/texvc \
		${LOCALBASE}/bin/fribidi:converters/fribidi \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mwlib>=0.12.14:devel/py-mwlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mwlib.ext>=0.12.3:devel/py-mwlib.ext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.0:textproc/py-pygments@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
