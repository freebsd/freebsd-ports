# New ports collection makefile for:	dns/p5-Net-Domain-TLD
# Date created:				30 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Domain-TLD
PORTVERSION=	1.65
CATEGORIES=	dns perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Net::Domain::TLD - look up and validate TLDs

BUILD_DEPENDS=	${SITE_PERL}/Memoize.pm:${PORTSDIR}/devel/p5-Memoize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::Domain::TLD.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
