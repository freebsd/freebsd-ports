# New ports collection makefile for:	bsdconv
# Date created:				23 May 2009
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	3.6.2
CATEGORIES=	converters
MASTER_SITES=	http://security-hole.info/distfile/
DISTNAME=	buganini-bsdconv-3.6.2-0-g66aab4b

MAINTAINER=	buganini@gmail.com
COMMENT=	BSD licensed charset/encoding converter library

USE_LDCONFIG=	yes

MAKE_ARGS=	PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/buganini-bsdconv-66aab4b

.include <bsd.port.pre.mk>

#.if ${OSVERSION} < 701101
EXTRA_PATCHES=	${FILESDIR}/extra-patch-strndup
#.endif

.include <bsd.port.post.mk>
