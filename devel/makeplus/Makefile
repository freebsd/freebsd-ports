# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	makeplus
# Date created:		2002-12-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	makeplus
PORTVERSION=	0.1.2
PORTREVISION=	1
PORTEPOCH=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.annexia.org/freeware/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of GNU Make rules for building packages with gmake

RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake

PREFIX?=	${LOCALBASE}
MAKE_ENV+=	MAKEPLUS_HOME=${WRKSRC}
NO_MTREE=	yes

MAN1=		make+.1

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./make+ \
		prefix=${PREFIX} manprefix=${PREFIX}

do-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
		./make+ install prefix=${PREFIX} manprefix=${PREFIX}

.include <bsd.port.post.mk>

#EOF
