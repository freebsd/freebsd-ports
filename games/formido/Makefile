# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	formido
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.mhgames.org/files/formido/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D kill-em all with 3D rendered graphics

LICENSE=	GPLv2

USE_SDL=	sdl mixer image
USES=		gmake
MAKE_ARGS=	CC="${CXX}" DATDIR="${DATADIR}" DEFCONFIGDIR="${DATADIR}"

PLIST_FILES=	bin/${PORTNAME}

PORTDATA=	*
PORTDOCS=	*

pre-build:
	@${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cfg ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
