# Created by: Andrey Kostenko <andrey@kostenko.name>
# $FreeBSD$

PORTNAME=	Archive-SimpleExtractor
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple module for extract archives

BUILD_DEPENDS=	p5-Archive-Rar>=2.02:${PORTSDIR}/archivers/p5-Archive-Rar \
		p5-Archive-Zip>=1.30:${PORTSDIR}/archivers/p5-Archive-Zip
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
