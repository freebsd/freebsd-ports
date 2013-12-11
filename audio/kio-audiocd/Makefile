# $FreeBSD$

PORTNAME=	kio-audiocd
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	audiocd-kio-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE IOSlave for accessing audio CDs

LICENSE=	GPLv2

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libcdda_paranoia.so:${PORTSDIR}/audio/cdparanoia \
		libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

CONFLICTS_INSTALL=	kdemultimedia-4.[1-8].*

USES=		cmake:outsource
NO_STAGE=	yes
USE_KDE4=	kdehier kdelibs kdeprefix libkcddb libkcompactdisc \
		automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LAME
LAME_DESC=	Install LAME MP3 audio encoder
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	LAME
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.include <bsd.port.mk>
