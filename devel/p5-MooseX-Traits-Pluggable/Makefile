# New ports collection makefile for:	devel/p5-MooseX-Traits-Pluggable
# Date created:				25 July 2009
# Whom:					Bill Brinzer <bill.brinzer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Traits-Pluggable
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RK/RKITOVER/
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	An extension to MooseX::Traits

BUILD_DEPENDS=	\
	p5-Class-MOP>=0.84:${PORTSDIR}/devel/p5-Class-MOP \
	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Moose-Autobox>=0:${PORTSDIR}/devel/p5-Moose-Autobox \
	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
	p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	\
	p5-Class-MOP>=0.84:${PORTSDIR}/devel/p5-Class-MOP \
	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Moose-Autobox>=0:${PORTSDIR}/devel/p5-Moose-Autobox \
	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
	p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	5.8.1+

MAN3=	MooseX::Traits::Pluggable.3

.include <bsd.port.mk>
