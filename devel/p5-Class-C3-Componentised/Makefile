# New ports collection makefile for:	Class-C3-Componentised
# Date created:	   2007-08-13
# Whom:		   Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-C3-Componentised
PORTVERSION=	1.0008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RI/RIBASUSHI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load mix-ins or components to your C3-based class

RUN_DEPENDS=	p5-Class-C3>=0.20:${PORTSDIR}/devel/p5-Class-C3 \
		p5-MRO-Compat>0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector
BUILD_DEPENDS=	${RUN_DEPENDS}

TEST_DEPENDS=	p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
	p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
	p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	5.8.0+	# Inherited from devel/p5-Algorithm-C3-Componentised

MAN3=		Class::C3::Componentised.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,Test::,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
