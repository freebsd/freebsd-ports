# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	frei0r
PORTVERSION=	1.3
DISTVERSIONPREFIX=	plugins-
PORTREVISION?=	1
CATEGORIES=	graphics
MASTER_SITES?=	http://piksel.no/${PORTNAME}/releases/ \
		ftp://ftp.dyne.org/${PORTNAME}/releases/ \
		http://distfiles.macports.org/${PORTNAME}-plugins/

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Minimalistic plugin API for video effects

.if !defined(BUILDING_FREI0R_METAPORT)
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if defined(BUILDING_FREI0R_OPENCV) && defined(BUILDING_FREI0R_GAVL)
IGNORE=		cannot build OpenCV and gavl plugins simultaneously
.endif

.if defined(BUILDING_FREI0R_OPENCV)
PORTREVISION=	3
COMMENT=	Frei0r OpenCV plugins
PKGNAMESUFFIX=	-plugins-opencv
LIB_DEPENDS+=	libopencv_legacy.so:graphics/opencv
FREI0R_PLUGINS=	facebl0r facedetect
.elif defined(BUILDING_FREI0R_GAVL)
PORTREVISION=	2
COMMENT=	Frei0r gavl plugins
PKGNAMESUFFIX=	-plugins-gavl
LIB_DEPENDS+=	libgavl.so:multimedia/gavl
FREI0R_PLUGINS=	rgbparade scale0tilt vectorscope
.else

PORTDOCS=	*

OPTIONS_DEFINE=	APIDOC DOCS
OPTIONS_DEFINE_amd64=	MMX
APIDOC_DESC=	Install full documentation (requires doxygen)
MMX_DESC=	MMX CPU instructions

.include <bsd.port.options.mk>

. if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MAPIDOC}
BUILD_DEPENDS+=	doxygen:devel/doxygen
. endif

.endif # !defined(BUILDING_FREI0R_OPENCV) && !defined(BUILDING_FREI0R_GAVL)

.if defined(FREI0R_PLUGINS)
CPPFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST=		${WRKSRC}/PLIST
ALL_TARGET=
BUILD_WRKSRC=	${WRKSRC}/src
. for FILE in ${FREI0R_PLUGINS}
ALL_TARGET+=	${FILE}.la
PLIST_FILES+=	lib/frei0r-1/${FILE}.so
. endfor
.endif

post-patch:
.if !defined(BUILDING_FREI0R_GAVL)
	@${REINPLACE_CMD} -e 's/HAVE_GAVL=true/HAVE_GAVL=false/g' \
		${WRKSRC}/configure
.endif
.if !defined(BUILDING_FREI0R_OPENCV)
	@${REINPLACE_CMD} -e 's/HAVE_OPENCV=true/HAVE_OPENCV=false/g' \
		${WRKSRC}/configure
.endif
.if !defined(FREI0R_PLUGINS)
. if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MAPIDOC}
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|include|include doc|' ${WRKSRC}/Makefile.in
. endif
. if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install-data-am/s| install-docsDATA||' \
		${WRKSRC}/Makefile.in
. endif
	@${REINPLACE_CMD} -e 's|^docsdir.*|docsdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^htmldocsdir.*|htmldocsdir = ${DOCSDIR}|' \
		${WRKSRC}/doc/Makefile.in
.else
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/frei0r-1
. for FILE in ${FREI0R_PLUGINS}
	@${INSTALL_LIB} ${BUILD_WRKSRC}/.libs/${FILE}.so \
		${STAGEDIR}${PREFIX}/lib/frei0r-1/${FILE}.so
. endfor
.endif #!defined(FREI0R_PLUGINS)

pre-build:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.mk>

.endif # !defined(BUILDING_FREI0R_METAPORT)
