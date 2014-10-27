# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	gogglesmm
PORTVERSION=	0.14.0
CATEGORIES=	audio
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music collection manager and player

LICENSE=	GPLv3

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libFOX-1.7.so:${PORTSDIR}/x11-toolkits/fox17

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_COMMIT=	8ccdb53

USES=		compiler:c++0x desktop-file-utils gmake pkgconfig
USE_SQLITE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LINK="${CXX}" \
		OPT_CFLAGS="${CXXFLAGS}" \
		OPT_LDFLAGS="${LDFLAGS}" \
		RESWRAP="${LOCALBASE}/bin/fox-1.7/reswrap"
CONFIGURE_ARGS=	--prefix=${PREFIX} --fox-prefix=${LOCALBASE} \
		--without-rsound --without-mpcdec
INSTALLS_ICONS=	yes

USE_LDCONFIG=	${PREFIX}/lib/gogglesmm

PORTDOCS=	AUTHORS ChangeLog README

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

OPTIONS_DEFINE=		ALSA CDIO DOCS FAAD FFMPEG FLAC GCRYPT JACK \
			MAD MMS NLS OPUS PULSEAUDIO SAMPLERATE SMB TREMOR \
			VORBIS WAVPACK
OPTIONS_DEFAULT=	CDIO FAAD FLAC MAD OPUS SAMPLERATE SMB \
			VORBIS WAVPACK
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_OFF=	--without-alsa
CDIO_LIB_DEPENDS=	libcdio.so:${PORTSDIR}/sysutils/libcdio
CDIO_CONFIGURE_OFF=	--without-cdda
#DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
#DBUS_CONFIGURE_OFF=	--without-dbus
FAAD_LIB_DEPENDS=	libfaad.so:${PORTSDIR}/audio/faad
FAAD_CONFIGURE_ON=	--faad-prefix=${LOCALBASE}
FAAD_CONFIGURE_OFF=	--without-faad
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CONFIGURE_ON=	--with-avcodec
FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CONFIGURE_OFF=	--without-flac
GCRYPT_DESC=		Use libgcrypt for md5 calculation
GCRYPT_LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
GCRYPT_CONFIGURE_ON=	--with-md5=gcrypt
GCRYPT_CONFIGURE_OFF=	--with-md5=internal
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_OFF=	--without-jack
MAD_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad
MAD_CONFIGURE_ON=	--mad-prefix=${LOCALBASE}
MAD_CONFIGURE_OFF=	--without-mad
MMS_LIB_DEPENDS=	libmms.so:${PORTSDIR}/net/libmms
MMS_CONFIGURE_OFF=	--without-mms
NLS_USES=		gettext
NLS_LIBS=		-lintl
NLS_CONFIGURE_OFF=	--without-nls
OPUS_DESC=		Opus decoding with libopus
OPUS_LIB_DEPENDS=	libopus.so:${PORTSDIR}/audio/opus
OPUSE_CONFIGURE_OFF=	--without-opus
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--without-pulse
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
SAMPLERATE_CONFIGURE_OFF=	--without-samplerate
SMB_LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
SMB_CONFIGURE_ON=	--smb-prefix=${LOCALBASE}
SMB_CONFIGURE_OFF=	--without-smb
TREMOR_LIB_DEPENDS=	libvorbisidec.so:${PORTSDIR}/audio/libtremor
TREMOR_CONFIGURE_ON=	--with-tremor
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_OFF=	--without-off --without-vorbis
WAVPACK_LIB_DEPENDS=	libwavpack.so:${PORTSDIR}/audio/wavpack
WAVPACK_CONFIGURE_OFF=	--without-wavpack

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 34
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$$(sharedir)/man|$$(installdir)/man| ; \
		 /INSTALL/s|-D|-c| ; \
		 s|@$$(CXX)|$$(CXX)|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|@$$(LINK)|$$(LINK)|' ${WRKSRC}/build/*.mk

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gogglesmm
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata
	@${MKDIR} ${STAGEDIR}${DATADIR}/utils
.for i in 16 22 24 32 48
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gogglesmm/libgap_*.so

.include <bsd.port.post.mk>
