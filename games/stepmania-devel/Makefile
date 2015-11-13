# Created by: Brad Allen <braddo@tranceaddict.net>
# $FreeBSD$

PORTNAME=	stepmania
PORTVERSION=	5.0.9
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	games
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rrhythm game simulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/Docs/Licenses.txt

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libpng.so:${PORTSDIR}/graphics/png

USE_GITHUB=	yes

USES=		autoreconf gmake iconv jpeg pathfix perl5 pkgconfig shebangfix
USE_XORG=	x11 xrandr xtst
USE_GL=		glew
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-pcre \
		${ICONV_CONFIGURE_ARG}
INSTALLS_ICONS=	yes
SHEBANG_FILES=	Utils/*.pl \
		extern/zlib/zlib2ansi

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		ALSA DOCS FFMPEG GTK2 JACK MAD PULSEAUDIO VORBIS
OPTIONS_DEFAULT=	GTK2 MAD VORBIS
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_ENV_OFF=	ac_cv_lib_asound_snd_ctl_open=no
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CONFIGURE_ON=	--with-system-ffmpeg
FFMPEG_CONFIGURE_WITH=	ffmpeg
GTK2_USE=		gnome=gtk20
GTK2_CONFIGURE_ENABLE=	gtk2
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_WITH=	jack
MAD_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad
MAD_CONFIGURE_WITH=	mp3
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENV_OFF=	ac_cv_lib_pulse_pa_stream_new=no
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_WITH=	vorbis

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(x86_64\)|amd64*\|\1| ; \
		 s|-lpthread|-pthread|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		's|XLIBS+="-l|XLIBS="$$XLIBS -l|' ${WRKSRC}/autoconf/m4/x11.m4
	@${REINPLACE_CMD} -e \
		's|-rdynamic|-Wl,-export-dynamic| ; \
		 s|-finline-limit=300||' ${WRKSRC}/src/Makefile.am

pre-build:
	@${MKDIR} ${WRKDIR}/wrappers
	@${ECHO_CMD} -n \
		> ${WRKDIR}/wrappers/stepmania
	@${ECHO_CMD} '#!${SH}' \
		>> ${WRKDIR}/wrappers/stepmania
	@${ECHO_CMD} 'cd ${PREFIX}/lib/stepmania' \
		>> ${WRKDIR}/wrappers/stepmania
	@${ECHO_CMD} 'exec ./stepmania $$@' \
		>> ${WRKDIR}/wrappers/stepmania

do-install:
	(cd ${WRKDIR}/wrappers && ${INSTALL_SCRIPT} stepmania \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/stepmania
.for i in Announcers BGAnimations BackgroundEffects BackgroundTransitions \
	Characters Courses Data NoteSkins Scripts Themes
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} \
		${STAGEDIR}${PREFIX}/lib/stepmania)
.endfor
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} stepmania \
		${STAGEDIR}${PREFIX}/lib/stepmania)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/stepmania/Songs
	(cd ${WRKSRC} && ${INSTALL_DATA} stepmania.desktop \
		${STAGEDIR}${PREFIX}/share/applications)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} icons \
		${STAGEDIR}${PREFIX}/share)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/Docs && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR} "! -name Licenses.txt")

post-install-GTK2-on:
	(cd ${WRKSRC}/src && ${INSTALL_LIB} GtkModule.so \
		${STAGEDIR}${PREFIX}/lib/stepmania)

.include <bsd.port.mk>
