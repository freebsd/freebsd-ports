# New ports collection makefile for:    gworkspace-gwmetadata
# Date created:         30 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gworkspace
PORTVERSION=	0.8.3
CATEGORIES=	deskutils
MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/
PKGNAMESUFFIX=	-gwmetadata${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GWMetadata for GNUstep workspace manager

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	DBKit:${GWORKSPACE_PORT}
USE_GNUSTEP_SYSTEM_LIBS+=	PreferencePanes:${PREFERENCEPANES_PORT}
USE_GNUSTEP_LDCONFIG=	${SYSTEMLIBDIR}

USE_SQLITE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

WRKSRC=		${WRKDIR}/GWorkspace-${PORTVERSION}/GWMetadata
CONFIGURE_ARGS+=	--with-sqlite-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-sqlite-library=${LOCALBASE}/lib
CONFIGURE_ENV+=		LDFLAGS="${LDFLAGS}"

GWORKSPACE_PORT?=	deskutils/gworkspace
PREFERENCEPANES_PORT?=	deskutils/preferencepanes

.include <bsd.port.mk>
