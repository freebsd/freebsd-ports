# New ports collection makefile for:	p5-CPAN-Meta
# Date created:				April 20 2010
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	CPAN-Meta
PORTVERSION=	2.101410
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jupengfei@gmail.com
COMMENT=	The distribution metadata for a CPAN dist

BUILD_DEPENDS=	p5-autodie>0:${PORTSDIR}/devel/p5-autodie	\
		p5-JSON>=2:${PORTSDIR}/converters/p5-JSON	\
		p5-Parse-CPAN-Meta>0:${PORTSDIR}/devel/p5-Parse-CPAN-Meta	\
		p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple		\
		p5-Version-Requirements>0:${PORTSDIR}/devel/p5-Version-Requirements
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		CPAN::Meta.3		\
		CPAN::Meta::Converter.3	\
		CPAN::Meta::Feature.3	\
		CPAN::Meta::History.3	\
		CPAN::Meta::Prereqs.3	\
		CPAN::Meta::Spec.3	\
		CPAN::Meta::Validator.3

.include <bsd.port.mk>
