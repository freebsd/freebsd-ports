# New ports collection makefile for:    gworkspace
# Date created:         04 Feb 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gworkspace
PORTVERSION=	0.6.3
CATEGORIES=	deskutils
MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/ \
		http://www.imago.ro/gworkspace/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep workspace manager

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/GWorkspace-${PORTVERSION}
GUN_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.if defined(WITHOUT_GHOSTSCRIPT)
PLIST_SUB+=	PDFVIEW="@comment "
.else
PLIST_SUB+=	PDFVIEW=""
USE_GHOSTSCRIPT=	yes
.endif

.include <bsd.port.mk>
