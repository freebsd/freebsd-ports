# Created by: pjm <pierrejacqes.mimifir@gmail.com>
# $FreeBSD$

PORTNAME=	bristol
PORTVERSION=	0.60.10
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.60

MAINTAINER=	pierrejacques.mimifir@gmail.com
COMMENT=	Vintage synthesiers emulation for electric pianos and organs

LICENSE=	GPLv2

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack \
		libfluidsynth.so:${PORTSDIR}/audio/fluidsynth

NO_STAGE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build moc_build uic_build rcc_build linguist_build

CONFIGURE_ARGS+=	--disable-alsa --enable-oss \
			--enable-jack-default-audio \
			--enable-jack-default-midi \
			--disable-version-check


MAN1=		bristol.1 bristoljackstats.1
MLINKS=		bristol.1 brighton.1 bristol.1 startBristol.1

PORTDATA=	*

.include <bsd.port.mk>
