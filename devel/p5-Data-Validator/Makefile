# New ports collection makefile for:	p5-Data-Validator
# Date created:		2011-08-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Validator
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rule based validator on type constraint system

BUILD_DEPENDS=	p5-Mouse>=0.93:${PORTSDIR}/devel/p5-Mouse
RUN_DEPENDS=	p5-Mouse>=0.93:${PORTSDIR}/devel/p5-Mouse

TEST_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN3=		Data::Validator.3 \
		Data::Validator::Role::AllowExtra.3 \
		Data::Validator::Role::Croak.3 \
		Data::Validator::Role::Method.3 \
		Data::Validator::Role::NoThrow.3 \
		Data::Validator::Role::Sequenced.3 \
		Data::Validator::Role::StrictSequenced.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
