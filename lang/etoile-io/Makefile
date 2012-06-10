# New ports collection makefile for:    etoile-io
# Date created:         19 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	io
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	lang gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Etoile Project Io Language

PORTSCOUT=	limit:^0\.2

DEPRECATED=	API no longer supported
EXPIRATION_DATE=	2012-07-20

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	DistributedView:${DISTRIBUTEDVIEW_PORT}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Languages/Io
HEADER_DIR=	Local/Library/Headers/Io
PLIST_FILES=	GNUstep/Local/Tools/ioobjc

DISTRIBUTEDVIEW_PORT?=	deskutils/etoile-distributedview

post-patch:
	${REINPLACE_CMD} -e 's|^inline|static inline|' \
		${WRKSRC}/Languages/Io/iovm/IoState_inline.h

.include <bsd.port.mk>
