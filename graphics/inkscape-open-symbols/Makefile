PORTNAME=	inkscape-open-symbols
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	graphics

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	SVG symbol sets that can be used as Inkscape symbols
WWW=		https://github.com/PanderMusubi/inkscape-open-symbols

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	inkscape:graphics/inkscape

USE_GITHUB=	yes
GH_ACCOUNT=	PanderMusubi

DATADIR=	${PREFIX}/share/inkscape/symbols
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "-mindepth 2")

.include <bsd.port.mk>
