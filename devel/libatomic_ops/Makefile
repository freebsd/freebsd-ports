# New ports collection makefile for:	libatomic-ops
# Date created:				09/22/2011
# Whom:					stas
#
# $FreeBSD$
#

PORTNAME=	libatomic_ops
PORTVERSION=	7.2.a6
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/
DISTNAME=	gc-${PORTVERSION:S/.a/alpha/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atomic operations access library

USE_AUTOTOOLS=	aclocal autoconf automake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/libatomic_ops

.include <bsd.port.mk>
