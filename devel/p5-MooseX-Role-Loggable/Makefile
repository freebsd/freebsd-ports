# New ports collection makefile for:	p5-MooseX-Role-Loggable
# Date created:		2012-02-04
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Role-Loggable
PORTVERSION=	0.007
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensive, yet simple, logging role using Log::Dispatchouli

BUILD_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Log-Dispatchouli>=0:${PORTSDIR}/devel/p5-Log-Dispatchouli \
		p5-Sys-Syslog>=0.16:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-File-Temp>=0.20:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Log-Dispatchouli>=0:${PORTSDIR}/devel/p5-Log-Dispatchouli \
		p5-Sys-Syslog>=0.16:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

PERL_CONFIGURE=	yes

MAN3=	MooseX::Role::Loggable.3

.include <bsd.port.mk>
