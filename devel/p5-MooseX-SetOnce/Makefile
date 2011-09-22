# New ports collection makefile for:	MooseX-SetOnce
# Date created:				2011-04-03
# Whom:					Frederic Culot <culot@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-SetOnce
PORTVERSION=	0.200000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write-once, read-many attributes for Moose

LICENSE_COMB=	dual
LICENSE=	ART20 GPLv1

RUN_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

MAN3=		MooseX::SetOnce.3

.include <bsd.port.mk>
