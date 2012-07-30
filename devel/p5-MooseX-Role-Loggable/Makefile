# New ports collection makefile for:	p5-MooseX-Role-Loggable
# Date created:		2012-02-04
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Role-Loggable
PORTVERSION=	0.008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensive, yet simple, logging role using Log::Dispatchouli

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Dispatchouli>=0:${PORTSDIR}/devel/p5-Log-Dispatchouli \
		p5-Moo>=1.000001:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0:${PORTSDIR}/devel/p5-MooX-Types-MooseLike \
		p5-Safe-Isa>=0:${PORTSDIR}/devel/p5-Safe-Isa \
		p5-Sys-Syslog>=0.25:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Role::Loggable.3

.include <bsd.port.mk>
