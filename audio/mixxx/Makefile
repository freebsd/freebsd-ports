# New ports collection makefile for:	Mixxx
# Date created:			25 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	mixxx
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://downloads.mixxx.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DJ mixing application

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		portaudio.2:${PORTSDIR}/audio/portaudio2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui opengl qt3support script svg xml \
		linguist_build moc_build qmake_build uic_build \
		moc_build rcc_build
USE_SCONS=	yes
SCONS_BUILDENV=	${SCONS_ENV}
SCONS_ARGS=	qtdir="${QT_PREFIX}"

CCFLAGS=	`pkg-config --cflags portaudio-2.0 \
			QtCore QtGui QtOpenGL Qt3Support QtScript QtSvg QtXml`
LINKFLAGS=	-L${LOCALBASE}/lib/portaudio2 -L${QT_LIBDIR} \
		-Wl,-rpath,${LOCALBASE}/lib/portaudio2 -Wl,-rpath,${QT_LIBDIR} \
		${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e \
		'/pthread/d ; \
		 /X11R6/d ; \
		 /-pipe -Wall -W -g/d' ${WRKSRC}/src/SConscript

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in Mixxx-Manual.pdf README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
