# New ports collection makefile for:	p5-Attribute-Handlers-Prospective
# Date created:				5 Jan 2004
# Whom:					Mathieu Arnold <mat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		Attribute-Handlers-Prospective
PORTVERSION=		0.01
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Attribute
PKGNAMEPREFIX=		p5-

MAINTAINER=		mat@FreeBSD.org
COMMENT=		Richer semantics for attribute handlers

BUILD_DEPENDS=		${SITE_PERL}/Filter/Simple.pm:${PORTSDIR}/textproc/p5-Filter-Simple \
			${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced
RUN_DEPENDS=		${BUILD_DEPENDS}

PERL_CONFIGURE=		yes

MAN3=			Attribute::Handlers::Prospective.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		Need perl 5.6.1, try installing lang/perl5
.endif

.include <bsd.port.post.mk>
