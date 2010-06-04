# New ports collection makefile for:    gworkspace-gwmetadata
# Date created:         30 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gworkspace
PORTVERSION=	0.8.7
PORTREVISION=	1
CATEGORIES=	deskutils gnustep
#MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	usr-apps
PKGNAMESUFFIX=	-gwmetadata${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GWMetadata for GNUstep workspace manager

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	DBKit:${GWORKSPACE_PORT}
USE_GNUSTEP_SYSTEM_LIBS+=	PreferencePanes:${PREFERENCEPANES_PORT}
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

USE_SQLITE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

UNIQUENAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/gworkspace-${PORTVERSION}/GWMetadata
CONFIGURE_ARGS+=	--with-sqlite-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-sqlite-library=${LOCALBASE}/lib
CONFIGURE_ENV+=		LDFLAGS="${LDFLAGS}"
DEFAULT_LIBVERSION=	0.1.0

GWORKSPACE_PORT?=	deskutils/gworkspace
PREFERENCEPANES_PORT?=	deskutils/preferencepanes

post-patch:
	${CP} ${WRKSRC}/gmds/mdextractor/Extractors/JpegExtractor/GNUmakefile.in \
		${WRKSRC}/gmds/mdextractor/Extractors/JpegExtractor/GNUmakefile
	${CP} ${FILESDIR}/Preferences-GNUmakefile \
		${WRKSRC}/Preferences/GNUmakefile
	${CP} ${FILESDIR}/MDFinder-GNUmakefile \
		${WRKSRC}/MDFinder/GNUmakefile

.include <bsd.port.mk>
