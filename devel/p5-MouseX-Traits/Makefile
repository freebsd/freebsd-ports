# New ports collection makefile for:	p5-MouseX-Traits
# Date created:		2011-06-02
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MouseX-Traits
PORTVERSION=	0.1102
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically apply roles at object creation time

BUILD_DEPENDS=	p5-Mouse>=0.81:${PORTSDIR}/devel/p5-Mouse
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USE_PERL5=	configure
USES=		perl5

MAN3=		MouseX::Traits.3

.include <bsd.port.mk>
