# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	CPAN-Meta
PORTVERSION=	2.132140
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	The distribution metadata for a CPAN dist

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CPAN-Meta-Requirements>=2.121:${PORTSDIR}/devel/p5-CPAN-Meta-Requirements \
		p5-CPAN-Meta-YAML>=0.008:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-Parse-CPAN-Meta>=1.44.03:${PORTSDIR}/devel/p5-Parse-CPAN-Meta
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		CPAN::Meta.3 \
		CPAN::Meta::Converter.3 \
		CPAN::Meta::Feature.3 \
		CPAN::Meta::History.3 \
		CPAN::Meta::Prereqs.3 \
		CPAN::Meta::Spec.3 \
		CPAN::Meta::Validator.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-version>=0.88:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-version>=0.88:${PORTSDIR}/devel/p5-version
.endif

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-JSON-PP>=2.27200:${PORTSDIR}/converters/p5-JSON-PP
RUN_DEPENDS+=	p5-JSON-PP>=2.27200:${PORTSDIR}/converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>
