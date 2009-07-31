# New ports collection makefile for:	py-prolog
# Date created:		28 Jun 2003
# Whom:			Gerhard Gonter <g.gonter@ieee.org>
#
# $FreeBSD$

PORTNAME=	prolog
PORTVERSION=	0.1
PORTREVISION=	1
PORTREVSION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyprolog
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyProlog-${PORTVERSION}

MAINTAINER=	g.gonter@ieee.org
COMMENT=	A Python extension embedding SWI-Prolog

BUILD_DEPENDS=	pl:${PORTSDIR}/lang/swi-pl
RUN_DEPENDS=	pl:${PORTSDIR}/lang/swi-pl

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	PyProlog

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		"Does not build on ia64 or amd64 (can't link shared libraries to static)"
.endif

.include <bsd.port.post.mk>
