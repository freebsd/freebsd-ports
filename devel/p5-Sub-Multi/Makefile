# Created by: ijliao
# $FreeBSD$

PORTNAME=	Sub-Multi
PORTVERSION=	0.003
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Data::Bind-based multi-sub dispatch

BUILD_DEPENDS=	p5-Class-Multimethods-Pure>=0.11:devel/p5-Class-Multimethods-Pure \
		p5-Data-Bind>=0.26:devel/p5-Data-Bind
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
