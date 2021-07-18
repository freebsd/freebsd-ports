PORTNAME=	goatools
DISTVERSION=	1.1.6
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for processing and visualizing Gene Ontology terms

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# xlrd should be == 1.2.0
RUN_DEPENDS=	${PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>0:textproc/py-xlsxwriter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>0:math/py-statsmodels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>0:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docopt>0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydot>0:graphics/py-pydot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygraphviz>0:graphics/py-pygraphviz@${PY_FLAVOR} \
		wget>0:ftp/wget

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
