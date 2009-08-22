# ex:ts=8
# Ports collection makefile for:	pngwriter
# Date created:			Nov 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pngwriter
PORTVERSION=	0.5.4
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library for creating PNG images

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src

USE_GNOME=	pkgconfig
CXXFLAGS+=	`pkg-config --cflags freetype2 libpng12` -I${LOCALBASE}/include

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	include/pngwriter.h \
		lib/libpngwriter.a \
		%%DATADIR%%/fonts/FreeMonoBold.ttf \
		%%DATADIR%%/fonts/FreeSansBold.ttf
PLIST_DIRS=	%%DATADIR%%/fonts \
		%%DATADIR%%

post-extract:
	@${FIND} ${WRKSRC} -name "\.*" -delete

do-build:
	cd ${BUILD_WRKSRC} \
		&& ${CXX} ${CXXFLAGS} -c pngwriter.cc -o pngwriter.o \
		&& ${AR} rv libpngwriter.a pngwriter.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/pngwriter.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/libpngwriter.a ${PREFIX}/lib
	@${MKDIR} ${DATADIR}/fonts
	@(cd ${WRKSRC}/fonts && ${COPYTREE_SHARE} . ${DATADIR}/fonts)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
