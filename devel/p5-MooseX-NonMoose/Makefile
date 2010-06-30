# New ports collection makefile for:	devel/p5-MooseX-NonMoose
# Date created:				March 23, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-NonMoose
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy subclassing of non-Moose classes

RUN_DEPENDS=	p5-Moose>=1.08:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		MooseX::NonMoose.3 \
		MooseX::NonMoose::InsideOut.3 \
		MooseX::NonMoose::Meta::Role::Class.3 \
		MooseX::NonMoose::Meta::Role::Constructor.3

.include <bsd.port.mk>
