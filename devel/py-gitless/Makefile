# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitless
PORTVERSION=	0.8.6
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Version control system built on top of Git

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}clint>=0.5.1:devel/py-clint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygit2>=0.26.0:devel/py-pygit2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sh>=1.12.14:devel/py-sh@${PY_FLAVOR} \
		git:devel/git
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils
USE_LOCALE=	en_US.UTF-8

USE_GITHUB=	yes
GH_ACCOUNT=	sdg-mit

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} nosetests-${PYTHON_VER} -v

.include <bsd.port.mk>
