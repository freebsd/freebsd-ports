# Ports collection Makefile for:	PyGreSQL
# Date created:				2/22/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#
POSTGRESQL_PORT?=	databases/postgresql7

PORTNAME=	PyGreSQL
PORTVERSION!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V PORTVERSION
PORTREVISION?=	0
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V MASTER_SITE_SUBDIR
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V DISTFILES
DIST_SUBDIR=	postgresql
WRKSRC=		${WRKDIR}/postgresql-${PORTVERSION}

MAINTAINER=	girgen@pingpong.net
COMMENT=	A Python interface to PostgreSQL, including a DP-API 2.0 wrapper

BUILD_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
RUN_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

MD5_FILE=	${.CURDIR}/../../${POSTGRESQL_PORT}/distinfo

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_PYTHON=	yes
CONFIGURE_ARGS=	--with-python --prefix=${PREFIX}
MAKE_ARGS+=	-C src/interfaces/python
CFLAGS+=	-L${LOCALBASE}/lib
MAKEFILE=	GNUmakefile

DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py

post-install:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -lf \
	  ${PYTHONPREFIX_SITELIBDIR}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -lf \
	  ${PYTHONPREFIX_SITELIBDIR}
.if !defined(NOPORTDOCS)
.for docfile in Announce ChangeLog README
	@ ${MKDIR} ${DOCSDIR}
	  ${INSTALL_DATA} ${WRKSRC}/src/interfaces/python/${docfile} \
	  ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
