# New ports collection makefile for:	ExtUtils-MakeMaker-Coverage
# Date created:	   30 September 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-MakeMaker-Coverage
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Add a Makefile target to determine test coverage using Devel::Cover

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Devel/Cover.pm:${PORTSDIR}/devel/p5-Devel-Cover \
		${SITE_PERL}/Object/Accessor.pm:${PORTSDIR}/devel/p5-Object-Accessor \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::MakeMaker::Coverage.3

.include <bsd.port.mk>
