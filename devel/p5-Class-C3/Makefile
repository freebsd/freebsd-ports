# New ports collection makefile for:	Class-C3
# Date created:	   1 Dec 2005
# Whom:		   Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-C3
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A pragma to use the C3 method resolution order algorithm

OPTIONS=	XS "XS speed optimizations" off

PERL_CONFIGURE=	yes

MAN3=		Class::C3.3 \
		Class::C3::next.3

.include <bsd.port.options.mk>

.ifdef(WITH_XS)
BUILD_DEPENDS+=	p5-Class-C3-XS>=0.13:${PORTSDIR}/devel/p5-Class-C3-XS
RUN_DEPENDS+=	p5-Class-C3-XS>=0.13:${PORTSDIR}/devel/p5-Class-C3-XS
.else
BUILD_DEPENDS+=	p5-Algorithm-C3>=0.07:${PORTSDIR}/devel/p5-Algorithm-C3
RUN_DEPENDS+=	p5-Algorithm-C3>=0.07:${PORTSDIR}/devel/p5-Algorithm-C3
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-ExtUtils-CBuilder>=0.27:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
.endif

.include <bsd.port.post.mk>
