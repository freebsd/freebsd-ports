# New ports collection makefile for:	Inline::CPP
# Date created:		14 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Inline-CPP
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Inline
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Write Perl subroutines and classes in C++

BUILD_DEPENDS=	${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	</dev/null

MAN3=		Inline::CPP.3

.include <bsd.port.mk>
