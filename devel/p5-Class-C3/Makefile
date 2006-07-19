# New ports collection makefile for:	Class-C3
# Date created:	   1 Dec 2005
# Whom:		   Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-C3
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	A pragma to use the C3 method resolution order algorithm

BUILD_DEPENDS=	p5-Algorithm-C3>=0.01:${PORTSDIR}/devel/p5-Algorithm-C3
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::C3.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,Test::,' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800	# Inherited from devel/p5-Algorithm-C3
IGNORE=		requires perl 5.8.x or later, install lang/perl5.8
.endif

.include <bsd.port.post.mk>
