# New ports collection makefile for:	p5-Test-Net-RabbitMQ
# Date created:		2010-09-10
# Whom:			Steve Wills <swills@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Net-RabbitMQ
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/G/GP/GPHAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A Perl mock RabbitMQ implementation for use when testing

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker>0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
		p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3=		Test::Net::RabbitMQ.3

.include <bsd.port.mk>
