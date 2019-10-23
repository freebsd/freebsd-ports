# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pooch
PORTVERSION=	0.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fetch your sample data files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PY_PATHLIB} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
USE_LOCALE=	en_US.UTF-8

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.tempfile>=0:devel/py-backports.tempfile@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
