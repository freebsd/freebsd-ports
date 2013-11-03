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

.include <bsd.port.pre.mk>

.if (${ARCH} == "sparc64")
LZMA_DEPEND=	xz
.endif

.if (${OSVERSION} > 900012) || ((${OSVERSION} > 800505) && (${OSVERSION} < 900000))
LZMA_DEPEND?=	sys
.else
LZMA_DEPEND?=	xz
.endif

.if (${LZMA_DEPEND} == "xz") || (${LZMA_DEPEND} == "lzmalib")
LIB_DEPENDS+=	lzma:${PORTSDIR}/archivers/${LZMA_DEPEND}
.endif

pre-build:
.if ${LZMA_DEPEND} == "sys"
	@${REINPLACE_CMD} -e "/^LDDLFLAGS/ s|${LOCALBASE}/lib|${LIBDIR}|" ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
