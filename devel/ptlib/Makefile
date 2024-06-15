PORTNAME=	ptlib
PORTVERSION=	2.10.11
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cross platform C++ library, used by OPAL
WWW=		http://www.opalvoip.org

LICENSE=	MPL10

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		autoreconf:build bison:wrapper compiler:c11 gmake localbase:ldflags \
		pathfix pkgconfig ssl tar:xz
BROKEN_SSL=	openssl openssl31
BROKEN_SSL_REASON=	Uses OpenSSL 3.0.0 deprecated BIO_s_file_internal
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--disable-lua \
		--disable-sasl \
		--enable-audio \
		--enable-ipv6 \
		--enable-exceptions \
		--enable-oss \
		--enable-plugins
# --with-expat-dir="${LOCALBASE}"
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

ALL_TARGET=	optshared

CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

CONFLICTS=	pwlib-1.*

PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PVERSION_MAJOR=${PVERSION_MAJOR} \
		PVERSION_MINOR=${PVERSION_MINOR}

OPTIONS_DEFINE=	DEBUG BSDVIDEO ODBC ALSA JABBER V4L SDL LDAP PULSEAUDIO
OPTIONS_DEFAULT=BSDVIDEO SDL V4L JABBER
OPTIONS_EXCLUDE_FreeBSD_13=	BSDVIDEO
OPTIONS_EXCLUDE_FreeBSD_14=	BSDVIDEO
OPTIONS_SUB=	yes

BSDVIDEO_DESC=	BSD video support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=alsa
BSDVIDEO_CONFIGURE_ENABLE=bsdvideo
BSDVIDEO_VARS=	PTLIB_VIDEO=1
DEBUG_ALL_TARGET=	debugshared
JABBER_CONFIGURE_ON=--enable-jabber
JABBER_VARS=	PTLIB_VIDEO=1
LDAP_USES=	ldap
LDAP_CONFIGURE_ENABLE=openldap
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
ODBC_CONFIGURE_ENABLE=	odbc
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=pulse
SDL_USES=		sdl
SDL_USE=	SDL=sdl
SDL_CONFIGURE_ENABLE=sdl
V4L_BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_ENABLE=	v4l v4l2
V4L_VARS=	PTLIB_VIDEO=1

PVERSION_MAJOR=	${PORTVERSION:C/.[0-9]+.[0-9]+.//}
PVERSION_MINOR=	${PORTVERSION:C/.[0-9]+$//g}

.include <bsd.port.options.mk>

.if (${OPSYS} == FreeBSD && ${SSL_DEFAULT} == base) || ${SSL_DEFAULT} == openssl
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-src_ptclib_pssl.cxx-openssl111
.else
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-src_ptclib_pssl.cxx
.endif

.if defined(PTLIB_VIDEO)
CONFIGURE_ARGS+=--enable-video --enable-vidfile
PLIST_SUB+=	VIDEODIR=""
.else
CONFIGURE_ARGS+=--disable-video --disable-vidfile
PLIST_SUB+=	VIDEODIR="@comment "
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

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CPPFLAGS+=	-Dregister= -Wno-error=dynamic-exception-spec
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/RTF_WASCLONED/0x20000/' ${WRKSRC}/src/ptlib/unix/socket.cxx
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|auto_ptr|unique_ptr|' \
		${WRKSRC}/include/ptlib/psharedptr.h
	@${REINPLACE_CMD} -e 's|public binary_function|public __binary_function|' \
		${WRKSRC}/include/ptlib/pprocess.h
.endif

pre-configure:
	(cd ${WRKSRC}/plugins/ && ${AUTORECONF} -fi)

post-install:
	${LN} -sf libpt.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libpt.so.${PVERSION_MAJOR}
	${LN} -sf libpt.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libpt.so.${PVERSION_MINOR}
	@${CHMOD} 0755 ${STAGEDIR}${PREFIX}/lib/libpt.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/ptlib-${PORTVERSION}/devices/*/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpt.so.${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ptlib-${PORTVERSION}/devices/*/*.so

post-install-DEBUG-on:
	${LN} -sf libpt_d.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libpt_d.so.${PVERSION_MAJOR}
	${LN} -sf libpt_d.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libpt_d.so.${PVERSION_MINOR}

.include <bsd.port.post.mk>
