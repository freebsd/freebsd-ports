PORTNAME=	xsdata
PORTVERSION=	25.7
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python XML Binding
WWW=		https://xsdata.readthedocs.io/en/latest/ \
		https://github.com/tefra/xsdata

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.7.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI LXML SOAP
LXML_DESC=	Handler/writer via lxml
SOAP_DESC=	Simple Object Access Protocol (SOAP) support

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=5.0:devel/py-click@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}click-default-group>=1.2:devel/py-click-default-group@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}docformatter>=1.7.2:devel/py-docformatter@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}toposort>=1.5:devel/py-toposort@${PY_FLAVOR} \
			ruff>=0.9.8:devel/ruff
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=4.5.0:devel/py-lxml5@${PY_FLAVOR}
SOAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
