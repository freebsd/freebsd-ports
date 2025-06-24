PORTNAME=	shuriken
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2-5
DISTVERSIONSUFFIX=	-gd09afc7
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Shuriken beat slicer
WWW=		https://github.com/rock-hopper/shuriken

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libaubio.so:audio/aubio \
		liblo.so:audio/liblo \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		librubberband.so:audio/rubberband \
		libsysinfo.so:devel/libsysinfo

USES=		gl qmake qt:5 xorg
USE_QT=		core gui opengl widgets buildtools:build linguisttools:build
USE_GL=		gl
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	rock-hopper

CXXFLAGS+=	-Dstat64=stat
LDFLAGS+=	-lexecinfo \
		-lsysinfo

PLIST_FILES=	bin/${PORTNAME}

pre-patch: # remove all .orig files
	@${FIND} ${WRKSRC} -name "*.orig" | ${XARGS} ${RM}

pre-build: # build libsndlib_shuriken
	@${MKDIR} ${WRKSRC}/lib
	@cd ${WRKSRC}/src/SndLibShuriken && \
		./configure --without-audio --without-s7 && \
		${GMAKE} && \
		${MV} libsndlib_shuriken.a ../../lib/

.include <bsd.port.mk>
