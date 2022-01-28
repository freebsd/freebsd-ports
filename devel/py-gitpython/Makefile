PORTNAME=	gitpython
DISTVERSION=	3.1.26
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	GitPython-${PORTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Python Git Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gitdb>=4.0.1<5:devel/py-gitdb@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ddt>=1.1.1:devel/py-ddt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4.3:devel/py-typing-extensions@${PY_FLAVOR}
.endif

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m nose

.include <bsd.port.post.mk>
