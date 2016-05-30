# Created by: alonso@
# $FreeBSD$

PORTNAME=	simon
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	audio kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Speech recognition system using sphinx, ALSA and KDE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libsamplerate.so:audio/libsamplerate \
		libpocketsphinx.so:audio/pocketsphinx \
		libsphinxad.so:audio/sphinxbase \
		libqwt6.so:x11-toolkits/qwt6

USE_KDE4=	kdelibs automoc4 pimlibs
USES=		cmake:outsource gettext tar:bz2
USE_QT4=	accessible corelib dbus gui script testlib xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CMAKE_ARGS+=	-DWITH_OpenCV:BOOL=OFF

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
