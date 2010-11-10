# New ports collection makefile for:	p5-Compress-Raw-Lzma
# Date created:		2010-07-26
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	Compress-Raw-Lzma
PORTVERSION=	2.031
PORTREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-Level Interface to lzma compression library

PERL_CONFIGURE=	yes

MAN3=		Compress::Raw::Lzma.3

.include <bsd.port.pre.mk>

.if (${OSVERSION} > 900012) || ((${OSVERSION} > 800505) && (${OSVERSION} < 900000))
LZMA_DEPEND?=	sys
.else
LZMA_DEPEND?=	xz
.endif

.if (${LZMA_DEPEND} == "xz") || (${LZMA_DEPEND} == "lzmalib")
LIB_DEPENDS=	lzma:${PORTSDIR}/archivers/${LZMA_DEPEND}
.endif

pre-build:
.if ${LZMA_DEPEND} == "sys"
	${REINPLACE_CMD} -e "/^LDDLFLAGS/ s|${LOCALBASE}/lib|/usr/lib|" ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
