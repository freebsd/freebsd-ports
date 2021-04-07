PORTNAME=	cdplayer
PORTVERSION=	0.5.1
PORTREVISION=	9
CATEGORIES=	audio gnustep
MASTER_SITES=	SF/gsburn/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	gnustep-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep CD player with CDDB support

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcdaudio.so:audio/libcdaudio \
		libPrefsModule.so:deskutils/preferences

BUILD_DEPENDS=	cddb-bundle>0:audio/cddb-bundle
RUN_DEPENDS=	cddb-bundle>0:audio/cddb-bundle

USES=		tar:bzip2 gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/CDPlayer-${PORTVERSION}

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/AudioCD.bundle/AudioCD \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/AudioCD.prefs/AudioCD \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/CDPlayer.app/CDPlayer

.include <bsd.port.mk>
