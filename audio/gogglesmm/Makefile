# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	gogglesmm
PORTVERSION=	1.1.4
CATEGORIES=	audio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Music collection manager and player

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib \
		libexpat.so:textproc/expat2 \
		libFOX-1.7.so:x11-toolkits/fox17

USE_GITHUB=	yes

USES=		cmake compiler:c++11-lib desktop-file-utils \
		localbase:ldflags pkgconfig sqlite
USE_XORG=	ice sm x11
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=		ALSA DBUS DOCS FAAD FLAC GCRYPT MAD NLS \
			OGG OPENGL OPUS PULSEAUDIO
OPTIONS_RADIO=		VORBISDEC
VORBISDEC_DESC=		Vorbis decoder library
OPTIONS_RADIO_VORBISDEC=	TREMOR VORBIS
OPTIONS_DEFAULT=	DBUS FAAD FLAC MAD OGG OPENGL OPUS VORBIS
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	WITH_ALSA

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	WITH_DBUS

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FAAD_CMAKE_BOOL=	WITH_FAAD

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CMAKE_BOOL=	WITH_FLAC
FLAC_IMPLIES=		OGG

GCRYPT_DESC=		Use libgcrypt for md5 calculation
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CMAKE_BOOL=	WITH_GCRYPT

MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CMAKE_BOOL=		WITH_MAD

NLS_USES=		gettext
NLS_LDFLAGS=		-lintl
NLS_CMAKE_BOOL=		WITH_NLS

OGG_LIB_DEPENDS=	libogg.so:audio/libogg
OGG_CMAKE_BOOL=		WITH_OGG

OPENGL_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy
OPENGL_USE=		GL=gl,glu
OPENGL_CMAKE_BOOL=	WITH_OPENGL

OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CMAKE_BOOL=	WITH_OPUS
OPUS_IMPLIES=		OGG

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WITH_PULSE

TREMOR_LIB_DEPENDS=	libvorbisidec.so:audio/libtremor
TREMOR_CMAKE_BOOL=	WITH_TREMOR
TREMOR_IMPLIES=		OGG

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CMAKE_BOOL=	WITH_VORBIS
VORBIS_IMPLIES=		OGG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOGG} && !${PORT_OPTIONS:MTREMOR} && !${PORT_OPTIONS:MVORBIS}
IGNORE=	you have selected an option that requires a Vorbis decoder. Run 'make config' and select one
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
