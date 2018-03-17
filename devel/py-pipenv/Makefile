# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pipenv
PORTVERSION=	11.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Development Workflow for Humans

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pew>=0.1.26:devel/py-pew@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=9.0.1:devel/py-pip@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv-clone>=0.2.5:devel/py-virtualenv-clone@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.14:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ordereddict>=0:devel/py-ordereddict@${FLAVOR}
.endif

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pathlib>=0:devel/py-pathlib@${FLAVOR}
.endif

.include <bsd.port.post.mk>
