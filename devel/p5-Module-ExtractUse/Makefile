# New ports collection makefile for:	p5-Module-ExtractUse
# Date created:		13 February 2007
# Whom:	      		Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-ExtractUse
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Find out what CPAN modules are used

RUN_DEPENDS=	${SITE_PERL}/Pod/Strip.pm:${PORTSDIR}/textproc/p5-Pod-Strip \
		p5-Parse-RecDescent>=1.94:${PORTSDIR}/devel/p5-Parse-RecDescent
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Module::ExtractUse.3

.include <bsd.port.mk>
