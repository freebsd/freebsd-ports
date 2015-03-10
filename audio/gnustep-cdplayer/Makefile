# $FreeBSD$

PORTNAME=	cdplayer
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	audio gnustep
MASTER_SITES=	SF/gsburn/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	gnustep-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep CD player with CDDB support

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcdaudio.so:${PORTSDIR}/audio/libcdaudio

USES=		tar:bzip2
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_BUNDLES+=	Cddb:${CDDB_BUNDLE_PORT}
USE_GNUSTEP_SYSTEM_LIBS+=	PrefsModule:${PREFERENCES_PORT}

WRKSRC=		${WRKDIR}/CDPlayer-${PORTVERSION}
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

CDDB_BUNDLE_PORT?=	audio/cddb-bundle
PREFERENCES_PORT?=	deskutils/preferences

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/GNUstep/Local/Library/Bundles/AudioCD.bundle/AudioCD \
		${STAGEDIR}${PREFIX}/GNUstep/Local/Library/Bundles/AudioCD.prefs/AudioCD \
		${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/CDPlayer.app/CDPlayer

.include <bsd.port.mk>
