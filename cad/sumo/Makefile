# $FreeBSD$

PORTNAME=	sumo
DISTVERSION=	0.31.0
CATEGORIES=	cad
MASTER_SITES=	http://www.dlr.de/ts/en/Portaldata/16/Resources/projekte/sumo/
DISTFILES=	${PORTNAME}-src-${DISTVERSIONFULL}${EXTRACT_SUFX}

MAINTAINER=	enriquefynn@gmail.com
COMMENT=	Traffic simulation suite for road vehicles, public transportation, etc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libFOX-1.6.so:x11-toolkits/fox16 \
		libfreetype.so:print/freetype2 \
		libgdal.so:graphics/gdal \
		libpng.so:graphics/png \
		libproj.so:graphics/proj \
		libtiff.so:graphics/tiff \
		libxerces-c.so:textproc/xerces-c3

USES=		jpeg zip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-proj-gdal=${LOCALBASE} \
		--with-xerces-libraries=${LOCALBASE}/lib \
		--disable-debug
USE_GL=		gl glu
USE_XORG=	x11 xcursor xext xfixes xft xi xrandr xrender

OPTIONS_DEFINE=	DOCS # the GUI option is possible (--without-fox-config), but it is broken, and it doesn't seem important to have. https://github.com/DLR-TS/sumo/issues/3655

DOCS_DISTFILES=	${PORTNAME}-doc-${DISTVERSION}${EXTRACT_SUFX}
DOCS_USES=	shebangfix
DOCS_VARS=	SHEBANG_FILES=docs/tutorial/*/*.py

PORTDOCS=	*

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${FIND} ${STAGEDIR}${DOCSDIR} -d -empty -delete

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
BUILD_DEPENDS+=	clang40:devel/llvm40
CC=		clang40
CXX=		clang++40 # fails to build with the default compiler on 10
.endif

.include <bsd.port.post.mk>
