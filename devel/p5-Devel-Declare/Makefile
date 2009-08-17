# New ports collection makefile for:	Devel-Declare
# Date created:	   16 Aug 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Devel-Declare
PORTVERSION=	0.005011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Adding keywords to perl, in perl

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Sub/Name.pm:${PORTSDIR}/devel/p5-Sub-Name \
		p5-B-Hooks-EndOfScope>=0.05:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-B-Hooks-OP-Check>=0.18:${PORTSDIR}/devel/p5-B-Hooks-OP-Check
BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=		Devel::Declare.3

.include <bsd.port.mk>
