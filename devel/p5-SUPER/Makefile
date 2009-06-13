# New ports collection makefile for:	devel/p5-SUPER
# Date created:				12 June, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	SUPER
PORTVERSION=	1.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Perl module control superclass method dispatch

BUILD_DEPENDS=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Sub-Identify>=0.04:${PORTSDIR}/devel/p5-Sub-Identify
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	SUPER.3

.include <bsd.port.mk>
