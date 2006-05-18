# New ports collection makefile for:	tcc
# Date created:		16 May 2006
# Whom:			Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcc
PORTVERSION=	0.9.23
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://fabrice.bellard.free.fr/tcc/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	A small and fast C compiler

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX}
MAN1=		tcc.1

ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>
