# New ports collection makefile for:	devel/p5-Parse-CPAN-Meta
# Date created:				26 February 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Parse-CPAN-Meta
PORTVERSION=	1.44.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse META.yml and other similar CPAN metadata files

PERL_CONFIGURE=	yes

MAN3=		Parse::CPAN::Meta.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-CPAN-Meta-YAML>=0.002:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-JSON-PP>=2.27103:${PORTSDIR}/converters/p5-JSON-PP
RUN_DEPENDS+=	p5-CPAN-Meta-YAML>=0.002:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-JSON-PP>=2.27103:${PORTSDIR}/converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>
