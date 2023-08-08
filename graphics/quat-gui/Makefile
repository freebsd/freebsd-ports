PORTNAME=	quat
PORTVERSION=	1.20
PORTREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	https://www.physcip.uni-stuttgart.de/pages/~phy11733/download/
PKGNAMESUFFIX=	-gui

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Three-dimensional fractal creator (X11 GUI)
WWW=		https://www.physcip.uni-stuttgart.de/pages/~phy11733/index_e.html

LICENSE=	GPLv2+

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		gl localbase:ldflags xorg
USE_GL=		gl glut
USE_XORG=	xext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/doc
CONFIGURE_ENV=	FLUID="${LOCALBASE}/bin/fluid"

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
DESKTOP_ENTRIES="Quat" "3D Fractal Generator" "" "${PORTNAME}" "" ""

PLIST_FILES=	bin/quat
PORTDOCS=	*

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -ffast-math

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
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
		 s|/doc/quat/|/doc/${PKGBASE}/|' \
		${WRKSRC}/gui/MainWindow.cxx
# disable data file installation since distfile does not do
# The Right Thing(TM)
	@${REINPLACE_CMD} -E -e \
		's|^(install-data-am:).*$$|\1| ; \
		 s|^(SUBDIRS.*)doc|\1|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@PACKAGE@|${PKGBASE}|' \
		${WRKSRC}/doc/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
