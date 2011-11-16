# New ports collection makefile for:	p5-Class-Load-XS
# Date created:		2011-11-16
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Load-XS
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS implementation of parts of Class::Load

BUILD_DEPENDS=	p5-Class-Load>=0.11:${PORTSDIR}/devel/p5-Class-Load
RUN_DEPENDS=	p5-Class-Load>=0.11:${PORTSDIR}/devel/p5-Class-Load

PERL_MODBUILD=	yes

MAN3=		Class::Load::XS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
