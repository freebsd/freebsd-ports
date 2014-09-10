# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	quat
PORTVERSION=	1.20
PORTREVISION=	14
CATEGORIES=	graphics
#MASTER_SITES=	http://www.physcip.uni-stuttgart.de/phy11733/download/
MASTER_SITES=	http://www.sourcefiles.org/Graphics/Fractals/
PKGNAMESUFFIX=	-gui

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Three-dimensional fractal creator (X11 GUI)

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

USE_XORG=	xext
USE_GL=		gl glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLUID="${LOCALBASE}/bin/fluid"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/doc

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

PORTDOCS=	*
PLIST_FILES=	bin/quat

DESKTOP_ENTRIES="Quat" "3D Fractal Generator" "" "${PORTNAME}" "" ""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		's,-(march=pentium|O3|ffast-math),,g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e \
		's|-I\.[[:space:]]+-I\$$\(srcdir\)[[:space:]]+||' \
		${WRKSRC}/gui/Makefile.in
	@${REINPLACE_CMD} -e \
		's|<FL/fl_file_chooser.H>|<FL/Fl_File_Chooser.H>| ; \
		 s|/doc/quat/|/doc/${UNIQUENAME}/|' \
		${WRKSRC}/gui/MainWindow.cxx
# disable data file installation since distfile does not do
# The Right Thing(TM)
	@${REINPLACE_CMD} -E -e \
		's|^(install-data-am:).*$$|\1| ; \
		 s|^(SUBDIRS.*)doc|\1|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@PACKAGE@|${UNIQUENAME}|' \
		${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>
