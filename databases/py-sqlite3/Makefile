# Created by: Hye-Shik Chang

PORTNAME=	sqlite3
DISTVERSION=	${PYTHON_DISTVERSION}
PORTREVISION=	7
CATEGORIES=	databases python
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Standard Python binding to the SQLite3 library (Python ${PYTHON_VER})

LICENSE=	PSFL
LICENSE_FILE=	${WRKDIR}/Python-${DISTVERSION}/LICENSE

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

PORTSCOUT=	ignore:1

USES=		compiler:c11 python:2.7+ tar:xz
USE_PYTHON=	autoplist distutils allflavors

DISTINFO_FILE=	${PORTSDIR}/lang/python${PYTHON_SUFFIX}/distinfo
WRKSRC_SUBDIR=	Modules

PYDISTUTILS_INSTALLARGS+=	--install-lib ${PYTHON_LIBDIR}/lib-dynload

.include <bsd.port.pre.mk>

post-extract:
.if ${PYTHON_REL} < 30000
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}
.else
	@${CP} ${FILESDIR}/setup3.py ${WRKSRC}/setup.py
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/lib-dynload/_sqlite3*.so

.include <bsd.port.post.mk>
