PORTNAME=	ramlfications
PORTVERSION=	0.1.9
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Python parser for RAML
WWW=		https://github.com/spotify/ramlfications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=16.0.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonref>=0.1:devel/py-jsonref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown2>=2.3.2:textproc/py-markdown2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.10.1:devel/py-xmltodict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES?=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
