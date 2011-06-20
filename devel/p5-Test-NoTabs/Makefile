# New ports collection makefile for:    p5-Test-NoTabs
# Date created:				2011-02-16
# Whom:	      				milki <milki@rescomp.berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	Test-NoTabs
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BOBTFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	Check the presence of tabs in your project

RUN_DEPENDS=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

TEST_DEPENDS=	p5-Test-Simple>=0;${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	--skipdeps

MAN3=		Test::NoTabs.3

.include <bsd.port.mk>
