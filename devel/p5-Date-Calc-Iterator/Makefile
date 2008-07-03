# New ports collection makefile for:	Date-Calc-Iterator
# Date created:	   03 Jul 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Date-Calc-Iterator
PORTVERSION=	1.00
CATEGORIES=	devel net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Iterate over a range of dates

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Date::Calc::Iterator.3

.include <bsd.port.mk>
