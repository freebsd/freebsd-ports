# New ports collection makefile for:	p5-Date-Japanese-Holiday
# Date created:		Mar 29, 2005
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Date-Japanese-Holiday
PORTVERSION=	0.05
CATEGORIES=	japanese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for Calculate Japanese Holiday

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/${PERL_ARCH}/Date/Simple.pm:${PORTSDIR}/devel/p5-Date-Simple \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Time/JulianDay.pm:${PORTSDIR}/devel/p5-Time-modules

PERL_CONFIGURE=	YES

MAN3=		Date::Japanese::Holiday.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
