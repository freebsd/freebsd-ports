# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Parse-CPAN-Meta
PORTVERSION=	1.44.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse META.yml and other similar CPAN metadata files

BUILD_DEPENDS=	p5-CPAN-Meta-YAML>=0.008:${PORTSDIR}/devel/p5-CPAN-Meta-YAML
RUN_DEPENDS=	p5-CPAN-Meta-YAML>=0.008:${PORTSDIR}/devel/p5-CPAN-Meta-YAML

USES=		perl5
USE_PERL5=	configure

MAN3=		Parse::CPAN::Meta.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-JSON-PP>=2.27200:${PORTSDIR}/converters/p5-JSON-PP
RUN_DEPENDS+=	p5-JSON-PP>=2.27200:${PORTSDIR}/converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>
