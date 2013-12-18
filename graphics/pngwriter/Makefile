# Created by: ijliao
# $FreeBSD$

PORTNAME=	pngwriter
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	C++ library for creating PNG images

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

USES=		pkgconfig

WRKSRC=		${WRKDIR}/${DISTNAME}

CXXFLAGS+=	`pkg-config --cflags freetype2 libpng15` -I${LOCALBASE}/include

PLIST_FILES=	include/pngwriter.h \
		lib/libpngwriter.a \
		%%DATADIR%%/fonts/FreeMonoBold.ttf \
		%%DATADIR%%/fonts/FreeSansBold.ttf
PLIST_DIRS=	%%DATADIR%%/fonts \
		%%DATADIR%%

PORTDOCS=	*
PORTEXAMPLES=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${FIND} ${WRKSRC} -name "\.*" -delete

do-build:
	cd ${WRKSRC}/src \
		&& ${CXX} ${CXXFLAGS} -c pngwriter.cc -o pngwriter.o \
		&& ${AR} rv libpngwriter.a pngwriter.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/pngwriter.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/libpngwriter.a ${PREFIX}/lib
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} fonts ${DATADIR})

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
