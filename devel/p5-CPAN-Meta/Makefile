# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	CPAN-Meta
PORTVERSION=	2.142060
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	The distribution metadata for a CPAN dist

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-JSON-PP>=2.27200:${PORTSDIR}/converters/p5-JSON-PP
RUN_DEPENDS+=	p5-JSON-PP>=2.27200:${PORTSDIR}/converters/p5-JSON-PP
.endif

.if ${PERL_LEVEL} < 501800
BUILD_DEPENDS+=	p5-CPAN-Meta-Requirements>=2.121:${PORTSDIR}/devel/p5-CPAN-Meta-Requirements \
		p5-CPAN-Meta-YAML>=0.008:${PORTSDIR}/devel/p5-CPAN-Meta-YAML
RUN_DEPENDS+=	p5-CPAN-Meta-Requirements>=2.121:${PORTSDIR}/devel/p5-CPAN-Meta-Requirements \
		p5-CPAN-Meta-YAML>=0.008:${PORTSDIR}/devel/p5-CPAN-Meta-YAML
.endif

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Parse-CPAN-Meta>=1.44.14:${PORTSDIR}/devel/p5-Parse-CPAN-Meta
RUN_DEPENDS+=	p5-Parse-CPAN-Meta>=1.44.14:${PORTSDIR}/devel/p5-Parse-CPAN-Meta
.endif

.include <bsd.port.post.mk>
