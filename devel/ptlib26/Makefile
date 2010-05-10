# New ports collection makefile for:	pwlib
# Date created:		Fri Aug 22 07:11:44 GMT 2003
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ptlib
PORTVERSION=	2.6.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/ptlib/2.6
DISTNAME=	ptlib-${PORTVERSION}

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	A cross platform C++ library, used by OPAL

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

CONFLICTS=	pwlib-1.* ptlib-2.4.*

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
WANT_GNOME=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-oss --enable-plugins --with-expat-dir="${LOCALBASE}"

OPTIONS=	ODBC		"Use ODBC" On \
		V4L		"Use Video4Linux" Off \
		BSDVIDEO	"Enable BSD video support" On \
		SDL		"Use SDL" On \
		LDAP		"Enable LDAP support" Off

.include <bsd.port.pre.mk>

PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PVERSION_MAJOR=${PORTVERSION:C/.[0-9]+$//g}  \
		PVERSION_MINOR=${PORTVERSION:C/^[0-9]+.[0-9]+.//}

.if defined(WITH_DEBUG)
ALL_TARGET=	optshared debugshared
BROKEN=		debug libs install broken
.else
ALL_TARGET=	optshared
.endif

.if defined(WITH_ODBC)
CONFIGURE_ARGS+=	--enable-odbc
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
.else
CONFIGURE_ARGS+=	--disable-odbc
.endif

.if defined(WITH_BSDVIDEO)
CONFIGURE_ARGS+=--enable-bsdvideo
PLIST_SUB+=	BSDVIDEO=""
WITH_VIDEO=1
.else
CONFIGURE_ARGS+=--disable-bsdvideo
PLIST_SUB+=	BSDVIDEO="@comment "
.endif

.if defined(WITH_V4L)
CONFIGURE_ARGS+=--enable-v4l --enable-v4l2
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include ${CPPFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS}"
PLIST_SUB+=	V4L=""
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS+=	v4l1.0:${PORTSDIR}/multimedia/libv4l
WITH_VIDEO=1
.else
CONFIGURE_ARGS+=--disable-v4l
PLIST_SUB+=	V4L="@comment "
.endif

.if defined(WITH_VIDEO)
CONFIGURE_ARGS+=	--enable-video
PLIST_SUB+=	VIDEODIR=""
.else
CONFIGURE_ARGS+=	--disable-video
PLIST_SUB+=	VIDEODIR="@comment "
.endif

.if defined(WITH_SDL)
USE_SDL+=	sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--enable-openldap --with-ldap-dir="${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--disable-openldap
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
#LIB_DEPENDS+=	dc1394.2[0-9]:${PORTSDIR}/multimedia/libdc1394
#CONFIGURE_ARGS+=	--enable-dc
#PLIST_SUB+=	DC1394=""
#.else
CONFIGURE_ARGS+=	--disable-dc
#PLIST_SUB+=	DC1394="@comment "
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpt|-lpt-${PORTVERSION:C/.[0-9]+$//g}|' ${WRKSRC}/ptlib.pc.in
.if ${ARCH} == sparc64 && ${OSVERSION} <= 700003
	@${REINPLACE_CMD} -e 's|P_PTHREADS_XPG6|0|' ${WRKSRC}/src/ptlib/unix/tlibthrd.cxx
.endif
.if ${OSVERSION} >= 800059
	@${REINPLACE_CMD} -e 's/RTF_WASCLONED/0x20000/' ${WRKSRC}/src/ptlib/unix/socket.cxx
.endif

.include <bsd.port.post.mk>
