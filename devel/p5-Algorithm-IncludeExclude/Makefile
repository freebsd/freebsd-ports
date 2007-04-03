# New ports collection makefile for:	devel/p5-Algorithm-IncludeExclude
# Date created:				03 April 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-IncludeExclude
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Build and evaluate include/exclude lists

BUILD_DEPENDS=	${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Algorithm::IncludeExclude.3

.include <bsd.port.mk>
