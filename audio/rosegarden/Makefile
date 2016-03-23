# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	rosegarden
PORTVERSION=	15.12.1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose music editor and sequencer suite

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		makedepend:${PORTSDIR}/devel/makedepend \
		${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib \
		liblirc_client.so:${PORTSDIR}/comms/lirc \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		liblrdf.so:${PORTSDIR}/textproc/liblrdf
RUN_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		lilypond:${PORTSDIR}/print/lilypond

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USES=		cmake:outsource desktop-file-utils gmake pkgconfig \
		shared-mime-info tar:bzip2

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALLS_ICONS=	yes

OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT4

QR4_USES=		compiler:c++0x
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
