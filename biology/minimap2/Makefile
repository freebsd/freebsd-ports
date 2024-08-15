PORTNAME=		minimap2
DISTVERSIONPREFIX=	v
DISTVERSION=		2.28
PORTREVISION=		1
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Pairwise aligner for genomic and spliced nucleotide sequences
WWW=		https://github.com/lh3/minimap2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NOT_FOR_ARCHS=		i386 mips powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	Requires 64-bit processor, except ARM NEON

BUILD_DEPENDS=	simde>0:devel/simde

USES=		gmake localbase
USE_GITHUB=	yes

GH_ACCOUNT=	lh3

ALL_TARGET=	extra
INSTALL_TARGET=	install-strip

MAKEFILE=	Makefile.simde
MAKE_ARGS=	MAN1DIR=${PREFIX}/share/man/man1

pre-build:
	${REINPLACE_CMD} -e 's|-msse4.1||g' -e 's|-msse2||g' ${WRKSRC}/Makefile.simde

.include <bsd.port.mk>
