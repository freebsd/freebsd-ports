# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	ReadLine-Perl
PORTVERSION=	1.0303
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-
DISTNAME=	Term-${PORTNAME}-${PORTVERSION:C/0+$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl 5 module for Term::ReadLine editing without GNU readline

USES=		perl5
USE_PERL5=	configure

post-install:
	# this port and devel/p5-ReadLine-Perl-TTYtter both install same file
	# teach this port don't install this file and resolve conflict
	${RM} ${STAGEDIR}/${SITE_PERL}/${PERL_ARCH}/auto/Term/ReadLine/.packlist

.include <bsd.port.mk>
