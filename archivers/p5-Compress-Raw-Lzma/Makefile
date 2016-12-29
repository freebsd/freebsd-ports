# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	Compress-Raw-Lzma
PORTVERSION=	2.070
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-Level Interface to lzma compression library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod

OPTIONS_DEFINE=	LZMALIB
LZMALIB_DESC=	Use archivers/lzmalia instead of liblzma in base

USE_PERL5=	configure
USES=		perl5

LZMALIB_LIB_DEPENDS=	liblzma.so.1:archivers/lzmalib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Compress/Raw/Lzma/Lzma.so

.include <bsd.port.mk>
