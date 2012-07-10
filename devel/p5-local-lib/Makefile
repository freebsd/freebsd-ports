# New ports collection makefile for:	local::lib
# Date created:		14 Mar 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	local-lib
PORTVERSION=	1.008004
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:APEIRON
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to create and use a local lib/ with PERL5LIB

TEST_DEPENDS=	p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny

PERL_CONFIGURE=	yes

MAN3=	POD2::DE::local::lib.3 \
	POD2::PT_BR::local::lib.3 \
	lib::core::only.3 \
	local::lib.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-ExtUtils-Install>=1.43:${PORTSDIR}/devel/p5-ExtUtils-Install
.endif

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Module-Build>=0.36:${PORTSDIR}/devel/p5-Module-Build
RUN_DEPENDS+=	p5-Module-Build>=0.36:${PORTSDIR}/devel/p5-Module-Build
.endif

.include <bsd.port.post.mk>
