# New ports collection makefile for:	Getargs::Long
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Getargs-Long
PORTVERSION=	0.1.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Getargs
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Parse routine arguments

BUILD_DEPENDS=	${SITE_PERL}/Log/Agent.pm:${PORTSDIR}/devel/p5-Log-Agent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Getargs::Long.3

.include <bsd.port.mk>
