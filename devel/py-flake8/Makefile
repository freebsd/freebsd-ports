# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	flake8
PORTVERSION=	3.7.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Code checking using pep8 and pyflakes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}mccabe>=0.6.0:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>=2.0.0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=1.5.0:devel/py-pyflakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}entrypoints>=0.3.0:devel/py-entrypoints@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}configparser>0:devel/py-configparser@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
