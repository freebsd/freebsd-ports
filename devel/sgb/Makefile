# New ports collection makefile for:    sgb
# Date created:         2003-02-05
# Whom:			Gerald Pfeifer <gerald@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sgb
PORTVERSION=	20030623
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://labrea.stanford.edu/pub/sgb/
DISTNAME=	sgb-2003-06-23

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	The Stanford GraphBase: A Platform for Combinatorial Computing

BUILD_DEPENDS=	ctangle:${PORTSDIR}/devel/cweb

NO_WRKSUBDIR=	yes
ALL_TARGET=	lib tests

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${WRKSRC}/PROTOTYPES/* ${WRKSRC}

.include <bsd.port.post.mk>
