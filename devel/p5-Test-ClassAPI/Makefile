# New ports collection makefile for:	devel/p5-Test-ClassAPI
# Date created:				24 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-ClassAPI
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Provides basic first-pass API testing for large class trees

BUILD_DEPENDS=	${SITE_PERL}/Class/Inspector.pm:${PORTSDIR}/devel/p5-Class-Inspector \
		${SITE_PERL}/Config/Tiny.pm:${PORTSDIR}/devel/p5-Config-Tiny
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::ClassAPI.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
post-patch:
	@${PERL} -pi -e 's,\r,,' ${WRKSRC}/lib/Test/ClassAPI.pm
.endif
.include <bsd.port.post.mk>
