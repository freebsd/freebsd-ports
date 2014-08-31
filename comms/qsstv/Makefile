# $FreeBSD$

PORTNAME=	qsstv
PORTVERSION=	8.2.7
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://users.telenet.be/on4qz/qsstv/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Amateur Radio SSTV/FAX reception program for unix

LICENSE=	GPLv3

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libhamlib.so:${PORTSDIR}/comms/hamlib \
		libasound.so:${PORTSDIR}/audio/alsa-lib \
		libjasper.so:${PORTSDIR}/graphics/jasper
.if defined(WITH_DEBUG)
LIB_DEPENDS+=	libqwt.so:${PORTSDIR}/x11-toolkits/qwt5
.endif
BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat

USES=		qmake
USE_QT4=	gui network xml moc_build rcc_build uic_build

.if defined(WITH_DEBUG)
IGNORE=		sources need more patching for debug build
.endif

PLIST_FILES=	bin/qsstv

.include <bsd.port.mk>
