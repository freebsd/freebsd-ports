# Created by: Philip M. Gollucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	Data-Walk
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GUIDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Traverse Perl data structures

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

MAN3=	Data::Walk.3

PLIST_FILES=	%%SITE_PERL%%/Data/Walk.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Data/Walk/.packlist
PLIST_DIRS=	%%SITE_PERL%%/Data \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Data/Walk \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Data

.include <bsd.port.mk>
