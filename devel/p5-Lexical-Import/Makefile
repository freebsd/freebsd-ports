# New ports collection makefile for:	p5-Lexical-Import
# Date created:		2012-02-07
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lexical-Import
PORTVERSION=	0.002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Clean imports from package-exporting modules

BUILD_DEPENDS=	p5-Lexical-Var>=0.006:${PORTSDIR}/devel/p5-Lexical-Var \
		p5-Module-Runtime>=0.011:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Params-Classify>=0:${PORTSDIR}/devel/p5-Params-Classify
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USE_PERL5=	5.12.0+ configure
USES=		perl5

MAN3=		Lexical::Import.3

.include <bsd.port.mk>
