# New ports collection makefile for:	pwlib
# Date created:		Fri Aug 22 07:11:44 GMT 2003
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pwlib
PORTVERSION=	1.10.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.voxgratia.org/releases/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/./_/g}-src-
EXTRACT_SUFX=	tar.gz

MAINTAINER=	steve@energistic.com
COMMENT=	A cross platform C++ library, used by OpenH323

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}_v${PORTVERSION:S/./_/g}

USE_BISON=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259
WANT_GNOME=	yes
WANT_SDL=	yes
USE_OPENSSL=	yes
NO_FILTER_SHLIBS=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -O1 -I${WRKSRC}/include -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CFLAGS="${CFLAGS} -O1"
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -O1 -I${WRKSRC}/include -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		STDCCFLAGS+="-I${LOCALBASE}" \
		CFLAGS="${CFLAGS} -O1"

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

#disable OpenLDAP support in PWLIB
.if defined(WITHOUT_LDAP)
CONFIGURE_ARGS+=	--disable-openldap
.else
USE_OPENLDAP=	yes
CONFIGURE_ENV+=	OPENLDAPLIBDIR="${LOCALBASE}/lib"
MAKE_ENV+=	OPENLDAPLIBDIR="${LOCALBASE}/lib"
.endif

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

.if (${ARCH} == "i386") || (${ARCH} == "ia64") || (${ARCH} == "amd64")
PLIST_SUB+=	BSDVIDEO=""
.else
PLIST_SUB+=	BSDVIDEO="@comment "
.endif

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' \
		${WRKSRC}/src/ptlib/common/tinyjpeg.cxx \
		${WRKSRC}/src/ptlib/common/jidctflt.cxx
.endif

.include <bsd.port.post.mk>
