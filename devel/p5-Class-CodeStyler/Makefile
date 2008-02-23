# New ports collection makefile for:	p5-Class-CodeStyler
# Date created:				12 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-CodeStyler
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Perl extension for code generation program formatting and execution

BUILD_DEPENDS=	${SITE_PERL}/Class/STL/Containers.pm:${PORTSDIR}/devel/p5-Class-STL-Containers
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.7+

.include <bsd.port.mk>
