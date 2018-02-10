# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	rosegarden
PORTVERSION=	17.04
PORTREVISION=	1
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
OPTIONS_DEFAULT=	QT4

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CMAKE_ON=		-DENABLE_LIRC:BOOL=ON
QT4_USE=		qt4=gui,network,testlib,xml \
			qt4=linguisttools_build,moc_build,qmake_build \
			qt4=rcc_build,uic_build
QT4_CMAKE_ON=		-DUSE_QT4:BOOL=ON
QT5_USES=		compiler:c++11-lib
QT5_USE=		qt5=network,printsupport,testlib,widgets,xml \
			qt5=buildtools_build,linguisttools_build,qmake_build
QT5_CMAKE_ON=		-DUSE_QT5:BOOL=ON
TOOLKIT_DESC=		Qt toolkit

.include <bsd.port.mk>
