# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	price
PORTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	graphics gnustep
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	PRICE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image filtering and manipulation using GNUstep

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gnustep

USE_GNUSTEP=	back build

DATADIR=	${GNUSTEP_SYSTEM_ROOT}/Applications/PRICE.app
PORTDATA=	*
PLIST_FILES=	${GNUSTEP_SYSTEM_TOOLS}/PRICE \
		share/applications/PRICE.desktop

post-build:
	${SED} -i '' -e '/^Categories/s/=/&Graphics;/' \
		${WRKSRC}/PRICE.app/Resources/PRICE.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/PRICE
	${LN} -sf ${DATADIR}/Resources/PRICE.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
