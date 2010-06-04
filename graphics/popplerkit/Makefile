# New ports collection makefile for:    popplerkit
# Date created:         21 Jan 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	popplerkit
PORTVERSION=	1.0.1
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/etoile/
DISTNAME=	etoile-0.4.1

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Framework that supports rendering of PDF content

LIB_DEPENDS=	poppler:${PORTSDIR}/graphics/poppler

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_GNOME=	gnomeprefix gnomehack gtk20

WRKSRC=	${WRKDIR}/Etoile-0.4.1
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/PopplerKit

.include <bsd.port.mk>
