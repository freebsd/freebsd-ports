# ex:ts=8
# New ports collection makefile for:	p5-Exception-Class
# Date created:			Jul 28, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Exception-Class
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Exception
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	A module that allows you to declare real exception classes in Perl

BUILD_DEPENDS=	${SITE_PERL}/Devel/StackTrace.pm:${PORTSDIR}/devel/p5-Devel-StackTrace \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Exception::Class.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
