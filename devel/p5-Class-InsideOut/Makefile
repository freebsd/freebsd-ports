# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Class-InsideOut
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Safe, simple inside-out object construction kit

BUILD_DEPENDS=	p5-Class-ISA>=0:${PORTSDIR}/devel/p5-Class-ISA
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:1.0301

USES=		perl5
USE_PERL5=	configure

MAN3=		Class::InsideOut::Manual::About.3 Class::InsideOut.3 \
		Class::InsideOut::Manual::Advanced.3

.include <bsd.port.mk>
