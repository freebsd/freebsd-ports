# Created by: alonso@
# $FreeBSD$

PORTNAME=	simon
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	audio kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Speech recognition system using sphinx, ALSA and KDE

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libsamplerate.so:audio/libsamplerate \
		libpocketsphinx.so:audio/pocketsphinx \
		libsphinxad.so:audio/sphinxbase \
		libqwt6.so:x11-toolkits/qwt6@qt4

USES=		cmake gettext kde:4 qt:4 tar:bz2
USE_KDE=	kdelibs automoc4 pimlibs
USE_QT=		accessible corelib dbus gui network script sql svg testlib xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xtst

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DWITH_OpenCV:BOOL=OFF

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
