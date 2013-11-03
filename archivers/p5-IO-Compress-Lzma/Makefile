# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	IO-Compress-Lzma
PORTVERSION=	2.063
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PMQS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write lzma files / buffers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Compress-Raw-Lzma>=2.063:${PORTSDIR}/archivers/p5-Compress-Raw-Lzma \
		p5-IO-Compress>=2.063:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod \
		p7zip>=0:${PORTSDIR}/archivers/p7zip

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
