# New ports collection makefile for:   p5-Date-Japanese-Era
# Date created:                7 March 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	Date-Japanese-Era
PORTVERSION=	0.03
CATEGORIES=	japanese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date

MAINTAINER=	fuyuki@mj.0038.net

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc

PERL_CONFIGURE=	yes

MAN3=		Date::Japanese::Era.3 \
		Date::Japanese::Era.ja.3 \
		Date::Japanese::Era::Table.3 \
		Date::Japanese::Era::Table::JIS_X0301.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
