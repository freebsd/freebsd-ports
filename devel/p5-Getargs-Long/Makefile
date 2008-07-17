# New ports collection makefile for:	Getargs::Long
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Getargs-Long
PORTVERSION=	1.1003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Parse routine arguments

BUILD_DEPENDS=	p5-Log-Agent>=0.105:${PORTSDIR}/devel/p5-Log-Agent \
		${SITE_PERL}/Module/Install.pm:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS=	p5-Log-Agent>=0.105:${PORTSDIR}/devel/p5-Log-Agent

PERL_CONFIGURE=	yes

MAN3=	Getargs::Long.3

.include <bsd.port.mk>
