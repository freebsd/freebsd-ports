# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pipenv
PORTVERSION=	11.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Development Workflow for Humans

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pew>=0.1.26:devel/py-pew@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=9.0.1:devel/py-pip@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv-clone>=0.2.5:devel/py-virtualenv-clone@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pathlib>=0:devel/py-pathlib@${FLAVOR}
.endif

.include <bsd.port.post.mk>
