# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	makeplus
# Date created:		2002-12-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	makeplus
PORTVERSION=	0.0.15
PORTREVISION=	0
PORTEPOCH=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.annexia.org/freeware/${PORTNAME}/

USE_GMAKE=	yes
PREFIX?=	${LOCALBASE}
MAKE_ENV+=	MAKEPLUS_HOME=${WRKSRC}
NO_MTREE=	yes

MAINTAINER=	alane@FreeBSD.org

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./make+

do-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./make+ install prefix=${PREFIX}

.include <bsd.port.post.mk>

#EOF
