# New ports collection makefile for:	devel/p5-Module-Starter
# Date created:				March 15 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Module-Starter
PORTVERSION=	1.54
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A simple starter kit for any Perl module

BUILD_DEPENDS=	${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage

PERL_CONFIGURE=	yes

MAN1=		module-starter.1
MAN3=		Module::Starter.3 \
		Module::Starter::App.3 \
		Module::Starter::BuilderSet.3 \
		Module::Starter::Simple.3 \
		Module::Starter::Plugin.3 \
		Module::Starter::Plugin::Template.3

.include <bsd.port.mk>
