# New ports collection makefile for:    gworkspace
# Date created:         04 Feb 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gworkspace
PORTVERSION=	0.5.2
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
MAKEFILE=	GNUmakefile
ALL_TARGET=

.ifdef WITHOUT_GHOSTSCRIPT
PLIST_SUB+=	PDFVIEW="@comment "
.else
BUILD_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript-gnu
RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript-gnu
PLIST_SUB+=	PDFVIEW=""
.endif

.include <bsd.port.pre.mk>

USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
.include "${PORTSDIR}/devel/gnustep/bsd.gnustep.mk"

.include <bsd.port.post.mk>
