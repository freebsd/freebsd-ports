# New ports collection makefile for:	devel/p5-Params-Check
# Date created:				15 December 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Params-Check
PORTVERSION=	0.22
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Params
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic input parsing/checking mechanism for Perl

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Params::Check.3

.include <bsd.port.mk>
