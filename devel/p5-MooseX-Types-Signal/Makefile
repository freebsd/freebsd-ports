# New ports collection makefile for:	p5-MooseX-Types-Signal
# Date created:	   16 Dec 2010
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types-Signal
PORTVERSION=	1.101932
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	A type to represent valid UNIX or Perl signals

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MooseX-Types>0:${PORTSDIR}/devel/p5-MooseX-Types
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Moose>0:${PORTSDIR}/devel/p5-Moose

PERL_CONFIGURE=	yes

MAN3=		MooseX::Types::Signal.3

.include <bsd.port.mk>
