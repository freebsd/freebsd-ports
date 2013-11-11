# Created by: Brad Allen <braddo@tranceaddict.net>
# $FreeBSD$

PORTNAME=	stepmania
PORTVERSION=	5.0.a3
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-SM5-alpha3-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rrhythm game simulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/Docs/Licenses.txt

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad \
		libGLEW.so:${PORTSDIR}/graphics/glew

OPTIONS_DEFINE=	PULSEAUDIO VORBIS DOCS
OPTIONS_DEFAULT=VORBIS

WRKSRC=		${WRKDIR}/${PORTNAME}-SM5-alpha3

PROJECTHOST=	sm-ssc
USE_BZIP2=	yes
USE_XORG=	x11 xau xdmcp xext xrandr xrender xtst
USE_GL=		gl glu
USES=		pathfix iconv shebangfix perl5 pkgconfig
USE_GNOME=	gtk20
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-ffmpeg
INSTALLS_ICONS=	yes
SHEBANG_FILES=	Utils/*.pl \
		extern/zlib/zlib2ansi

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lpthread

VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_WITH=	vorbis

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ENV+=	ac_cv_lib_pulse_pa_stream_new=no
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^LIBS/s|-lpthread|${ICONV_LIB}|' -e 's/-finline-limit=300//g' \
			 ${WRKSRC}/src/Makefile.in

pre-build:
	@${ECHO_CMD} -n > ${WRKDIR}/stepmania.sh
	@${ECHO_CMD} '#!${SH}' >> ${WRKDIR}/stepmania.sh
	@${ECHO_CMD} 'cd ${PREFIX}/lib/stepmania; ./stepmania $$@' >> ${WRKDIR}/stepmania.sh

post-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} SMData)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/stepmania.sh ${STAGEDIR}${PREFIX}/bin/stepmania
	${INSTALL_DATA} ${WRKSRC}/stepmania.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	cd ${WRKSRC}/icons/hicolor/scalable/apps && ${INSTALL_DATA} \
		stepmania-ssc.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
.for i in 16 22 24 32 36 48 64 72 96 128 192 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	cd ${WRKSRC}/icons/hicolor/${i}x${i}/apps && ${INSTALL_DATA} \
		stepmania-ssc.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/stepmania
	${INSTALL_PROGRAM} ${WRKSRC}/src/stepmania ${STAGEDIR}${PREFIX}/lib/stepmania
	${INSTALL_DATA} ${WRKSRC}/src/GtkModule.so ${STAGEDIR}${PREFIX}/lib/stepmania
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/stepmania/Packages
	${INSTALL_DATA} ${WRKSRC}/GameData.smzip ${STAGEDIR}${PREFIX}/lib/stepmania/Packages
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(${TAR} -C ${WRKSRC}/Docs --exclude "Licenses.txt" -cf - . | \
		${TAR} -C ${STAGEDIR}${DOCSDIR} --unlink -xf -)

.include <bsd.port.mk>
