# New ports collection makefile for:	devel/p5-Test-JSON
# Date created:				26 April 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-JSON
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${DISTVERSION:C/0$//}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Test JSON data

RUN_DEPENDS=	p5-Test-Differences>=0.47:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Simple>=0.62:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Tester>=0.10.3:${PORTSDIR}/devel/p5-Test-Tester \
		p5-JSON-Any>=1.20:${PORTSDIR}/converters/p5-JSON-Any
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::JSON.3

.include <bsd.port.mk>
