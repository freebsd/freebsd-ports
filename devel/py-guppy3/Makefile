PORTNAME=	guppy3
PORTVERSION=	3.1.5
PORTREVISION=	2
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
USE_PYTHON=	cython3 distutils

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
X11_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

.if ! defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

TMPDIR?=	/tmp

do-test: install
	(cd ${TMPDIR} &&	\
	${PYTHON_CMD} -c "from guppy import hpy; hpy().test()")

.include <bsd.port.mk>
