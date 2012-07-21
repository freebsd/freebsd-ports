# New ports collection makefile for:	p5-Test-Net-RabbitMQ
# Date created:		2010-09-10
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Net-RabbitMQ
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GPHAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A Perl mock RabbitMQ implementation for use when testing

BUILD_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		Test::Net::RabbitMQ.3

.include <bsd.port.mk>
