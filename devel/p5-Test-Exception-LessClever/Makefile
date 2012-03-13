# New ports collection makefile for:	p5-Test-Exception-LessClever
# Date created:		2011-10-04
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Exception-LessClever
PORTVERSION=	0.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test::Exception simplified

BUILD_DEPENDS=	p5-Mock-Quick>=1.100:${PORTSDIR}/devel/p5-Mock-Quick
RUN_DEPENDS=	p5-Mock-Quick>=1.100:${PORTSDIR}/devel/p5-Mock-Quick

PERL_MODBUILD=	yes

MAN3=		Test::Exception::LessClever.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
