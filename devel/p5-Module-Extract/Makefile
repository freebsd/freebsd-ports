# New ports collection makefile for:	p5-Module-Extract
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Module-Extract
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Base class for working with Perl distributions

BUILD_DEPENDS=	${SITE_PERL}/Archive/Extract.pm:${PORTSDIR}/archivers/p5-Archive-Extract
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Module::Extract.3

.include <bsd.port.mk>
