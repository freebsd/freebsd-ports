# New ports collection makefile for:	cx_Freeze
# Date created:				05 Apr 2009
# Whom:					Marcelo Araujo <araujo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cx_Freeze
PORTVERSION=	4.0.1
CATEGORIES=	devel python
MASTER_SITES=	SF/cx-freeze/${PORTNAME}/${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	The cx_Freeze is a set of utilities for freezing Python scripts

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build on 6.X
.endif

.include <bsd.port.post.mk>
