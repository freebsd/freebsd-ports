PORTNAME=	oletools
PORTVERSION=	0.60.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Tools to analyze security characteristics of MS OLE2 files
WWW=		https://pypi.org/project/oletools/

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/oletools/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorclass>=0:textproc/py-colorclass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}easygui>=0:x11-toolkits/py-easygui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msoffcrypto-tool>=0:security/py-msoffcrypto-tool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}olefile>=0.46:devel/py-olefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing2>=2.1.0<3:devel/py-pyparsing2@${PY_FLAVOR}

USES=		dos2unix python zip
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
