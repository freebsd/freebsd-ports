# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO-Compress
PORTVERSION=	2.070
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 compression modules (bzip2, deflate, gzip, zlib, zip)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Compress-Raw-Bzip2>=${PORTVERSION}:archivers/p5-Compress-Raw-Bzip2 \
		p5-Compress-Raw-Zlib>=${PORTVERSION}:archivers/p5-Compress-Raw-Zlib
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod

CONFLICTS_INSTALL=	p5-Compress-Zlib-2* p5-IO-Compress-Base-2* p5-IO-Compress-Zlib-2* p5-IO-Compress-Bzip2-2*

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
