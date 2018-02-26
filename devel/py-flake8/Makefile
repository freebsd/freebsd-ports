# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	flake8
PORTVERSION=	3.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Code checking using pep8 and pyflakes

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${FLAVOR}
RUN_DEPENDS=	${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}mccabe>=0.5.0:devel/py-mccabe@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>=2.0.0:devel/py-pycodestyle@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0.8.1:devel/py-pyflakes@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}configparser>0:devel/py-configparser@${FLAVOR}
.endif

.include <bsd.port.post.mk>
