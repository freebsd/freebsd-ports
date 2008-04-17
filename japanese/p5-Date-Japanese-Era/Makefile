# New ports collection makefile for:   p5-Date-Japanese-Era
# Date created:                7 March 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	Date-Japanese-Era
PORTVERSION=	0.06
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Conversion between Japanese Era / Gregorian calendar

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Lingua/JA/Numbers.pm:${PORTSDIR}/japanese/p5-Lingua-JA-Numbers
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+	# inherited from p5-Lingua-JA-Numbers

MAN3=		Date::Japanese::Era.3 \
		Date::Japanese::Era::Table.3 \
		Date::Japanese::Era::Table::JIS_X0301.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
