# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	gle-graphics
DISTVERSION=	4.2.4cf
PORTREVISION=	6
CATEGORIES=	graphics print
MASTER_SITES=	SF/glx/gle4%20%28Current%20Active%20Version%29/${DISTVERSION:C,.$,,1}
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Graphics language that produces images from script files

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	qmake-qt4:devel/qmake4

BITMAP_IMAGES_CONFIGURE_WITH=	jpeg=${LOCALBASE} tiff=${LOCALBASE} png=${LOCALBASE}
BITMAP_IMAGES_DESC=	Support for including bitmap images
BITMAP_IMAGES_LIB_DEPENDS=	libpng.so:graphics/png \
		libtiffxx.so:graphics/tiff
BITMAP_IMAGES_USES=	jpeg

CONFIGURE_ARGS=	--with-extrafonts=yes

ALL_TARGET=	all

DOCS_ALL_TARGET=	doc
DOCS_USE=	tex=latex:build tex=dvipsk:build

GNU_CONFIGURE=	yes

LATEX_GS_DESC=	Use LaTeX & GhostScript
LATEX_GS_USE=	tex=latex
LATEX_GS_USES=	ghostscript

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS BITMAP_IMAGES LATEX_GS X11
OPTIONS_DEFAULT=	BITMAP_IMAGES LATEX_GS X11

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

REINPLACE_FILES=	configure

USE_GCC=	yes
USE_GL=	yes
USE_LDCONFIG=	yes
USE_QT4=	gui moc network opengl rcc
USES=		gmake ncurses pathfix
CPPFLAGS+=	-I${NCURSESINC}

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

X11_CONFIGURE_WITH=	x
X11_USE=	xorg=x11

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -E -e 's,k(freebsd),\1,1' ${REINPLACE_FILES}

.include <bsd.port.mk>
