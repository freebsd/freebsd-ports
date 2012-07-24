# New ports collection makefile for:	p5-uni-perl
# Date created:		2009-10-20
# Whom:			Mons Anderson <mons@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	uni-perl
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MONS
PKGNAMEPREFIX=	p5-

MAINTAINER=	mons@cpan.org
COMMENT=	Modern perl with Unicode

RUN_DEPENDS=	p5-Encode>=2.37:${PORTSDIR}/converters/p5-Encode \
		p5-lib-abs>=0.90:${PORTSDIR}/devel/p5-lib-abs
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

PERL_CONFIGURE=	5.10.0+

MAN3=	uni::perl.3

.include <bsd.port.mk>
