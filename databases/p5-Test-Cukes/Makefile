# New ports collection makefile for: 	p5-Test-Cukes
# Date created:				26 Aug, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Test-Cukes
PORTVERSION=	0.08
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	A BBD test tool inspired by Cucumber

BUILD_DEPENDS=	p5-Any-Moose>=0.10:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Carp-Assert>=0.20:${PORTSDIR}/devel/p5-Carp-Assert \
		p5-Exporter-Lite>=0.02:${PORTSDIR}/devel/p5-Exporter-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Cukes.3

.include <bsd.port.mk>
