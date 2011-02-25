# New ports collection makefile for:	local::lib
# Date created:		14 Mar 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	local-lib
PORTVERSION=	1.008004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/A/AP/APEIRON
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to create and use a local lib/ with PERL5LIB

RUN_DEPENDS=	\
	p5-Module-Build>=0.36:${PORTSDIR}/devel/p5-Module-Build \
	p5-ExtUtils-Install>=1.43:${PORTSDIR}/devel/p5-ExtUtils-Install
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POD2::DE::local::lib.3 \
	POD2::PT_BR::local::lib.3 \
	lib::core::only.3 \
	local::lib.3

.include <bsd.port.mk>
