# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-Accessor-Lvalue
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Create Lvalue accessors

BUILD_DEPENDS=	p5-Want>=0:${PORTSDIR}/devel/p5-Want \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Class::Accessor::Lvalue.3 \
		Class::Accessor::Lvalue::Fast.3

NO_STAGE=	yes
.include <bsd.port.mk>
