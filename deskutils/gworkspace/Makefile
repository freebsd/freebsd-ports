# New ports collection makefile for:    gworkspace
# Date created:         04 Feb 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gworkspace
PORTVERSION=	0.8.4
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep workspace manager

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

WRKSRC=		${WRKDIR}/GWorkspace-${PORTVERSION}
GNU_CONFIGURE=	yes
ADDITIONAL_LDFLAGS+=	-L${WRKSRC}/FSNode/FSNode.framework/Versions/A
DEFAULT_LIBVERSION2=	0.1.0
PLIST_SUB+=	LIBVERSION2=${DEFAULT_LIBVERSION2}
PLIST_SUB+=	MAJORLIBVERSION2=${DEFAULT_LIBVERSION2:C/([0-9]).*/\1/1}
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR="${GNUSTEP_SYSTEM_ROOT}"

.if defined(WITHOUT_GHOSTSCRIPT)
PLIST_SUB+=	PDFVIEW="@comment "
.else
PLIST_SUB+=	PDFVIEW=""
USE_GHOSTSCRIPT=	yes
.endif

post-install:
	${CP} ${WRKSRC}/Inspector/ContentViewersProtocol.h \
		${GNUSTEP_SYSTEM_ROOT}/Library/Frameworks/Inspector.framework/Versions/A/Headers/ContentViewersProtocol.h

.include <bsd.port.mk>
