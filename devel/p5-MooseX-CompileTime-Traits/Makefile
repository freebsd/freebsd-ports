# New ports collection makefile for:	MooseX::CompileTime::Traits
# Date created:		10 Oct 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-CompileTime-Traits
PORTVERSION=	1.102570
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to allow compile time traits for classes/roles

RUN_DEPENDS=	\
	p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Declare>0:${PORTSDIR}/devel/p5-MooseX-Declare
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	MooseX::CompileTime::Traits.3

.include <bsd.port.mk>
