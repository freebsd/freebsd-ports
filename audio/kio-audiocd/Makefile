# $FreeBSD$

PORTNAME=	kio-audiocd
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	audio kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	audiocd-kio-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE IOSlave for accessing audio CDs

LICENSE=	GPLv2

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libcdda_paranoia.so:audio/cdparanoia \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

USES=		cmake:outsource tar:xz
USE_KDE4=	kdelibs libkcddb libkcompactdisc \
		automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LAME
LAME_DESC=	Install LAME MP3 audio encoder
LAME_RUN_DEPENDS=	lame:audio/lame

.include <bsd.port.mk>
