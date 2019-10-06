# $FreeBSD$

PORTNAME=	STAR
DISTVERSION=	2.7.2d
CATEGORIES=	biology
PKGNAMEPREFIX=	rna-

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Spliced Transcripts Alignment to a Reference

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/STAR-${DISTVERSION}/LICENSE

# 64-bit only, needs 16+ GiB RAM for typical eukaryotic genome
NOT_FOR_ARCHS=	i386 powerpc

USES=		compiler:openmp gmake
USE_GITHUB=	yes
GH_ACCOUNT=	alexdobin

WRKSRC_SUBDIR=	source

PLIST_FILES=	bin/STAR

.include <bsd.port.pre.mk>

# Force newer compiler on platforms using GCC 4.2 as base
.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
USE_GCC=	yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/STAR ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
