# New ports collection makefile for:	MooseX-SetOnce
# Date created:				2011-04-03
# Whom:					Frederic Culot <culot@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-SetOnce
PORTVERSION=	0.200001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write-once, read-many attributes for Moose

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

MAN3=		MooseX::SetOnce.3

.include <bsd.port.mk>
