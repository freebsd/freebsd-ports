# New ports collection makefile for:	Devel-Events-Objects
# Date created:	   			23 Oct 2008
# Whom:		   			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-Events-Objects
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Perl module providing object tracking support for Devel::Events

RUN_DEPENDS=	p5-Devel-Events>=0:${PORTSDIR}/devel/p5-Devel-Events \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Tie-RefHash-Weak>=0:${PORTSDIR}/devel/p5-Tie-RefHash-Weak \
		p5-Variable-Magic>=0:${PORTSDIR}/devel/p5-Variable-Magic

PERL_CONFIGURE=	yes

MAN3=		Devel::Events::Generator::Objects.3 \
		Devel::Events::Handler::ObjectTracker.3 \
		Devel::Events::Objects.3

.include <bsd.port.mk>
