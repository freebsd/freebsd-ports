# New ports collection makefile for:	demeter
# Date created:		25 Jan 2004
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	demeter
PORTVERSION=	3.21
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.ifdef (WITH_SAMPLE_DATA)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		DemeterSampleData-${SAMPLE_DATA_VER}-2${EXTRACT_SUFX}
.endif

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	A C++ library to render 3D terrains using OpenGL

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GL=		yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
WANT_SDL=	yes
USE_AUTOCONF_VER=	253
USE_AUTOMAKE_VER=	15
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

SAMPLE_DATA_VER=	3.20
SAMPLE_DATA_SUBDIR=	DemeterSampleData-${SAMPLE_DATA_VER}
WRKSRC_DATA=		${WRKDIR}/${SAMPLE_DATA_SUBDIR}

.include <bsd.port.pre.mk>

.if ${HAVE_SDL:Msdl} && ${HAVE_SDL:Mimage}
WITH_SDL=	yes
.endif

# .if ${HAVE_GNOME:Mlibxml2}
.if exists(${LOCALBASE}/lib/libxml2.so)
WITH_LIBXML2=	yes
.endif

.if exists(${X11BASE}/lib/libosg.so)
WITH_OSG=	yes
.endif

.if exists(${LOCALBASE}/lib/libgdal.so)
WITH_GDAL=	yes
.endif

.ifdef (WITH_SDL)
USE_SDL=	sdl image
.endif

.ifdef (WITH_LIBXML2)
USE_GNOME=	libxml2
.endif

.ifdef (WITH_OSG)
BUILD_DEPENDS+=	${X11BASE}/lib/libosg.so:${PORTSDIR}/graphics/osg
RUN_DEPENDS+=	${X11BASE}/lib/libosg.so:${PORTSDIR}/graphics/osg
.endif

.ifdef (WITH_GDAL)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libgdal.so:${PORTSDIR}/graphics/gdal
RUN_DEPENDS+=	${LOCALBASE}/lib/libgdal.so:${PORTSDIR}/graphics/gdal
.endif

.if !defined(WITH_SDL)
PLIST_SUB=	WITH_SDL="@comment "
.else
PLIST_SUB=	WITH_SDL=""
.endif

.if !defined(WITH_LIBXML2)
PLIST_SUB+=	WITH_LIBXML2="@comment "
.else
PLIST_SUB+=	WITH_LIBXML2=""
.endif

.if !defined(WITH_OSG)
PLIST_SUB+=	WITH_OSG="@comment "
.else
PLIST_SUB+=	WITH_OSG=""
.endif

.if !defined(WITH_GDAL)
PLIST_SUB+=	WITH_GDAL="@comment "
.else
PLIST_SUB+=	WITH_GDAL=""
.endif

.if !defined(WITH_SAMPLE_DATA)
PLIST_SUB+=	SAMPLE_DATA="@comment "
.else
PLIST_SUB+=	SAMPLE_DATA="" \
		SAMPLE_DATA_SUBDIR=${SAMPLE_DATA_SUBDIR}
.endif

pre-everything::
.ifndef (WITH_SDL)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_SDL=yes to compile with SDL support"
	@${ECHO_CMD} ""
.endif
.ifndef (WITH_LIBXML2)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_LIBXML2=yes to compile with XML support"
	@${ECHO_CMD} ""
.endif
.ifndef (WITH_OSG)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_OSG=yes to compile with Open Scene Graph support"
	@${ECHO_CMD} ""
.endif
.ifndef (WITH_GDAL)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_GDAL=yes to compile with GDAL support"
	@${ECHO_CMD} ""
.endif
.ifndef (WITH_SAMPLE_DATA)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_SAMPLE_DATA=yes to download and install data for example programs"
	@${ECHO_CMD} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG:T}|g' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g; \
			      s|\(-lgdal\)\.1\.1|\1|g' \
		`${FIND} ${WRKSRC} -name Makefile.am`
	@${REINPLACE_CMD} -e 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|' \
		${WRKSRC}/samples/SampleUtilities/Data.cpp

# install additional data files, required to run demo programs
.ifdef (WITH_SAMPLE_DATA)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/${SAMPLE_DATA_SUBDIR}
.for i in bmp jpg png raw rgba terrain
	${INSTALL_DATA} ${WRKSRC_DATA}/*.${i} ${EXAMPLESDIR}/${SAMPLE_DATA_SUBDIR}
.endfor
.endif

.include <bsd.port.post.mk>
