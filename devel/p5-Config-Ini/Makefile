# New ports collection makefile for:	p5-Config-Ini
# Date created:				17 June 2001
# Whom:					Christopher Elkins <chrise@scardini.com>
#
# $FreeBSD$
#

PORTNAME=	Config-Ini
PORTVERSION=	1.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to MS-Windows registry and .ini files

BUILD_DEPENDS=	${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash

PERL_CONFIGURE=	YES

MAN3=		Config::Ini.3

.include <bsd.port.mk>
