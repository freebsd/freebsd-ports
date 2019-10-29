# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	pathlib2
PORTVERSION=	2.3.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Object-oriented filesystem paths

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}scandir>=0:sysutils/py-scandir@${PY_FLAVOR}
.endif

do-test:
	@(cd ${WRKSRC} && \
		${PYTHON_CMD} test_pathlib2.py && \
		${PYTHON_CMD} test_pathlib2_with_py2_unicode_literals.py)

.include <bsd.port.post.mk>
