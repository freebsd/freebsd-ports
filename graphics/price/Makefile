# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	price
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	graphics gnustep
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	PRICE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image filtering and manipulation using GNUstep

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

DATADIR=	${GNUSTEP_LOCAL_APPS}/PRICE.app
PORTDATA=	*
PLIST_FILES=	${GNUSTEP_LOCAL_TOOLS}/PRICE \
		share/applications/PRICE.desktop

post-build:
	${SED} -i '' -e '/^Categories/s/=/&Graphics;/' \
 		${WRKSRC}/PRICE.app/Resources/PRICE.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/PRICE
	${LN} -sf ${DATADIR}/Resources/PRICE.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
