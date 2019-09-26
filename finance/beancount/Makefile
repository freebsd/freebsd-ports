# $FreeBSD$

PORTNAME=	beancount
PORTVERSION=	2.2.3
CATEGORIES=	finance
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Double-Entry Accounting from Text Files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bottle>=0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>=0:devel/py-python-magic@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bottle>=0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>=0:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>=0:devel/py-python-magic@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils noflavors

# Project hosted on Bitbucket
BB_ACCOUNT=	blais
BB_COMMIT=	ff1e2616b26a
BB_PROJECT=	${PORTNAME}

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/parser/_parser.so

.include <bsd.port.mk>
