# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	c2lib
# Date created:		2002-12-22
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2lib
PORTVERSION=	1.3.0
PORTREVISION=	0
PORTEPOCH=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.annexia.org/freeware/${PORTNAME}/

MAINTAINER=	alane@FreeBSD.org

BUILD_DEPENDS+=	cdoc:${.CURDIR}/../../devel/cdoc
BUILD_DEPENDS+=	make+:${.CURDIR}/../../devel/makeplus

USE_GMAKE=	yes
PREFIX?=	${LOCALBASE}
MAKE_ENV+=	CC="${CC}"
.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} make+ 

do-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV}\
		make+ install prefix=${PREFIX} manprefix=${PREFIX}

.include "${.CURDIR}/manpages.mk"
.include <bsd.port.post.mk>

#EOF
