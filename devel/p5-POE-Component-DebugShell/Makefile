# New ports collection makefile for:	POE-Component-DebugShell
# Date created:	   28 February 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-DebugShell
PORTVERSION=	1.412
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Interactive peeking into a running POE application

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-API-Peek>=0:${PORTSDIR}/devel/p5-POE-API-Peek
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Distribution>=0:${PORTSDIR}/devel/p5-Test-Distribution

PERL_CONFIGURE=	yes

MAN3=		POE::Component::DebugShell.3

.include <bsd.port.mk>
