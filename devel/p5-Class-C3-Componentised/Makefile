# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-C3-Componentised
PORTVERSION=	1.0010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}00

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load mix-ins or components to your C3-based class

RUN_DEPENDS=	p5-Class-C3>=0.20:${PORTSDIR}/devel/p5-Class-C3 \
		p5-MRO-Compat>0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector
BUILD_DEPENDS:=	${RUN_DEPENDS}

TEST_DEPENDS=	p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

post-extract:
	@${REINPLACE_CMD} -i '' -e '/Test::/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
