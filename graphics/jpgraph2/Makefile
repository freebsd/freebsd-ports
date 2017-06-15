# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jpgraph
PORTVERSION=	4.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://fossies.org/linux/www/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Draw both "quick and dirty" graphs with a minimum of code

LICENSE=	QPL
LICENSE_NAME=	Q PUBLIC LICENSE version 1.0
LICENSE_TEXT=	Please refer to: http://www.opensource.org/licenses/qtpl.php for details
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		php tar:bzip2
USE_PHP=	gd
NO_ARCH=	yes
NO_BUILD=	yes

NO_CDROM=	The free version cannot be used in a commercial context

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} '/TrueType/ s|// ||; \
		s|/usr/share/fonts/TrueType|${LOCALBASE}/share/fonts/dejavu|' \
		${WRKSRC}/src/jpg-config.inc.php

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} "*.php *.dat fonts lang themes" \
		${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${RM} ${WRKSRC}/src/Examples/jpgraph
	(cd ${WRKSRC}/src/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
