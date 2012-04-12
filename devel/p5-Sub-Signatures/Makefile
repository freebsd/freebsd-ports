# New ports collection makefile for:	p5-Sub-Signatures
# Date created:	   21 Nov 2010
# Whom:		   Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	Sub-Signatures
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	magik@roorback.net
COMMENT=	Use proper signatures for subroutines, including dispatching

BUILD_DEPENDS=	p5-Sub-Uplevel>=0.12:${PORTSDIR}/devel/p5-Sub-Uplevel
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		Sub::Signatures.3

.include <bsd.port.mk>
