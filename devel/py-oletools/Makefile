# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oletools
PORTVERSION=	0.54.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Tools to analyze security characteristics of MS OLE2 files

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/oletools/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.2.0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}olefile>=0.46:devel/py-olefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}easygui>=0:x11-toolkits/py-easygui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorclass>=0:textproc/py-colorclass@${PY_FLAVOR}

USES=		python zip
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
