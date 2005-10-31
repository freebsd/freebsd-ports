# New ports collection makefile for:	devel/p5-Devel-Constants
# Date created:				10 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Devel-Constants
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to translate constants back to their named symbols

PERL_CONFIGURE=	yes

MAN3=		Devel::Constants.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
