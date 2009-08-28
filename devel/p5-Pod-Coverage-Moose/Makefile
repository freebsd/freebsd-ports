# New ports collection makefile for:	p5-Pod-Coverage-Moose
# Date created:				2008/08/30
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Pod-Coverage-Moose
PORTVERSION=	0.02
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pod::Coverage extension for Moose

BUILD_DEPENDS=	${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-Pod-Parser \
		${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump \
		p5-Class-MOP>=0:${PORTSDIR}/devel/p5-Class-MOP \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Perl6-Junction>=0:${PORTSDIR}/devel/p5-Perl6-Junction \
		p5-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Pod-Coverage \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Pod::Coverage::Moose.3

.include <bsd.port.mk>
