# New ports collection makefile for:	dns/p5-BIND-Config-Parser
# Date created:				05 May 2010
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	BIND-Config-Parser
PORTVERSION=	0.01
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN/../../authors/id/M/MA/MATTD
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse BIND Config files

BUILD_DEPENDS=	${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	BIND::Config::Parser.3

.include <bsd.port.mk>
