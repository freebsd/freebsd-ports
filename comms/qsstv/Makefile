# $FreeBSD$

PORTNAME=	qsstv
PORTVERSION=	8.2.11
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://users.telenet.be/on4qz/qsstv/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	shurd
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio SSTV/FAX reception program for unix

LICENSE=	GPLv3

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libhamlib.so:${PORTSDIR}/comms/hamlib \
		libasound.so:${PORTSDIR}/audio/alsa-lib \
		libjasper.so:${PORTSDIR}/graphics/jasper
BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat

USES=		qmake
USE_QT4=	gui network xml moc_build rcc_build uic_build

.include <bsd.port.options.mk>

.include <bsd.port.mk>
