# $FreeBSD$

PORTNAME=	STAR
DISTVERSION=	2.7.3a
PORTREVISION=	1
CATEGORIES=	biology
PKGNAMEPREFIX=	rna-

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Spliced Transcripts Alignment to a Reference

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/STAR-${DISTVERSION}/LICENSE

# 64-bit only, needs 16+ GiB RAM for typical eukaryotic genome
NOT_FOR_ARCHS=	i386 powerpc

USES=		compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	alexdobin

WRKSRC_SUBDIR=	source

PLIST_FILES=	bin/STAR

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/STAR ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
