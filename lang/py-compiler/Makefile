# New ports collection makefile for:    py-compiler
# Date created:         6 September 2001
# Whom:                 Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#
# XXX The compiler package is included in Python 2.1 upwards.
#     This port somehow needs to take this into account.

PORTNAME=	compiler
PORTVERSION=	${PYTHON_PORTVERSION}
CATEGORIES=	lang python
MASTER_SITES=	http://www.python.org/ftp/python/${PORTVERSION}/ \
		http://SunSITE.Informatik.RWTH-Aachen.DE/python/ftp/python/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}

DIST_SUBDIR=	python
USE_PYTHON=	yes
WRKSRC=		${PYTHON_WRKSRC}/Tools/${PORTNAME}

.include <bsd.port.pre.mk>
.if ${PYTHON_REL} >= 220
FORBIDDEN=	"Part of the standard library from Python 2.2 upwards"
.endif

do-build:
	@ cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py build

do-install:
	@ cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
	  setup.py install -c -O1 --prefix=${PREFIX}

.include <bsd.port.post.mk>
