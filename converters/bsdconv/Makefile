# New ports collection makefile for:	bsdconv
# Date created:				23 May 2009
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	4.3
CATEGORIES=	converters
MASTER_SITES=	http://cloud.github.com/downloads/buganini/bsdconv/

MAINTAINER=	buganini@gmail.com
COMMENT=	BSD licensed charset/encoding converter library

USE_LDCONFIG=	yes

MAKE_ARGS=	PREFIX=${PREFIX}

.include <bsd.port.pre.mk>

#.if ${OSVERSION} < 701101
EXTRA_PATCHES=	${FILESDIR}/extra-patch-strndup
#.endif

.include <bsd.port.post.mk>
