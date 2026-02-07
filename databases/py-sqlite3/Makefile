PORTNAME=	sqlite3
DISTVERSION=	${PYTHON_DISTVERSION}
PORTREVISION=	10
CATEGORIES=	databases python
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Standard Python binding to the SQLite3 library (Python ${PYTHON_VER})

LICENSE=	PSFL
LICENSE_FILE=	${WRKDIR}/Python-${DISTVERSION}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		compiler:c11 python tar:xz
USE_PYTHON=	allflavors autoplist pep517

DISTINFO_FILE=	${PORTSDIR}/lang/python${PYTHON_BASESUFFIX}/distinfo
WRKSRC_SUBDIR=	Modules

SUB_LIST+=	DISTVERSION=${DISTVERSION}
SUB_FILES=	pyproject.toml
PLIST_FILES=	${PYTHONPREFIX_LIBDIR:S;${PREFIX}/;;}/lib-dynload/_sqlite3${PYTHON_SOABI}.so

PORTSCOUT=	ignore:1

pre-configure:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}
	@${MV} ${WRKDIR}/pyproject.toml ${WRKSRC}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_sqlite3${PYTHON_SOABI}.so
	# lib-dynload is the expected location
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_LIBDIR}/lib-dynload
	@(cd ${STAGEDIR}${PYTHONPREFIX_LIBDIR}/lib-dynload && ${LN} -s ../site-packages/_sqlite3${PYTHON_SOABI}.so)

do-test:
	@${PYTHON_CMD} -c 'import sqlite3'  # minimal smoke test

.include <bsd.port.mk>
