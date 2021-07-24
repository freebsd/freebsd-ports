# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	contextvars
PORTVERSION=	2.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEP 567 backport

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}immutables>=0.9:devel/py-immutables@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 30700
IGNORE=		included in python ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
