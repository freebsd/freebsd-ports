# New ports collection makefile for:	Hydrogen
# Date created:			23 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	hydrogen
PORTVERSION=	0.9.4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Hydrogen/${PORTVERSION}%20Sources

MAINTAINER=	devel@stasyan.com
COMMENT=	An advanced drum machine

LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile \
		tar.0:${PORTSDIR}/devel/libtar \
		lrdf.2:${PORTSDIR}/textproc/liblrdf

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui linguist_build moc_build network qt3support rcc_build sql uic_build xml
USE_SCONS=	yes

OPTIONS=	JACK "JACK support" on \
		ALSA "ALSA support" off \
		PORTAUDIO "PortAudio support" off \
		LIBARCHIVE "LibArchive support" off \
		LASH "Lash support" off \
		PORTAUDIO "Portaudio support" off \

post-patch:
		${REINPLACE_CMD} -e "s|includes = \[\]|includes = \['-I${QT_INCDIR}/QtCore', '-I${QT_INCDIR}/QtXml', '-I${QT_INCDIR}/QtGui',  '-I${QT_INCDIR}', '-I${QT_INCDIR}/Qt', '-I${LOCALBASE}/include'\]|g; s|ldflags = \[\]|ldflags = \['-L${QT_LIBDIR}','-L${LOCALBASE}/lib'\,'-lQtCore', '-lQtGui', '-lQtXml', '-lQtNetwork', '${PTHREAD_LIBS}']|g" ${WRKSRC}/Sconstruct

.include <bsd.port.options.mk>

SCONS_ENV+=	oss=1
.if defined(WITH_JACK)
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
SCONS_ENV+=	jack=1
.else
SCONS_ENV+=	jack=0
.endif

.if defined(WITH_PORTAUDIO)
LIB_DEPENDS+=	portaudio.0:${PORTSDIR}/audio/portaudio
SCONS_ENV+=	portaudio=1
.else
SCONS_ENV+=	portaudio=0
.endif

.if defined(WITH_LIBARCHIVE)
LIB_DEPENDS+=	archive:${PORTSDIR}/archivers/libarchive
SCONS_ENV+=	libarchive=1
.else
SCONS_ENV+=	libarchive=0
.endif

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
SCONS_ENV+=	alsa=1
.else
SCONS_ENV+=	alsa=0
.endif

.if defined(WITH_LASH)
LIB_DEPENDS+=	lash.2:${PORTSDIR}/audio/lash
SCONS_ENV+=	lash=1
.else
SCONS_ENV+=	lash=0
.endif

SCONS_ENV+=	cppflags="${CXXFLAGS}" 	linkflags="${LINKFLAGS}" prefix="${PREFIX}" CC="${CC}" CXX="${CXX}"

pre-install:
	-@${RM} -rf ${WRKSRC}/data/doc/man

.include <bsd.port.mk>
