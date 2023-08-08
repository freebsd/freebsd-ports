PORTNAME=	guppy3
PORTVERSION=	3.1.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python Programming Environment & Heap analysis toolset
WWW=		https://github.com/zhuyifei1999/guppy3/

LICENSE=	MIT

#USE_GITHUB=	yes
#GH_ACCOUNT=	zhuyifei1999

USES=		python
USE_PYTHON=	cython distutils

.if ! defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

TMPDIR?=	/tmp

do-test: install
	(cd ${TMPDIR} &&	\
	${PYTHON_CMD} -c "from guppy import hpy; hpy().test()")

.include <bsd.port.mk>
