# New ports collection makefile for:	p5-Module-Refresh
# Date created:		13 February 2005
# Whom:	      		aturetta@commit.it
#
# $FreeBSD$
#

PORTNAME=	Module-Refresh
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Refresh %INC files when updated on disk

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker>=6.42:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-File-Temp>=0.19:${PORTSDIR}/devel/p5-File-Temp \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

USE_PERL5=	5.8.1+
PERL_CONFIGURE=	yes

MAN3=		Module::Refresh.3

.include <bsd.port.mk>
