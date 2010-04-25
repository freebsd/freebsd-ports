# New ports collection makefile for:	p5-TryCatch
# Date created:		22 April 2010
# Whom:		milki
#
# $FreeBSD$
#

PORTNAME=	TryCatch
PORTVERSION=	1.002000
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	 ../../authors/id/A/AS/ASH
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	First class try catch semantics for Perl, without source filters

BUILD_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-ExtUtils-Depends>=0.302:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-B-Hooks-OP-Check>=0.18:${PORTSDIR}/devel/p5-B-Hooks-OP-Check \
		p5-B-Hooks-OP-PPAddr>=0.03:${PORTSDIR}/devel/p5-B-Hooks-OP-PPAddr
RUN_DEPENDS=	p5-Parse-Method-Signatures>=1.003012:${PORTSDIR}/devel/p5-Parse-Method-Signatures \
		p5-B-Hooks-EndOfScope>=0.08:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Devel-Declare>=0.005007:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Scope-Upper>=0.06:${PORTSDIR}/devel/p5-Scope-Upper \
		p5-Variable-Magic>=0.28:${PORTSDIR}/devel/p5-Variable-Magic \
		p5-Sub-Exporter>=0.979:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-XSLoader>=0:${PORTSDIR}/devel/p5-XSLoader

PERL_CONFIGURE=	5.8.1+

MAN3=	TryCatch.3

.include <bsd.port.mk>
