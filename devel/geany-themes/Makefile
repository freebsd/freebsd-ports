PORTNAME=	geany-themes
DISTVERSION=	1.24
PORTREVISION=	3
CATEGORIES=	devel editors

MAINTAINER=	james.wright@digital-chaos.com
COMMENT=	Additional color schemes for the Geany IDE
WWW=		https://www.geany.org/download/themes/

LICENSE=	BSD2CLAUSE GPLv2+ PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Themes have been included in the main geany distribution
EXPIRATION_DATE=2025-08-31

USE_GITHUB=	yes
GH_ACCOUNT=	geany

CONFLICTS_INSTALL=	geany

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/geany/colorschemes/
	${INSTALL_DATA} ${WRKSRC}/colorschemes/*.conf ${STAGEDIR}${PREFIX}/share/geany/colorschemes/

.include <bsd.port.mk>
