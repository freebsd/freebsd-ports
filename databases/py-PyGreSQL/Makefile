# Ports collection Makefile for:	PyGreSQL
# Date created:				2/22/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	PyGreSQL
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org

POSTGRESQL_SUBPORT=	YES
.include <${.CURDIR}/../postgresql7/Makefile>

BUILD_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
RUN_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

POSTGRESQL_PORT?=	databases/postgresql7

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
