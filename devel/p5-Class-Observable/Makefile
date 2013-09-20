# Created by: Travis Campbell <hcoyote@ghostar.org>
# $FreeBSD$

PORTNAME=	Class-Observable
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hcoyote@ghostar.org
COMMENT=	Allow other classes and objects to respond to events in yours

BUILD_DEPENDS=	p5-Class-ISA>=0:${PORTSDIR}/devel/p5-Class-ISA
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Class::Observable.3

NO_STAGE=	yes
.include <bsd.port.mk>
