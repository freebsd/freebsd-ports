# Created by: thierry@pompo.net

PORTNAME=	guppy3
PORTVERSION=	3.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python Programming Environment & Heap analysis toolset

LICENSE=	MIT

#USE_GITHUB=	yes
#GH_ACCOUNT=	zhuyifei1999

USES=		python:3.7+
USE_PYTHON=	cython distutils

.if ! defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

TMPDIR?=	/tmp

do-test: install
	(cd ${TMPDIR} &&	\
	${PYTHON_CMD} -c "from guppy import hpy; hpy().test()")

.include <bsd.port.mk>
