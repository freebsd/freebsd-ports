# New ports collection makefile for:	Test::Mock::Guard
# Date created:		22 Aug 2012
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Mock-Guard
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple mock test library using RAII

BUILD_DEPENDS=	p5-Class-Load>=0.06:${PORTSDIR}/devel/p5-Class-Load
RUN_DEPENDS=	p5-Class-Load>=0.06:${PORTSDIR}/devel/p5-Class-Load

PERL_CONFIGURE=	yes

MAN3=	Test::Mock::Guard.3

.include <bsd.port.mk>
