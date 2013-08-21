# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Validator
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rule based validator on type constraint system

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mouse>=0.93:${PORTSDIR}/devel/p5-Mouse
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

USE_PERL5=	modbuild
USES=		perl5

MAN3=		Data::Validator.3 \
		Data::Validator::Role::AllowExtra.3 \
		Data::Validator::Role::Croak.3 \
		Data::Validator::Role::Method.3 \
		Data::Validator::Role::NoRestricted.3 \
		Data::Validator::Role::NoThrow.3 \
		Data::Validator::Role::Sequenced.3 \
		Data::Validator::Role::StrictSequenced.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-CPAN-Meta>=0:${PORTSDIR}/devel/p5-CPAN-Meta
RUN_DEPENDS+=	p5-CPAN-Meta>=0:${PORTSDIR}/devel/p5-CPAN-Meta
.endif

.include <bsd.port.post.mk>
