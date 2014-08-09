# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	5
CATEGORIES=	databases python
MASTER_SITES=	PYTHON
MASTER_SITE_SUBDIR=	ftp/python/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Standard Python binding to the SQLite3 library

LICENSE=	PSFL

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

PORTSCOUT=	ignore:1

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USES=		tar:xz

DIST_SUBDIR=	python
DISTINFO_FILE=	${PORTSDIR}/lang/python${PYTHON_SUFFIX}/distinfo
WRKSRC=		${WRKDIR}/Python-${PORTVERSION}/Modules

PYDISTUTILS_INSTALLARGS+=	--install-lib ${PYTHON_LIBDIR}/lib-dynload
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

post-extract:
.if ${PYTHON_REL} < 300
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}
.else
	@${CP} ${FILESDIR}/setup3.py ${WRKSRC}/setup.py
.endif

.include <bsd.port.post.mk>
