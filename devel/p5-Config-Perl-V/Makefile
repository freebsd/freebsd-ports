# New ports collection makefile for:	p5-Config-Perl-V
# Date created:		2011-02-05
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#
PORTNAME=	Config-Perl-V
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HMBRAND
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Structured data retrieval of Perl -V output

BUILD_DEPENDS=	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Config::Perl::V.3

.include <bsd.port.mk>
