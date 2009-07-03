# New ports collection makefile for:	Cache-FastMmap
# Date created:	   25 January 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Cache-FastMmap
PORTVERSION=	1.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Uses an mmap'ed file to act as a shared memory interprocess cache

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Cache::FastMmap.3 Cache::FastMmap::CImpl.3

.include <bsd.port.mk>
