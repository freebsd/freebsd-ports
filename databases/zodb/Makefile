# New ports collection makefile for:	zodb
# Date created:		18 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zodb
PORTVERSION=	2001.06.16
CATEGORIES=	databases python
MASTER_SITES=	http://amk.ca/files/zodb/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bsddb3/__init__.py:${PORTSDIR}/databases/py-bsddb3

USE_PYTHON=	yes
SRCDIRS=	zodb-basic ExtensionClass ZODB BTrees

do-build:
.for dir in ${SRCDIRS}
	@ cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
	  setup.py build
.endfor

do-install:
.for dir in ${SRCDIRS}
	@ cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
	  setup.py install -c -O1 --prefix=${PREFIX}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ACKS CHANGES README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
