# New ports collection makefile for:	ExtUtils::XSBuilder
# Date created:				11 Sep 2003
# Whom:                			vanilla
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-XSBuilder
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Autogenerating XS-glue Code

RUN_DEPENDS=	${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLDIRS=site

MAN3=		ExtUtils::XSBuilder.3 ExtUtils::xsbuilder.osc2002.3

.include <bsd.port.mk>
