# ex:ts=8
# New ports collection makefile for:	p5-Devel-StackTrace
# Date created:			Jul 28, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Devel-StackTrace
PORTVERSION=	1.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Stack trace and stack trace frame objects

PERL_MODBUILD=	yes

MAN3=		Devel::StackTrace.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
