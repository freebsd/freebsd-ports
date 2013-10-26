# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	mixxx
PORTVERSION=	1.11.0
DISTVERSIONSUFFIX=	-src
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://downloads.mixxx.org/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DJ mixing application

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	portaudio2>=0:${PORTSDIR}/audio/portaudio2 \
		bzr>=0:${PORTSDIR}/devel/bzr
LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libmad.so:${PORTSDIR}/audio/libmad \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
		libtag.so:${PORTSDIR}/audio/taglib \
		libprotobuf.so:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	portaudio2>=0:${PORTSDIR}/audio/portaudio2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
USE_QT4=	corelib gui network opengl script sql svg xml \
		linguist_build moc_build qmake_build rcc_build uic_build
USE_GL=		glu
USE_SCONS=	yes
SCONS_BUILDENV=	${SCONS_ENV}
SCONS_ARGS=	qtdir="${QT_PREFIX}" optimize=0
USE_LDCONFIG=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	Mixxx-Manual.pdf README README.macro

DOCSRCDIR2=	${WRKSRC}/doc/HID
DOCSDIR2=	${DOCSDIR}/doc/HID
DOC_FILES2=	*.odt *.pdf

OPTIONS_DEFINE=	DOCS FAAD LAME SHOUTCAST TCMALLOC WAVPACK
OPTIONS_DEFAULT=	FAAD SHOUTCAST TCMALLOC WAVPACK

OPTIONS_SUB=	yes

TCMALLOC_DESC=	Use Google's TCMalloc

FAAD_LIB_DEPENDS=	libfaad.so:${PORTSDIR}/audio/faad \
			libmp4v2.so:${PORTSDIR}/multimedia/mp4v2
FAAD_SCONS_ARGS_ON=	faad=1
FAAD_SCONS_ARGS_OFF=	faad=0

LAME_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame

SHOUTCAST_LIB_DEPENDS=	libshout.so:${PORTSDIR}/audio/libshout
SHOUTCAST_SCONS_ARGS_ON=	shoutcast=1
SHOUTCAST_SCONS_ARGS_OFF=	shoutcast=0

TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:${PORTSDIR}/devel/google-perftools
TCMALLOC_SCONS_ARGS_ON=	perftools=1
TCMALLOC_SCONS_ARGS_OFF=	perftools=0

WAVPACK_LIB_DEPENDS=	libwavpack.so:${PORTSDIR}/audio/wavpack
WAVPACK_SCONS_ARGS_ON=	wv=1
WAVPACK_SCONS_ARGS_OFF=	wv=0

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/build/depends.py
	@${REINPLACE_CMD} -e "/('install', docs)/d" \
		${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -e "s|^Exec=.*|Exec=mixxx| ; \
		 s|^Icon=.*|Icon=${PREFIX}/share/pixmaps/mixxx-icon.png|" \
		${WRKSRC}/src/mixxx.desktop
.for i in midi/midimessage.h qtscript-bytearray/bytearrayclass.h
	@${ECHO_CMD} >> ${WRKSRC}/src/controllers/${i}
.endfor

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/mixxx

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
