# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	hydrogen
PORTVERSION=	0.9.5.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Hydrogen/${MAJORVERSION}%20Sources

MAINTAINER=	FreeBSD@ShaneWare.Biz
COMMENT=	Advanced drum machine

LICENSE=	GPLv2

CONFLICTS=	hydrogen-devel-0.*

LIB_DEPENDS+=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libtar.so:${PORTSDIR}/devel/libtar \
		liblrdf.so:${PORTSDIR}/textproc/liblrdf

MAJORVERSION=	0.9.5
USE_QT4=	corelib gui linguist_build moc_build network qt3support rcc_build sql uic_build xml
USES=		pkgconfig scons

OPTIONS_DEFINE=	JACK ALSA PORTAUDIO LIBARCHIVE LASH
OPTIONS_DEFAULT=	JACK

LIBARCHIVE_DESC=	LibArchive support

post-patch:
	${REINPLACE_CMD} -e "s|includes = \[\]|includes = \['-I${QT_INCDIR}/QtCore', '-I${QT_INCDIR}/QtXml', '-I${QT_INCDIR}/QtGui',  '-I${QT_INCDIR}', '-I${QT_INCDIR}/Qt', '-I${LOCALBASE}/include', '-I${LOCALBASE}/include/raptor2'\]|g; s|ldflags = \[\]|ldflags = \['-L${QT_LIBDIR}','-L${LOCALBASE}/lib'\,'-lQtCore', '-lQtGui', '-lQtXml', '-lQtNetwork']|g" ${WRKSRC}/Sconstruct

.include <bsd.port.options.mk>

MAKE_ARGS+=	oss=1

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack
MAKE_ARGS+=	jack=1
.else
MAKE_ARGS+=	jack=0
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	libportaudio.so:${PORTSDIR}/audio/portaudio
MAKE_ARGS+=	portaudio=1
.else
MAKE_ARGS+=	portaudio=0
.endif

.if ${PORT_OPTIONS:MLIBARCHIVE}
LIB_DEPENDS+=	libarchive.so:${PORTSDIR}/archivers/libarchive
MAKE_ARGS+=	libarchive=1
.else
MAKE_ARGS+=	libarchive=0
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
MAKE_ARGS+=	alsa=1
.else
MAKE_ARGS+=	alsa=0
.endif

.if ${PORT_OPTIONS:MLASH}
LIB_DEPENDS+=	liblash.so:${PORTSDIR}/audio/lash
MAKE_ARGS+=	lash=1
.else
MAKE_ARGS+=	lash=0
.endif

MAKE_ARGS+=	cppflags="${CXXFLAGS}" 	linkflags="${LINKFLAGS}" prefix="${PREFIX}" CC="${CC}" CXX="${CXX}"

pre-install:
	-@${RM} -rf ${WRKSRC}/data/doc/man

.include <bsd.port.mk>
