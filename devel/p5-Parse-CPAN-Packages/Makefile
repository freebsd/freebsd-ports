# New ports collection makefile for:	devel/p5-Parse-CPAN-Packages
# Date created:				Mar 27 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Parse-CPAN-Packages
PORTVERSION=	2.25
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Parse
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse 02packages.details.txt.gz from CPAN

BUILD_DEPENDS=	${SITE_PERL}/Sort/Versions.pm:${PORTSDIR}/devel/p5-Sort-Versions \
		${SITE_PERL}/CPAN/DistnameInfo.pm:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/IO/Zlib.pm:${PORTSDIR}/archivers/p5-IO-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Parse::CPAN::Packages.3

.include <bsd.port.mk>
