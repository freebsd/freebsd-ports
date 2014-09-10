# $FreeBSD$

PORTNAME=	toolbox
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://ftp.azc.uam.mx/mirrors/gnu/savannah/files/toolbox/Release.pkg/0.8/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
PKGNAMESUFFIX=	kit${PKGNAMESUFFIX2}
DISTNAME=	Toolbox-${PORTVERSION}

LICENSE=	GPLv2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolbox bundle for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Toolbox
USE_GNUSTEP_MAKE_DIRS+=	Toolbox

.include <bsd.port.mk>
