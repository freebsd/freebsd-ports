PORTNAME=	gogglesmm
DISTVERSION=	1.3.1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/gogglesmm/gogglesmm/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-full-${DISTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Music collection manager and player
WWW=		https://gogglesmm.github.io/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib \
		libexpat.so:textproc/expat2 \
		libFOX-1.7.so:x11-toolkits/fox17

USES=		cmake compiler:c++11-lib desktop-file-utils gnome \
		pkgconfig sqlite xorg
USE_XORG=	ice sm x11 xext

CMAKE_ON=	FOX_USE_EXTERNAL \
		WITH_ZLIB

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=		A52 ALSA DBUS DCA DOCS FAAD FLAC MAD NLS \
			OGG OPENGL OPUS PULSEAUDIO SNDIO VORBIS
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	DBUS FAAD FLAC MAD OGG OPENGL OPENSSL OPUS VORBIS
OPTIONS_SUB=		yes

A52_LIB_DEPENDS=	liba52.so:audio/liba52
A52_CMAKE_BOOL=		WITH_A52

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	WITH_ALSA

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	WITH_DBUS

DCA_LIB_DEPENDS=	libdca.so:multimedia/libdca
DCA_CMAKE_BOOL=		WITH_DCA

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FAAD_CMAKE_BOOL=	WITH_FAAD

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CMAKE_BOOL=	WITH_FLAC
FLAC_IMPLIES=		OGG

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CMAKE_BOOL=	WITH_GNUTLS

MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CMAKE_BOOL=		WITH_MAD

NLS_USES=		gettext
NLS_CMAKE_BOOL=		WITH_NLS

OGG_LIB_DEPENDS=	libogg.so:audio/libogg
OGG_CMAKE_BOOL=		WITH_OGG

OPENGL_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy
OPENGL_USES=		gl
OPENGL_USE=		GL=opengl,glu
OPENGL_CMAKE_BOOL=	WITH_OPENGL

OPENSSL_USES=		ssl
OPENSSL_CMAKE_BOOL=	WITH_OPENSSL

OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CMAKE_BOOL=	WITH_OPUS
OPUS_IMPLIES=		OGG

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WITH_PULSE

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	WITH_SNDIO

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CMAKE_BOOL=	WITH_VORBIS
VORBIS_IMPLIES=		OGG

.include <bsd.port.options.mk>

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
