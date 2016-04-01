# $FreeBSD$

PORTNAME=	qsstv
PORTVERSION=	8.2.12
CATEGORIES=	comms hamradio
MASTER_SITES=	http://users.telenet.be/on4qz/qsstv/downloads/ \
		LOCAL/shurd
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio SSTV/FAX reception program for unix

LICENSE=	GPLv3

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libhamlib.so:comms/hamlib \
		libasound.so:audio/alsa-lib \
		libjasper.so:graphics/jasper
BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat

USES=		qmake
USE_QT4=	gui network xml moc_build rcc_build uic_build
PLIST_FILES=	bin/qsstv

.include <bsd.port.mk>
