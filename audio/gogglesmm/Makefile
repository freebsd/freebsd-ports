# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	gogglesmm
PORTVERSION=	1.0.9
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music collection manager and player

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libFOX-1.7.so:${PORTSDIR}/x11-toolkits/fox17

USE_GITHUB=	yes

USES=		compiler:c++11-lang desktop-file-utils gmake pkgconfig
USE_GL=		glew
USE_SQLITE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LINK="${CXX}" \
		OPT_CFLAGS="${CXXFLAGS}" \
		OPT_LDFLAGS="${LDFLAGS}" \
		RESWRAP="${LOCALBASE}/bin/fox-1.7/reswrap"
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--libdir=${PREFIX}/lib \
		--fox-prefix=${LOCALBASE} \
		--without-rsound
INSTALLS_ICONS=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

OPTIONS_DEFINE=		ALSA CDIO DBUS DOCS FAAD FFMPEG FLAC GCRYPT JACK \
			MAD MMS NLS OGG OPUS PULSEAUDIO SAMPLERATE SMB WAVPACK
OPTIONS_RADIO=		VORBISDEC
OPTIONS_RADIO_VORBISDEC=	TREMOR VORBIS
OPTIONS_DEFAULT=	CDIO DBUS FAAD FLAC MAD OGG OPUS SAMPLERATE SMB \
			VORBIS WAVPACK
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_OFF=	--without-alsa
CDIO_LIB_DEPENDS=	libcdio.so:${PORTSDIR}/sysutils/libcdio
CDIO_CONFIGURE_OFF=	--without-cdda
DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_OFF=	--without-dbus
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
OGG_LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg
OGG_CONFIGURE_OFF=	--without-ogg
OPUS_LIB_DEPENDS=	libopus.so:${PORTSDIR}/audio/opus
OPUS_CONFIGURE_OFF=	--without-opus
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--without-pulse
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
SAMPLERATE_CONFIGURE_OFF=	--without-samplerate
SMB_LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
SMB_CONFIGURE_ON=	--smb-prefix=${LOCALBASE}
SMB_CONFIGURE_OFF=	--without-smb
TREMOR_LIB_DEPENDS=	libvorbisidec.so:${PORTSDIR}/audio/libtremor
TREMOR_CONFIGURE_ON=	--with-tremor
TREMOR_IMPLIES=		OGG
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_OFF=	--without-vorbis
VORBIS_IMPLIES=		OGG
VORBISDEC_DESC=		Vorbis decoder library
WAVPACK_LIB_DEPENDS=	libwavpack.so:${PORTSDIR}/audio/wavpack
WAVPACK_CONFIGURE_OFF=	--without-wavpack

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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gogglesmm
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gogglesmm/libgap_*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
