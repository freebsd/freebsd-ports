# New ports collection makefile for:	Test::mysqld
# Date created:		31 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-mysqld
PORTVERSION=	0.14
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for mysqld test runner

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
	p5-Test-SharedFork>=0.06:${PORTSDIR}/devel/p5-Test-SharedFork
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::mysqld.3

.include <bsd.port.mk>
