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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python source to bytecode compiler

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${PYTHON_WRKSRC}/Tools/${PORTNAME}

.include <bsd.port.pre.mk>
.if ${PYTHON_REL} >= 220
IGNORE=	is part of the standard library from Python 2.2 upwards
.endif

.include <bsd.port.post.mk>
