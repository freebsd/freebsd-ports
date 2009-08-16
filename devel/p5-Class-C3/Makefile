# New ports collection makefile for:	Class-C3
# Date created:	   1 Dec 2005
# Whom:		   Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-C3
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A pragma to use the C3 method resolution order algorithm

OPTIONS=	XS "XS speed optimizations" off

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.pre.mk>

.ifdef(WITH_XS)
RUN_DEPENDS=	p5-Class-C3-XS>=0.07:${PORTSDIR}/devel/p5-Class-C3-XS
.else
RUN_DEPENDS=	p5-Algorithm-C3>=0.06:${PORTSDIR}/devel/p5-Algorithm-C3
.endif
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=		Class::C3.3 \
		Class::C3::next.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^if, .. m,}$$,' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
