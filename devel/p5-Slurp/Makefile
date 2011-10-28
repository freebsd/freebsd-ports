# New ports collection makefile for:	p5-Slurp
# Date created:				October 28, 2011
# Whom:	      				Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	Slurp
PORTVERSION=	0.4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROBAU
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Slurp entire files into variables

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	YES

MAN3=		Slurp.3

PLIST_FILES=	%%SITE_PERL%%/Slurp.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Slurp/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Slurp

.include <bsd.port.mk>
