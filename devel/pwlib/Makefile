# Created by: Roger Hardiman <roger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pwlib
PORTVERSION=	1.12.0
PORTREVISION=	10
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/openh323/${PORTNAME}/${PORTVERSION}
DISTNAME=	ptlib-v${PORTVERSION:S/./_/g}-src
DIST_SUBDIR=	openh323

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross platform C++ library, used by OpenH323

LIB_DEPENDS=	libexpat.so:textproc/expat2

CONFLICTS=	ptlib-2.*

WRKSRC=		${WRKDIR}/ptlib_v${PORTVERSION:S/./_/g}

USES=		bison gmake
USE_GCC=	any
USE_AUTOTOOLS=	autoconf
WANT_GNOME=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	SDL PLUGINS LDAP ESOUND V4L
OPTIONS_DEFAULT=	PLUGINS LDAP
OPTIONS_SUB=	yes
LDAP_DESC=	OpenLDAP support

CFLAGS+=		-O1
MAKE_ENV=	STDCCFLAGS+="-I${LOCALBASE}"
CPPFLAGS+=	-O1 -I${WRKSRC}/include -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV+=	ATOMICITY_H="<ext/atomicity.h>"

SDL_USE=	SDL=sdl
SDL_CONFIGURE_ENV=	SDLLIBDIR="${LOCALBASE}/lib"
SDL_MAKE_ENV=	SDLLIBDIR="${LOCALBASE}/lib"
SDL_CONFIGURE_ENABLE=	sdl

PLUGINS_CONFIGURE_ENABLE=	plugins

LDAP_CONFIGURE_ENABLE=	openldap
LDAP_USE=	OPENLDAP=yes
LDAP_CONFIGURE_ENV=	OPENLDAPLIBDIR="${LOCALBASE}/lib"
LDAP_MAKE_ENV=	OPENLDAPLIBDIR="${LOCALBASE}/lib"

ESOUND_USE=	GNOME=esound
ESOUND_CONFIGURE_ENABLE=	esd

V4L_CONFIGURE_ENABLE=	v4l
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:multimedia/v4l_compat

#explicity build OSS
CONFIGURE_ARGS+=	--enable-oss
#disable OBDC support... it doesn't compile and nothing _seems_ to
#actually use it. If you do have something that requires this please
#send patches!
CONFIGURE_ARGS+=	--disable-odbc

# ONLY FOR THE BRAVE!
# If someone owns a firewire(4) video device and wants to use it for
# video-conferencing purposes, please download the files:
# libraw1394.shar.gz, libavc1394.shar.gz and libdc1394.shar.gz from
# ftp://ftp.frm2.tum.de/pub/jpulz/FreeBSD/ports/
# Extract the files in ${PORTSDIR}/devel and uncomment the following lines.
#
##enable libavc1394
#.if defined(WITH_AVC1394)
#LIB_DEPENDS+=	avc1394.2:devel/libavc1394 \
#		dv.4:multimedia/libdv
#CONFIGURE_ARGS+=	--enable-avc
#PLIST_SUB+=	AVC1394=""
#.else
CONFIGURE_ARGS+=	--disable-avc
PLIST_SUB+=	AVC1394="@comment "
#.endif
#
##enable libdc1394
#.if defined(WITH_DC1394)
#LIB_DEPENDS+=	dc1394_control.13:devel/libdc1394
#CONFIGURE_ARGS+=	--enable-dc
#PLIST_SUB+=	DC1394=""
#.else
CONFIGURE_ARGS+=	--disable-dc
PLIST_SUB+=	DC1394="@comment "
#.endif

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64") || (${ARCH} == "ia64") || (${ARCH} == "powerpc") || (${ARCH} == "sparc64")
CFLAGS+=	-fPIC
.endif

.if (${ARCH} == "amd64") || (${ARCH} == "i386") || (${ARCH} == "ia64") || (${ARCH} == "powerpc") || (${ARCH} == "sparc64")
PLIST_SUB+=	BSDVIDEO=""
.else
PLIST_SUB+=	BSDVIDEO="@comment "
.endif

.include <bsd.port.post.mk>
