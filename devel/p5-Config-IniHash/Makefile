# New ports collection makefile for:	p5-Config-IniHash
# Date created:		2006-08-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Config-IniHash
PORTVERSION=	2.9.0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/J/JE/JENDA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for reading and writing INI files

RUN_DEPENDS=	${SITE_PERL}/Hash/Case.pm:${PORTSDIR}/devel/p5-Hash-Case \
		${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Hash/WithDefaults.pm:${PORTSDIR}/devel/p5-Hash-WithDefaults
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Config::IniHash.3

.include <bsd.port.mk>
