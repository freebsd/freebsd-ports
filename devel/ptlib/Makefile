# New ports collection makefile for:	pwlib
# Date created:		Fri Aug 22 07:11:44 GMT 2003
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ptlib
PORTVERSION=	2.4.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/ptlib/2.4
DISTNAME=	ptlib-${PORTVERSION}

MAINTAINER=	lihong@ieee.org
COMMENT=	A cross platform C++ library, used by OpenH323

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

CONFLICTS=	pwlib-1.* ptlib-2.6.*

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
WANT_GNOME=	yes
WANT_SDL=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800059
EXTRA_PATCHES=	${FILESDIR}/extra-src_ptlib_unix_socket.cxx
.endif

CONFIGURE_ENV=	\
		OPENSSL_CFLAGS="-I/usr/include" \
		OPENSSL_LIBS="-lssl"
CONFIGURE_ARGS+=	\
		--disable-atomicity \
		--with-expat-dir="${LOCALBASE}" \
		--enable-oss \
		--disable-odbc
ALL_TARGET=	optshared

# if explicitely asked for, depend upon it
.if defined(WITH_SDL)
USE_SDL+=	sdl
CONFIGURE_ENV+=	SDL_CFLAGS="`sdl-config --cflags`" \
		SDL_LIBS="`sdl-config --libs`"
MAKE_ENV+=	SDL_CFLAGS="`sdl-config --cflags`" \
		SDL_LIBS="`sdl-config --libs`"
.endif

# if explicitely disabled, do not depend upon it
.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--disable-sdl
.endif

# if nobody cares, use it if it is installed already
.if !defined(WITHOUT_SDL) && !defined(WITH_SDL)
.if ${HAVE_SDL:Msdl}
USE_SDL+=	sdl
CONFIGURE_ENV+=	SDL_CFLAGS="`sdl-config --cflags`" \
		SDL_LIBS="`sdl-config --libs`"
MAKE_ENV+=	SDL_CFLAGS="`sdl-config --cflags`" \
		SDL_LIBS="`sdl-config --libs`"
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif
.endif

.if !defined(WITHOUT_PLUGINS)
CONFIGURE_ARGS+=	--enable-plugins
.endif

#disable OpenLDAP support in PWLIB
.if defined(WITHOUT_LDAP)
CONFIGURE_ARGS+=	--disable-openldap
.else
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--enable-openldap --with-ldap-dir="${LOCALBASE}"
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

.if (${ARCH} == "i386") || (${ARCH} == "ia64") || (${ARCH} == "amd64") || (${ARCH} == "powerpc") || (${ARCH} == "sparc64")
CONFIGURE_ARGS+=--enable-bsdvideo
PLIST_SUB+=	BSDVIDEO=""
.else
CONFIGURE_ARGS+=--disable-bsdvideo
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
