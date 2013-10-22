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
LIB_DEPENDS=	mad:${PORTSDIR}/audio/libmad \
		GLEW:${PORTSDIR}/graphics/glew

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ENV+=	ac_cv_lib_pulse_pa_stream_new=no
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--without-vorbis
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^LIBS/s|-lpthread|${ICONV_LIB}|' ${WRKSRC}/src/Makefile.in

pre-build:
	@${ECHO_CMD} -n > ${WRKDIR}/stepmania.sh
	@${ECHO_CMD} '#!${SH}' >> ${WRKDIR}/stepmania.sh
	@${ECHO_CMD} 'cd ${PREFIX}/lib/stepmania; ./stepmania $$@' >> ${WRKDIR}/stepmania.sh

post-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} SMData)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/stepmania.sh ${PREFIX}/bin/stepmania
	${INSTALL_DATA} ${WRKSRC}/stepmania.desktop ${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/icons/hicolor/scalable/apps
	cd ${WRKSRC}/icons/hicolor/scalable/apps && ${INSTALL_DATA} \
		stepmania-ssc.svg ${PREFIX}/share/icons/hicolor/scalable/apps
.for i in 16 22 24 32 36 48 64 72 96 128 192 256
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	cd ${WRKSRC}/icons/hicolor/${i}x${i}/apps && ${INSTALL_DATA} \
		stepmania-ssc.png ${PREFIX}/share/icons/hicolor/${i}x${i}/apps
.endfor
	@${MKDIR} ${PREFIX}/lib/stepmania
	${INSTALL_PROGRAM} ${WRKSRC}/src/stepmania ${PREFIX}/lib/stepmania
	${INSTALL_DATA} ${WRKSRC}/src/GtkModule.so ${PREFIX}/lib/stepmania
	@${MKDIR} ${PREFIX}/lib/stepmania/Packages
	${INSTALL_DATA} ${WRKSRC}/GameData.smzip ${PREFIX}/lib/stepmania/Packages
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(${TAR} -C ${WRKSRC}/Docs --exclude "Licenses.txt" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -)
	@${FIND} ${DOCSDIR} -print0 | ${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${DOCSDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} a+rx
.endif

.include <bsd.port.mk>
