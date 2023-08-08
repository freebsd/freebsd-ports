PORTNAME=	http-prompt
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interactive HTTP command-line client
WWW=		https://github.com/httpie/http-prompt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=5.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpie>=2.4.0:www/py-httpie@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsimonious>=0.6.2:textproc/py-parsimonious@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit2>=2.0.0<3.0.0:devel/py-prompt-toolkit2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.1.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.0:devel/py-yaml@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SUB_FILES=	pkg-message

.include <bsd.port.mk>
