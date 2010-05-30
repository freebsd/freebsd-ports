# New ports collection makefile for:    gnustep-cdplayer
# Date created:         17 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	cdplayer
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	audio gnustep
MASTER_SITES=	SF/gsburn/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	gnustep-

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep CD player with CDDB support

LIB_DEPENDS+=	cdaudio.1:${PORTSDIR}/audio/libcdaudio

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_BUNDLES+=	Cddb:${CDDB_BUNDLE_PORT}
USE_GNUSTEP_SYSTEM_LIBS+=	PrefsModule:${PREFERENCES_PORT}

WRKSRC=		${WRKDIR}/CDPlayer-${PORTVERSION}
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

CDDB_BUNDLE_PORT?=	audio/cddb-bundle
PREFERENCES_PORT?=	deskutils/preferences.app

pre-configure:
	${LN} -s ${GNUSTEP_SYSTEM_ROOT}/Library/Frameworks/PrefsModule.framework/Versions/A/Headers ${WRKSRC}/AudioCD/AudioCDPrefs/PrefsModule

post-install:
	${MKDIR} ${GNUSTEP_PREFIX}/Local/Library/Headers/CDPlayer
	${INSTALL_DATA} ${WRKSRC}/CDPlayer/AudioCDProtocol.h \
		 ${GNUSTEP_PREFIX}/Local/Library/Headers/CDPlayer/

.include <bsd.port.mk>
