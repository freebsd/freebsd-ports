# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pipx
PORTVERSION=	0.16.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Install and Run Python Applications in Isolated Environments

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=1.9.4<2.0:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.4:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}userpath>=1.4.1:devel/py-userpath@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.3.0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
