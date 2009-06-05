# New ports collection makefile for:	bsdconv
# Date created:				23 May 2009
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	1.11
CATEGORIES=	converters
MASTER_SITES=	http://security-hole.info/distfile/
DISTNAME=	buganini-bsdconv-583422ced076a6b034160dea835d8e4b2a9d7371

MAINTAINER=	buganini@gmail.com
COMMENT=	BSD licensed charset/encoding converter library

USE_LDCONFIG=	yes

do-build:
	cd ${WRKSRC} && \
		make PREFIX=${LOCALBASE}

.include <bsd.port.mk>
