# $FreeBSD$

PORTNAME=	toolbox
PORTVERSION=	0.8
PORTREVISION=	7
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://ftp.azc.uam.mx/mirrors/gnu/savannah/files/toolbox/Release.pkg/0.8/ \
		LOCAL/dinoex
PKGNAMESUFFIX=	kit${PKGNAMESUFFIX2}
DISTNAME=	Toolbox-${PORTVERSION}

LICENSE=	GPLv2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolbox bundle for GNUstep

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Toolbox/Toolbox

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Libraries/libToolbox.so

.include <bsd.port.mk>
