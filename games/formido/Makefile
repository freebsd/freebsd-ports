# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	formido
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://www.mhgames.org/files/formido/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D kill-em all with 3D rendered graphics

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL_license.txt

USE_SDL=	sdl mixer image
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CXX}" DATDIR="${DATADIR}" DEFCONFIGDIR="${DATADIR}"

PLIST_FILES=	bin/${PORTNAME}

PORTDATA=	*
PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

pre-build:
	@${MKDIR} ${WRKSRC}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/formido ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.if !defined(NOPORTDATA)
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} '*' ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/formido.cfg ${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
