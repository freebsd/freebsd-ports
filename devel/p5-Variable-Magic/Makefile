# Ports collection makefile for:	p5-Variable-Magic
# Date created:				2008/08/30
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Variable-Magic
PORTVERSION=	0.48
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Associate user-defined magic to variables from Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Module-CPANTS-Analyse>=0:${PORTSDIR}/devel/p5-Module-CPANTS-Analyse \
		p5-Test-Kwalitee>=0:${PORTSDIR}/devel/p5-Test-Kwalitee \
		p5-Test-Portability-Files>=0:${PORTSDIR}/devel/p5-Test-Portability-Files

PERL_CONFIGURE=	yes

MAN3=		Variable::Magic.3

.include <bsd.port.mk>
