# New ports collection makefile for:	p5-Config-GitLike
# Date created:		2011-02-07
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Config-GitLike
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SPANG
PKGNAMEPREFIX=	p5-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Simple git-compatible config file parser for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	devel/p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose

RUN_DEPENDS:=	${BUILD_DEPENDS}

# for tests
BUILD_DEPENDS+=	devel/p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

MAN3+=		Config::GitLike::Git.3 \
		Config::GitLike::Cascaded.3 \
		Config::GitLike.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
