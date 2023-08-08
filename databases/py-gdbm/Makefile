PORTNAME=	gdbm
DISTVERSION=	${PYTHON_DISTVERSION}
PORTREVISION=	7
CATEGORIES=	databases python
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings to the GNU dbm library (Python ${PYTHON_VER})

LICENSE=	PSFL

LIB_DEPENDS=	libgdbm.so:databases/gdbm

USES=		compiler:c11 python tar:xz
USE_PYTHON=	allflavors autoplist distutils

DISTINFO_FILE=	${.CURDIR}/../../lang/python${PYTHON_SUFFIX}/distinfo
PYDISTUTILS_INSTALLARGS+=	--install-lib ${PYTHONPREFIX_LIBDIR}/lib-dynload
WRKSRC_SUBDIR=	Modules

PORTSCOUT=	ignore:1

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/lib-dynload/_gdbm.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
