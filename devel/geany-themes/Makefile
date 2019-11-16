# $FreeBSD$

PORTNAME=	geany-themes
DISTVERSION=	1.24
CATEGORIES=	devel editors

MAINTAINER=	james.wright@digital-chaos.com
COMMENT=	Additional color schemes for the Geany IDE

LICENSE=	GPLv2+ BSD PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	geany:devel/geany

USE_GITHUB=	yes
GH_ACCOUNT=	geany

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/geany/colorschemes/
	${INSTALL_DATA} ${WRKSRC}/colorschemes/*.conf ${STAGEDIR}${PREFIX}/share/geany/colorschemes/

.include <bsd.port.mk>
