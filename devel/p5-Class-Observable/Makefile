# New ports collection makefile for:	Class-Observable
# Date created:	   11 Aug 2004
# Whom:		  Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Observable
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	hcoyote@ghostar.org
COMMENT=	Allow other classes and objects to respond to events in yours

BUILD_DEPENDS=	${SITE_PERL}/Class/ISA.pm:${PORTSDIR}/devel/p5-Class-ISA
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Observable.3

.include <bsd.port.mk>
