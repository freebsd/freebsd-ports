# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitless
PORTVERSION=	0.8.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Version control system built on top of Git

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}clint>=0.3.6:devel/py-clint@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygit2>=0.23.0:devel/py-pygit2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sh>=1.11:devel/py-sh@${FLAVOR} \
		git:devel/git

USES=		python
USE_PYTHON=	autoplist concurrent distutils
USE_LOCALE=	en_US.UTF-8

USE_GITHUB=	yes
GH_ACCOUNT=	sdg-mit

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
