# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Bio-NEXUS
PORTVERSION=	0.78
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object-oriented Perl API for the NEXUS file format

BUILD_DEPENDS=	p5-Clone-PP>=1.02:${PORTSDIR}/devel/p5-Clone-PP
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Deep>=0.106:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
