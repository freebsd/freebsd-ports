# New ports collection makefile for:	frei0r
# Date created:		17 November 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frei0r
PORTVERSION=	1.3
DISTVERSIONPREFIX=	plugins-
PORTREVISION?=	1
CATEGORIES=	graphics
MASTER_SITES?=	http://piksel.no/${PORTNAME}/releases/ \
		ftp://ftp.dyne.org/${PORTNAME}/releases/ \
		http://distfiles.macports.org/${PORTNAME}-plugins/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT?=	Minimalistic plugin API for video effects

.if !defined(BUILDING_FREI0R_METAPORT)
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if defined(BUILDING_FREI0R_OPENCV) && defined(BUILDING_FREI0R_GAVL)
IGNORE=		cannot build OpenCV and gavl plugins simultaneously
.endif

.if defined(BUILDING_FREI0R_OPENCV)
PORTREVISION=	1
COMMENT=	Frei0r OpenCV plugins
PKGNAMESUFFIX=  -plugins-opencv
LIB_DEPENDS+=	opencv_legacy.2:${PORTSDIR}/graphics/opencv
FREI0R_PLUGINS=	facebl0r facedetect
.elif defined(BUILDING_FREI0R_GAVL)
PORTREVISION=	1
COMMENT=	Frei0r gavl plugins
PKGNAMESUFFIX=  -plugins-gavl
LIB_DEPENDS+=	gavl.1:${PORTSDIR}/multimedia/gavl
FREI0R_PLUGINS=	rgbparade scale0tilt vectorscope
.else

PORTDOCS=	*

OPTIONS=	APIDOC "Install full documentation (requires doxygen)" off \
		MMX "Enable MMX CPU instructions" off

.include <bsd.port.options.mk>

. if !defined(NOPORTDOCS) && defined(WITH_APIDOC)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
. endif

.endif # !defined(BUILDING_FREI0R_OPENCV) && !defined(BUILDING_FREI0R_GAVL)

.if defined(FREI0R_PLUGINS)
CPPFLAGS+=	"-I${LOCALBASE}/include"
PLIST=		${WRKSRC}/PLIST
ALL_TARGET=
BUILD_WRKSRC=	${WRKSRC}/src
. for FILE in ${FREI0R_PLUGINS}
ALL_TARGET+=	${FILE}.la
PLIST_FILES+=	lib/frei0r-1/${FILE}.so
. endfor
PLIST_FILES+=	"@dirrmtry lib/frei0r-1"
.endif

.include <bsd.port.pre.mk>

.if !defined(WITH_MMX) && ${ARCH} != "amd64"
CONFIGURE_ARGS+=--disable-cpuflags
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
. if !defined(NOPORTDOCS) && defined(WITH_APIDOC)
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|include|include doc|' ${WRKSRC}/Makefile.in
. endif
. if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am/s| install-docsDATA||' \
		${WRKSRC}/Makefile.in
. endif
	@${REINPLACE_CMD} -e 's|^docsdir.*|docsdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^htmldocsdir.*|htmldocsdir = ${DOCSDIR}|' \
		${WRKSRC}/doc/Makefile.in
.else
do-install:
	@${MKDIR} ${PREFIX}/lib/frei0r-1
. for FILE in ${FREI0R_PLUGINS}
	@${INSTALL_LIB} ${BUILD_WRKSRC}/.libs/${FILE}.so \
		${PREFIX}/lib/frei0r-1/${FILE}.so
. endfor
.endif #!defined(FREI0R_PLUGINS)

pre-build:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.post.mk>

.endif # !defined(BUILDING_FREI0R_METAPORT)
