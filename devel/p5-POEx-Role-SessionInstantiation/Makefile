# New ports collection makefile for:	POEx::Role::SessionInstantiation
# Date created:		10 Oct 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POEx-Role-SessionInstantiation
PORTVERSION=	1.102610
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NP/NPEREZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of Moose role for turning objects into POE sessions

RUN_DEPENDS=	\
	p5-MooseX-CompileTime-Traits>=0:${PORTSDIR}/devel/p5-MooseX-CompileTime-Traits \
	p5-MooseX-Declare>0:${PORTSDIR}/devel/p5-MooseX-Declare \
	p5-MooseX-Types>0:${PORTSDIR}/devel/p5-MooseX-Types \
	p5-MooseX-Types>0:${PORTSDIR}/devel/p5-MooseX-Types \
	p5-POE>0:${PORTSDIR}/devel/p5-POE \
	p5-POEx-Types>=0:${PORTSDIR}/devel/p5-POEx-Types \
	p5-aliased>0:${PORTSDIR}/devel/p5-aliased
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POEx::Role::Event.3 \
	POEx::Role::SessionInstantiation.3 \
	POEx::Role::SessionInstantiation::Meta::POEState.3 \
	POEx::Role::SessionInstantiation::Meta::Session::Events.3 \
	POEx::Role::SessionInstantiation::Meta::Session::Implementation.3 \
	POEx::Role::SessionInstantiation::Meta::Session::Magic.3 \
	POEx::Role::SessionInstantiation::Meta::Session::Sugar.3

.include <bsd.port.mk>
