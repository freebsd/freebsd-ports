PORTNAME=	keystone-engine
DISTVERSION=	0.9.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Keystone Assembler Engine with Python bindings
WWW=		https://github.com/keystone-engine/keystone

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cmake:indirect pkgconfig python
USE_PYTHON=	autoplist pep517

post-install:
	${STRIP} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/keystone/libkeystone.so

.include <bsd.port.mk>
