# New ports collection makefile for:    p5-Cache-Mmap
# Date created:				January 25th 2003
# Whom:	      				Erwin Lansing <erwin@lansing.dk>
#
# $FreeBSD$
#

PORTNAME=	Cache-Mmap
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Cache
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Cache::Mmap.3

.include <bsd.port.mk>
