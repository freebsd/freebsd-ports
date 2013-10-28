# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-C3
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pragma to use the C3 method resolution order algorithm

OPTIONS_DEFINE=	XS
XS_DESC=	XS speed optimizations

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXS}
BUILD_DEPENDS+=	p5-Class-C3-XS>=0.13:${PORTSDIR}/devel/p5-Class-C3-XS
RUN_DEPENDS+=	p5-Class-C3-XS>=0.13:${PORTSDIR}/devel/p5-Class-C3-XS
.else
BUILD_DEPENDS+=	p5-Algorithm-C3>=0.07:${PORTSDIR}/devel/p5-Algorithm-C3
RUN_DEPENDS+=	p5-Algorithm-C3>=0.07:${PORTSDIR}/devel/p5-Algorithm-C3
.endif

.include <bsd.port.mk>
