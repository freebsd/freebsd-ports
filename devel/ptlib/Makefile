# Created by: Roger Hardiman <roger@freebsd.org>
# $FreeBSD$

PORTNAME=	ptlib
PORTVERSION=	2.10.11
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cross platform C++ library, used by OPAL

LICENSE=	MPL10

LIB_DEPENDS=	libexpat.so:textproc/expat2

CONFLICTS=	pwlib-1.*

USES=		autoreconf:build bison compiler:c11 gmake localbase:ldflags \
		pathfix pkgconfig ssl tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

CONFIGURE_ARGS+=--enable-audio \
		--enable-ipv6 \
		--enable-exceptions \
		--enable-oss \
		--enable-plugins

CONFIGURE_ARGS+=--disable-lua \
		--disable-sasl

# --with-expat-dir="${LOCALBASE}"
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

OPTIONS_DEFINE=	BSDVIDEO DEBUG ODBC ALSA JABBER V4L SDL LDAP PULSEAUDIO
OPTIONS_DEFAULT=BSDVIDEO SDL V4L JABBER

BSDVIDEO_DESC=	BSD video support
DEBUG_DESC=	Install debug library

.include <bsd.port.options.mk>

.if (${OPSYS} == FreeBSD && ${OSVERSION} > 1200085 && ${SSL_DEFAULT} == base) || ${SSL_DEFAULT} == openssl
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-src_ptclib_pssl.cxx-openssl111
.else
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-src_ptclib_pssl.cxx
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PVERSION_MAJOR=${PVERSION_MAJOR} \
		PVERSION_MINOR=${PVERSION_MINOR}

PVERSION_MAJOR=	${PORTVERSION:C/.[0-9]+.[0-9]+.//}
PVERSION_MINOR=	${PORTVERSION:C/.[0-9]+$//g}

.if ${PORT_OPTIONS:MDEBUG}
ALL_TARGET=	optshared debugshared
PLIST_SUB+=	DEBUG=""
.else
ALL_TARGET=	optshared
PLIST_SUB+=	DEBUG="@comment "
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:audio/pulseaudio
CONFIGURE_ARGS+=--enable-pulse
PLIST_SUB+=	PULSEAUDIO=""
.else
CONFIGURE_ARGS+=--disable-pulse
PLIST_SUB+=	PULSEAUDIO="@comment "
.endif

.if ${PORT_OPTIONS:MJABBER}
CONFIGURE_ARGS+=--enable-jabber
PLLIB_VIDEO=1
.endif

.if ${PORT_OPTIONS:MODBC}
LIB_DEPENDS+=	libodbc.so:databases/unixODBC
CONFIGURE_ARGS+=--enable-odbc
.else
CONFIGURE_ARGS+=--disable-odbc
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:audio/alsa-lib
CONFIGURE_ARGS+=--enable-alsa
PLIST_SUB+=	ALSA=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSA="@comment "
.endif

.if ${PORT_OPTIONS:MBSDVIDEO}
CONFIGURE_ARGS+=--enable-bsdvideo
PLIST_SUB+=	BSDVIDEO=""
PTLIB_VIDEO=1
.else
CONFIGURE_ARGS+=--disable-bsdvideo
PLIST_SUB+=	BSDVIDEO="@comment "
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=	v4l_compat>=0:multimedia/v4l_compat
LIB_DEPENDS+=	libv4l2.so:multimedia/libv4l
CONFIGURE_ARGS+=--enable-v4l --enable-v4l2
PLIST_SUB+=	V4L=""
PTLIB_VIDEO=1
.else
CONFIGURE_ARGS+=--disable-v4l --disable-v4l2
PLIST_SUB+=	V4L="@comment "
.endif

.if defined(PTLIB_VIDEO)
CONFIGURE_ARGS+=--enable-video --enable-vidfile
PLIST_SUB+=	VIDEODIR=""
.else
CONFIGURE_ARGS+=--disable-video --disable-vidfile
PLIST_SUB+=	VIDEODIR="@comment "
.endif

.if ${PORT_OPTIONS:MSDL}
USES+=		sdl
USE_SDL+=	sdl
CONFIGURE_ARGS+=--enable-sdl
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--enable-openldap
.else
CONFIGURE_ARGS+=--disable-openldap
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
#LIB_DEPENDS+=	dc1394.2[0-9]:multimedia/libdc1394
#CONFIGURE_ARGS+=	--enable-dc
#PLIST_SUB+=	DC1394=""
#.else
CONFIGURE_ARGS+=	--disable-dc
#PLIST_SUB+=	DC1394="@comment "
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's/RTF_WASCLONED/0x20000/' ${WRKSRC}/src/ptlib/unix/socket.cxx

pre-configure:
	(cd ${WRKSRC}/plugins/ && ${AUTORECONF} -fi)

post-install:
	${LN} -sf libpt.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libpt.so.${PVERSION_MAJOR}
	${LN} -sf libpt.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libpt.so.${PVERSION_MINOR}
.if ${PORT_OPTIONS:MDEBUG}
	${LN} -sf libpt_d.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libpt_d.so.${PVERSION_MAJOR}
	${LN} -sf libpt_d.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libpt_d.so.${PVERSION_MINOR}
.endif
	@${CHMOD} 0755 ${STAGEDIR}${PREFIX}/lib/libpt.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/ptlib-${PORTVERSION}/devices/*/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpt.so.${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ptlib-${PORTVERSION}/devices/*/*.so

.include <bsd.port.mk>
