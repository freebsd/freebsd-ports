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

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Config::Ini.3

.include <bsd.port.mk>
