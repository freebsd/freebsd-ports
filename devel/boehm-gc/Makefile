# New ports collection makefile for:	boehm-gc
# Date created:		15 November 1996
# Whom:			Mike McGaughey <mmcg@cs.monash.edu.au>
#
# $FreeBSD$
#

PORTNAME=	boehm-gc
PORTVERSION=	5.0a4
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/	\
		http://reality.sgi.com/boehm_mti/gc_source/
DISTNAME=	gc5.0alpha4

MAINTAINER=	mmcg@cs.monash.edu.au

ONLY_FOR_ARCHS=	i386

FETCH_BEFORE_ARGS=	-b

WRKSRC=		${WRKDIR}/gc
MAN3=		gc.3
ALL_TARGET=	FreeBSD-pkg-all
INSTALL_TARGET=	FreeBSD-pkg-install
MAKE_ENV+=	CP="${CP}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"

.include <bsd.port.mk>
