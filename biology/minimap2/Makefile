# $FreeBSD$

PORTNAME=		minimap2
DISTVERSIONPREFIX=	v
DISTVERSION=		2.16
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Pairwise aligner for genomic and spliced nucleotide sequences

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# Depends on hard-coded SSE instructions
# There appears to be some support for AARCH64 as well
ONLY_FOR_ARCHS=	amd64 i386

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	lh3

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/minimap2 man/man1/minimap2.1.gz

.include <bsd.port.mk>
