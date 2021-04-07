PORTNAME=	http-prompt
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Interactive command-line HTTP client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=5.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsimonious>=0.6.2:textproc/py-parsimonious@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit2>=2.0.0<2.1.0:devel/py-prompt-toolkit2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.1.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpie>=0.9.2:www/py-httpie@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

SUB_FILES=	pkg-message

.include <bsd.port.mk>
