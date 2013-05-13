# Created by: chinsan
# $FreeBSD$

PORTNAME=	Acme-GuessNumber
PORTVERSION=	0.04
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Locale/IMACAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatic number guessing game robot

PERL_CONFIGURE=	yes
MAN3=		Acme::GuessNumber.3

PLIST_FILES=	%%SITE_PERL%%/Acme/GuessNumber.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Acme-GuessNumber/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Acme-GuessNumber \
		%%SITE_PERL%%/Acme

.include <bsd.port.mk>
