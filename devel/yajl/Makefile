# New ports collection makefile for:	yajl
# Date created:		2010-03-29
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	yajl
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/lloyd/yajl/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	A Portable JSON parsing and serialization library in ANSI C

USE_LDCONFIG=	yes
USE_CMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
