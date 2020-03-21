# Created by: Alex Trull <freebsd.alex@trull.org>
# $FreeBSD$

PORTNAME=	scummvm
PORTVERSION=	2.1.1
CATEGORIES=	games emulators
MASTER_SITES=	http://www.scummvm.org/frs/scummvm/${PORTVERSION}/

PATCH_SITES=	https://github.com/scummvm/scummvm/commit/
PATCHFILES=	8593a9e1e4e8dd1f5dfac9b1304a417df9a742e6.patch:-p1 \
		68758a879e0c8ecc0d40962516d4e808aa4e15e5.patch:-p1

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Interpreter for several adventure games

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfaad.so:audio/faad \
		libfreetype.so:print/freetype2 \
		libmpeg2.so:multimedia/libmpeg2 \
		libtheoradec.so:multimedia/libtheora

USES=		gmake gnome iconv jpeg sdl tar:xz
HAS_CONFIGURE=	yes
USE_SDL=	sdl2
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=	--disable-alsa \
		--disable-debug \
		--disable-nasm \
		--disable-tremor \
		--enable-verbose-build \
		--with-jpeg-prefix=${LOCALBASE} \
		--with-sdl-prefix=${LOCALBASE} \
		--with-zlib-prefix=/usr

LDFLAGS+=	-lpthread

OPTIONS_DEFINE=		DOCS FLAC FLUIDSYNTH MP3 MT32EMU PNG SNDIO VORBIS
OPTIONS_DEFAULT=	MP3 MT32EMU PNG VORBIS
OPTIONS_SUB=		yes

MT32EMU_DESC=	MT-32 emulator

VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_ON=	--with-ogg-prefix=${LOCALBASE} \
			--with-vorbis-prefix=${LOCALBASE}
VORBIS_CONFIGURE_OFF=	--disable-vorbis \
			--disable-ogg

MP3_LIB_DEPENDS=	libmad.so:audio/libmad
MP3_CONFIGURE_ON=	--with-mad-prefix=${LOCALBASE}
MP3_CONFIGURE_OFF=	--disable-mad

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ON=	--with-png-prefix=${LOCALBASE}
PNG_CONFIGURE_OFF=	--disable-png

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ON=	--with-flac-prefix=${LOCALBASE}
FLAC_CONFIGURE_OFF=	--disable-flac

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ON=	--with-fluidsynth-prefix=${LOCALBASE}
FLUIDSYNTH_CONFIGURE_OFF=	--disable-fluidsynth

MT32EMU_CONFIGURE_OFF=	--disable-mt32emu

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ON=	--with-sndio-prefix=${LOCALBASE}
SNDIO_CONFIGURE_OFF=	--disable-sndio

.include <bsd.port.pre.mk>

.if ${ARCH} == armv6 || ${ARCH} == armv7
CONFIGURE_ENV+=	ASFLAGS=-meabi=5
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^mandir=/s/datarootdir/prefix/' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/dists/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
