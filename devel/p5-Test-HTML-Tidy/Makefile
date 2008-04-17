# New ports collection makefile for:	p5-Test-HTML-Tidy
# Date created:				Sep 13 2006
# Whom:	      				rafan@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Test-HTML-Tidy
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Test::More-style wrapper around HTML::Tidy

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Tidy.pm:${PORTSDIR}/textproc/p5-HTML-Tidy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::HTML::Tidy.3

.include <bsd.port.mk>
