# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	rosegarden
PORTVERSION=	17.04
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	General purpose music editor and sequencer suite

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dssi_osc_update:audio/dssi \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfftw3f.so:math/fftw3-float \
		liblrdf.so:textproc/liblrdf
RUN_DEPENDS=	dssi_osc_update:audio/dssi \
		flac:audio/flac \
		wavpack:audio/wavpack \
		xdg-open:devel/xdg-utils \
		lilypond:print/lilypond

USES=		alias cmake:outsource desktop-file-utils localbase:ldflags \
		pkgconfig shared-mime-info tar:bzip2

OPTIONS_DEFINE=		LIRC
OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CMAKE_ON=		-DENABLE_LIRC:BOOL=ON
QT4_USES=		qt:4
QT4_USE=		qt=gui,network,testlib,xml \
			qt=linguisttools_build,moc_build,qmake_build \
			qt=rcc_build,uic_build
QT4_CMAKE_ON=		-DUSE_QT4:BOOL=ON
QT5_USES=		compiler:c++11-lib qt:5
QT5_USE=		qt=network,printsupport,testlib,widgets,xml \
			qt=buildtools_build,linguisttools_build,qmake_build
QT5_CMAKE_ON=		-DUSE_QT5:BOOL=ON
TOOLKIT_DESC=		Qt toolkit

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

.include <bsd.port.mk>
