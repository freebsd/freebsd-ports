# New ports collection makefile for:    p5-Test-Deep
# Date created:				May 12th 2004
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-Deep
PORTVERSION=	0.108
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test data structures for differences deeply

RUN_DEPENDS=	p5-Test-NoWarnings>=0.02:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Tester>=0.04:${PORTSDIR}/devel/p5-Test-Tester
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Deep.3 Test::Deep::NoTest.3

post-patch:
	${REINPLACE_CMD} -e '/return (/s/;/);/' ${WRKSRC}/lib/Test/Deep/RegexpOnly.pm
	${RM} ${WRKSRC}/lib/Test/Deep/RegexpOnly.pm.bak

.include <bsd.port.mk>
