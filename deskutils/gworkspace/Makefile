# New ports collection makefile for:    gworkspace
# Date created:         04 Feb 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gworkspace
PORTVERSION=	0.5.3
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

.ifdef WITHOUT_GHOSTSCRIPT
PLIST_SUB+=	PDFVIEW="@comment "
.else
.if defined(WITH_GHOSTSCRIPT_AFP1)
GSPORT?=	print/ghostscript-afp1
.else
GSPORT?=	print/ghostscript-gnu
.endif
BUILD_DEPENDS+=	gs:${PORTSDIR}/${GSPORT}
RUN_DEPENDS+=	gs:${PORTSDIR}/${GSPORT}
PLIST_SUB+=	PDFVIEW=""
.endif

.include <bsd.port.pre.mk>

USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
.include "${PORTSDIR}/devel/gnustep/bsd.gnustep.mk"

.include <bsd.port.post.mk>
