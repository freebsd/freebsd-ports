# New ports collection makefile for:	Class-C3
# Date created:	   1 Dec 2005
# Whom:		   Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-C3
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	A pragma to use the C3 method resolution order algorithm

OPTIONS=	XS "XS speed optimizations" off

.include <bsd.port.pre.mk>

.ifdef(WITH_XS)
RUN_DEPENDS=	p5-Class-C3-XS>=0.07:${PORTSDIR}/devel/p5-Class-C3-XS
.else
RUN_DEPENDS=	p5-Algorithm-C3>=0.06:${PORTSDIR}/devel/p5-Algorithm-C3
.endif
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::C3.3 \
		Class::C3::next.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^if, .. m,}$$,' ${WRKSRC}/Makefile.PL

.if ${PERL_LEVEL} < 500800	# Inherited from devel/p5-Algorithm-C3
IGNORE=		requires perl 5.8.x or later, install lang/perl5.8
.endif

.include <bsd.port.post.mk>
