# New ports collection makefile for:	Cache-FastMmap
# Date created:	   25 January 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Cache-FastMmap
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Cache
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Uses an mmap'ed file to act as a shared memory interprocess cache

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Cache::FastMmap.3 Cache::FastMmap::CImpl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	Perl 5.6 or newer required. Install lang/perl5.8 or lang/perl5 and try again
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.[pP][mL]" | \
		${XARGS} ${PERL} -i -pe 's/^use 5.008/use 5.006/'

.include <bsd.port.post.mk>
