# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kscd
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	CD Player for KDE

LICENSE=	GPLv2

LIB_DEPENDS=	libmusicbrainz3.so:${PORTSDIR}/audio/libmusicbrainz3

CONFLICTS_INSTALL=	kdemultimedia-4.[1-8].*

USES=		cmake:outsource
NO_STAGE=	yes
USE_KDE4=	kdehier kdelibs kdeprefix libkcddb libkcompactdisc \
		automoc4
USE_QT4=	phonon moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

OPTIONS_DEFINE=	ALSA

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
.else
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-no_alsa
.endif

.include <bsd.port.mk>

