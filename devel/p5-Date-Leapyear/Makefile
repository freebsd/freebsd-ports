# ex:ts=8
# New ports collection makefile for:	p5-Date-Leapyear
# Date created:			Jul 11, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Date-Leapyear
PORTVERSION=	1.71
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module to determine if a particular year a leap year

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Date::Leapyear.3

.include <bsd.port.mk>
