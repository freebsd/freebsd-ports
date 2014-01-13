# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	Compress-Raw-Lzma
PORTVERSION=	2.063
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PMQS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-Level Interface to lzma compression library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

USE_PERL5=	configure
USES=		perl5

LZMA_DEPEND?=	sys

.if ${LZMA_DEPEND} == "lzmalib"
LIB_DEPENDS+=	liblzma.so.1:${PORTSDIR}/archivers/lzmalib
.endif

pre-build:
.if ${LZMA_DEPEND} == "sys"
	@${REINPLACE_CMD} -e "/^LDDLFLAGS/ s|${LOCALBASE}/lib|${LIBDIR}|" ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
