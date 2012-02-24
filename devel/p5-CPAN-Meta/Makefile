# New ports collection makefile for:	p5-CPAN-Meta
# Date created:				April 20 2010
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	CPAN-Meta
PORTVERSION=	2.120530
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	The distribution metadata for a CPAN dist

PERL_CONFIGURE=	yes

MAN3=		CPAN::Meta.3 \
		CPAN::Meta::Converter.3 \
		CPAN::Meta::Feature.3 \
		CPAN::Meta::History.3 \
		CPAN::Meta::Prereqs.3 \
		CPAN::Meta::Requirements.3 \
		CPAN::Meta::Spec.3 \
		CPAN::Meta::Validator.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-version>=0.82:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-version>=0.82:${PORTSDIR}/devel/p5-version
.endif

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-CPAN-Meta-YAML>=0.002:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-JSON-PP>=2.27103:${PORTSDIR}/converters/p5-JSON-PP \
		p5-Parse-CPAN-Meta>=1.44:${PORTSDIR}/devel/p5-Parse-CPAN-Meta
RUN_DEPENDS+=	p5-CPAN-Meta-YAML>=0.002:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-JSON-PP>=2.27103:${PORTSDIR}/converters/p5-JSON-PP \
		p5-Parse-CPAN-Meta>=1.44:${PORTSDIR}/devel/p5-Parse-CPAN-Meta
.endif

.include <bsd.port.post.mk>
