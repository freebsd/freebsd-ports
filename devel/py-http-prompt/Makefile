# $FreeBSD$

PORTNAME=	http-prompt
PORTVERSION=	0.11.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Interactive command-line HTTP client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=5.0:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsimonious>=0.6.2:textproc/py-parsimonious@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt_toolkit>=0.60:devel/py-prompt_toolkit@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.1.0:textproc/py-pygments@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpie>=0.9.2:www/py-httpie@${FLAVOR}

NO_ARCH=	yes
SUB_FILES=	pkg-message
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
