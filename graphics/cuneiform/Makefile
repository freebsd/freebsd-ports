# New ports collection makefile for:	cuneiform
# Date created:				2008/08/23
# Whom:					samm
#
# $FreeBSD$
#

PORTNAME=	cuneiform
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://launchpad.net/cuneiform-linux/${PORTVERSION:R}/${PORTVERSION:R}/+download/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	OCR system developed and open sourced by Cognitive technologies

LIB_DEPENDS=	dlmalloc.2:${PORTSDIR}/devel/libdlmalloc

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DCMAKE_EXE_LINKER_FLAGS="-L${LOCALBASE}/lib -ldlmalloc"
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/build
CMAKE_SOURCE_PATH=..

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	IMAGEMAGICK "Enable support of different graphic formats" off

.include <bsd.port.pre.mk>

.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	MagickWand.2:${PORTSDIR}/graphics/ImageMagick
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
.if !defined(WITH_IMAGEMAGICK)
	@${REINPLACE_CMD} -e '/pkg_check_modules.*ImageMagick/ d' \
		${WRKSRC}/../cuneiform_src/Kern/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
