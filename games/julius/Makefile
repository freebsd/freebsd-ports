# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	julius
PORTVERSION=	g20180430
CATEGORIES=	games

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Open source re-implementation of Caesar III

LICENSE=	GPLv3

USES=		cmake:outsource

USE_GITHUB=	yes
GH_ACCOUNT=	bvschaik
GH_TAGNAME=	cb7ecdf

USE_SDL=	mixer2 sdl2

SUB_FILES=	julius pkg-message

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
