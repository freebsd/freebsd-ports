# New ports collection makefile for:	p5-Date-Chinese
# Date Created:				13 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	Date-Chinese
PORTVERSION=	1.03
CATEGORIES=	chinese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	shell@shellhung.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		Date::Chinese.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

WRKDIST=	${WRKDIR}/Date-Chinese-1.3
WRKSRC=		${WRKDIST}

.include <bsd.port.mk>
