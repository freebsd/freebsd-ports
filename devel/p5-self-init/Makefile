# New ports collection makefile for:	p5-self-init
# Date created:		2009-07-13
# Whom:			Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	self-init
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MONS
PKGNAMEPREFIX=	p5-

TEST_DEPENDS=	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-ex-lib>=0:${PORTSDIR}/devel/p5-ex-lib

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Invoke package init methods at compile time

MAN3=	self::init.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
