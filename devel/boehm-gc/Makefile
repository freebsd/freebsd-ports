# New ports collection makefile for:	boehm-gc
# Date created:		15 November 1996
# Whom:			Mike McGaughey <mmcg@cs.monash.edu.au>
#
# $FreeBSD$
#

PORTNAME=	boehm-gc
PORTVERSION=	5.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/
DISTNAME=	gc5.3

MAINTAINER=	ports@FreeBSD.org

ONLY_FOR_ARCHS=	i386	# XXX can't figure out whether to define
#			# XXX SEARCH_FOR_DATA_START on other platforms

WRKSRC=		${WRKDIR}/gc
MAN3=		gc.3
ALL_TARGET=	FreeBSD-pkg-all
INSTALL_TARGET=	FreeBSD-pkg-install
MAKE_ENV+=	CP="${CP}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"

.include <bsd.port.mk>
