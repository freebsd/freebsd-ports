# New ports collection makefile for:	p5-Config-IniHash
# Date created:		2006-08-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Config-IniHash
PORTVERSION=	2.8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl extension for reading and writing INI files

RUN_DEPENDS=	${SITE_PERL}/Hash/Case.pm:${PORTSDIR}/devel/p5-Hash-Case \
		${SITE_PERL}/Hash/WithDefaults.pm:${PORTSDIR}/devel/p5-Hash-WithDefaults

PERL_CONFIGURE=	yes

MAN3=		Config::IniHash.3

.include <bsd.port.mk>
