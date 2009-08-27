# New ports collection makefile for:	pwlib
# Date created:		Fri Aug 22 07:11:44 GMT 2003
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pwlib
PORTVERSION=	1.12.0
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES= 	SF/openh323/${PORTNAME}/${PORTVERSION}
DISTNAME=	ptlib-v${PORTVERSION:S/./_/g}-src
DIST_SUBDIR=	openh323

MAINTAINER=	steve@energistic.com
COMMENT=	A cross platform C++ library, used by OpenH323

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/ptlib_v${PORTVERSION:S/./_/g}

USE_BISON=	build
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
USE_GNOME=	gnometarget
WANT_GNOME=	yes
WANT_SDL=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>


CFLAGS=		-O1
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -O1 -I${WRKSRC}/include -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CFLAGS="${CFLAGS}"
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -O1 -I${WRKSRC}/include -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		STDCCFLAGS+="-I${LOCALBASE}"

.if ${OSVERSION} >= 700042
CONFIGURE_ENV+=	ATOMICITY_H="<ext/atomicity.h>"
.else
CONFIGURE_ENV+=	ATOMICITY_H="<bits/atomicity.h>"
.endif

# if explicitely asked for, depend upon it
.if defined(WITH_SDL)
USE_SDL+=	sdl
CONFIGURE_ENV+=	SDLLIBDIR="${LOCALBASE}/lib"
MAKE_ENV+=	SDLLIBDIR="${LOCALBASE}/lib"
.endif

# if explicitely disabled, do not depend upon it
.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--disable-sdl
.endif

# if nobody cares, use it if it is installed already
.if !defined(WITHOUT_SDL) && !defined(WITH_SDL)
.if ${HAVE_SDL:Msdl}
USE_SDL+=	sdl
CONFIGURE_ENV+=	SDLLIBDIR="${LOCALBASE}/lib"
MAKE_ENV+=	SDLLIBDIR="${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif
.endif

.if !defined(WITHOUT_PLUGINS)
CONFIGURE_ARGS+=	--enable-plugins
.endif

#explicity build OSS
CONFIGURE_ARGS+=	--enable-oss

#disable OpenLDAP support in PWLIB
.if defined(WITHOUT_LDAP)
CONFIGURE_ARGS+=	--disable-openldap
.else
USE_OPENLDAP=	yes
CONFIGURE_ENV+=	OPENLDAPLIBDIR="${LOCALBASE}/lib"
MAKE_ENV+=	OPENLDAPLIBDIR="${LOCALBASE}/lib"
.endif

#disable OBDC support... it doesn't compile and nothing _seems_ to
#actually use it. If you do have something that requires this please
#send patches!
CONFIGURE_ARGS+=	--disable-odbc

#enable esound support
.if defined(WITH_ESOUND) && ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-esd
PLIST_SUB+=	ESD=""
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESD="@comment "
.endif

# ONLY FOR THE BRAVE!
# If someone owns a firewire(4) video device and wants to use it for
# video-conferencing purposes, please download the files:
# libraw1394.shar.gz, libavc1394.shar.gz and libdc1394.shar.gz from
# ftp://ftp.frm2.tum.de/pub/jpulz/FreeBSD/ports/
# Extract the files in ${PORTSDIR}/devel and uncomment the following lines.
#
##enable libavc1394
#.if defined(WITH_AVC1394)
#LIB_DEPENDS+=	avc1394.2:${PORTSDIR}/devel/libavc1394 \
#		dv.4:${PORTSDIR}/multimedia/libdv
#CONFIGURE_ARGS+=	--enable-avc
#PLIST_SUB+=	AVC1394=""
#.else
CONFIGURE_ARGS+=	--disable-avc
PLIST_SUB+=	AVC1394="@comment "
#.endif
#
##enable libdc1394
#.if defined(WITH_DC1394)
#LIB_DEPENDS+=	dc1394_control.13:${PORTSDIR}/devel/libdc1394
#CONFIGURE_ARGS+=	--enable-dc
#PLIST_SUB+=	DC1394=""
#.else
CONFIGURE_ARGS+=	--disable-dc
PLIST_SUB+=	DC1394="@comment "
#.endif

.if (${ARCH} == "amd64") || (${ARCH} == "ia64") || (${ARCH} == "sparc64")
CFLAGS+=	-fPIC
.endif

.if (${ARCH} == "i386") || (${ARCH} == "ia64") || (${ARCH} == "amd64") || (${ARCH} == "sparc64")
PLIST_SUB+=	BSDVIDEO=""
.else
PLIST_SUB+=	BSDVIDEO="@comment "
.endif

.if defined(WITH_V4L) || ( exists(${LOCALBASE}/include/linux/videodev.h) && \
	!defined(WITHOUT_V4L) )
CONFIGURE_ARGS+=--enable-v4l
PLIST_SUB+=	V4L=""
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
.else
CONFIGURE_ARGS+=--disable-v4l
PLIST_SUB+=	V4L="@comment "
.endif

post-patch:
.if ${ARCH} == sparc64 && ${OSVERSION} <= 700003
	@${REINPLACE_CMD} -e 's|P_PTHREADS_XPG6|0|' \
		${WRKSRC}/src/ptlib/unix/tlibthrd.cxx
.endif

.include <bsd.port.post.mk>
