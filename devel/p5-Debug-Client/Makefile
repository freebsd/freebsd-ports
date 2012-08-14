# New ports collection makefile for:	p5-Debug-Client
# Date created:		2010-03-17
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	Debug-Client
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client for the standard Perl debugger

BUILD_DEPENDS=	p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir
RUN_DEPENDS=	p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir

TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

PERL_CONFIGURE=	yes

MAN3=		Debug::Client.3

.include <bsd.port.mk>
