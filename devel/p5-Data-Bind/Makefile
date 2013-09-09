# Created by: Ying-Chieh Chen
# $FreeBSD$

PORTNAME=	Data-Bind
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A perl module to bind and alias variables

BUILD_DEPENDS=	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor	\
		p5-Devel-Caller>0:${PORTSDIR}/devel/p5-Devel-Caller \
		p5-Devel-LexAlias>0:${PORTSDIR}/devel/p5-Devel-LexAlias \
		p5-Data-Capture>0:${PORTSDIR}/devel/p5-Data-Capture
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

MAN3=		Data::Bind.3

.include <bsd.port.mk>
