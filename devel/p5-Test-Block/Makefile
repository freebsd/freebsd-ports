# New ports collection makefile for:	devel/p5-Test-Block
# Date created:				16 April 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Block
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Specify fine granularity test plans
DEPRECATED=	Marked as depreciated upstream

BUILD_DEPENDS=	p5-Test-Exception>=0.15:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Simple>=0.47:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Test::Block.3

.include <bsd.port.mk>
