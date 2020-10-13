# Created by: Kirill Ponomarev <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tiamat
PORTVERSION=	7.3
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Single binary builder for Python projects

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pop>=0:devel/py-pop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

USE_GITLAB=	yes
GL_ACCOUNT=	saltstack/pop
GL_COMMIT=	e0d4c851aea63480127a11e01f77ab5df959b484

NO_ARCH=	yes

.include <bsd.port.mk>
