# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hdr_tools
PORTVERSION=	0.0.2010.11.23	# unspecified by the author, so use the date
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://ttic.uchicago.edu/~cotter/projects/hdr_tools/archives/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	hdr_src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Command-line tools for creating and manipulating HDR images

LICENSE=	GPLv3

LIB_DEPENDS=	libpopt.so:devel/popt \
		libtiff.so:graphics/tiff \
		libIlmImf.so:graphics/openexr \
		libMagick++-6.so:graphics/ImageMagick6

USES=		compiler:c++11-lang gmake pkgconfig tar:tgz
NO_WRKSUBDIR=	yes

PROGRAMS=	hdr_adjust hdr_convert hdr_create hdr_denoise hdr_fix_ca \
		hdr_squish

PLIST_FILES=	${PROGRAMS:S,^,bin/,}

.include <bsd.port.pre.mk>

.if ${MACHINE_CPU:Msse2}
CXXFLAGS+=	-msse2 -mfpmath=sse
.endif

.if ${COMPILER_FEATURES:Mopenmp}
CXXFLAGS+=	-fopenmp
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,RGBColorspace,s&,' ${WRKSRC}/image.cc

do-install:
	${INSTALL_PROGRAM} ${PROGRAMS:S,^,${WRKSRC}/,} \
		${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.post.mk>
