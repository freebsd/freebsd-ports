# New ports collection makefile for:	p5-Test-BinaryData
# Date created:		2011-12-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-BinaryData
PORTVERSION=	0.013
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compare two things, give hex dumps if they differ

TEST_DEPENDS=	p5-Test-Tester>=0.10.7:${PORTSDIR}/devel/p5-Test-Tester

USE_PERL5=	configure
USES=		perl5

MAN3=		Test::BinaryData.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
