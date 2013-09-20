# Created by: Yuan-Chung Hsiao <ychsiao@gmail.com>
# $FreeBSD$

PORTNAME=	repoze.who-friendlyform
PORTVERSION=	1.0.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	A collection of developer-friendly for repoze.who-powered

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:${PORTSDIR}/devel/py-coverage \
		${PYTHON_PKGNAMEPREFIX}nose>=0:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}repoze.who>=1.0.15:${PORTSDIR}/devel/py-repoze.who
RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}coverage>=0:${PORTSDIR}/devel/py-coverage \
		${PYTHON_PKGNAMEPREFIX}nose>=0:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}repoze.who>=1.0.15:${PORTSDIR}/devel/py-repoze.who

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	repoze.who-friendlyform

NO_STAGE=	yes
.include <bsd.port.mk>
