# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dangerdeep-data
PORTVERSION=	0.3.0
CATEGORIES=	games
MASTER_SITES=	SF/dangerdeep/danger_from_the_deep-data/${PORTVERSION}
DIST_SUBDIR=	dangerdeep

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Danger from the Deep data files

LICENSE=	CC-BY-NC-ND-2.5
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/data
DATADIR=	${PREFIX}/share/dangerdeep
PORTDATA=	*

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
