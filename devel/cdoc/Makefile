# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	cdoc
# Date created:		2002-12-22
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cdoc
PORTVERSION=	0.9.6
PORTREVISION=	1
PORTEPOCH=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.annexia.org/freeware/${PORTNAME}/

MAINTAINER=	alane@FreeBSD.org

BUILD_DEPENDS+=	make+:${.CURDIR}/../makeplus

USE_GMAKE=	yes
USE_PERL5_RUN=	yes
PREFIX?=	${LOCALBASE}

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC}; make+

do-install:
	cd ${WRKSRC}; make+ install prefix=${PREFIX}

.include <bsd.port.post.mk>

#EOF
