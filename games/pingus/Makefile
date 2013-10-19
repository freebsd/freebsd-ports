# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pingus
PORTVERSION=	0.7.2
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://pingus.seul.org/files/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Lemmings-like game

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libboost_regex.so:${PORTSDIR}/devel/boost-libs \
		libphysfs.so:${PORTSDIR}/devel/physfs

USE_BZIP2=	yes
USES=		iconv
USE_SCONS=	yes
SCONS_ARGS=	with_linuxusbmouse=0 \
		with_linuxevdev=0
USE_SDL=	sdl image mixer

DESKTOP_ENTRIES="Pingus" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"pingus" "" "false"

PLIST=		${WRKDIR}/pkg-plist

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|add_path("data")|add_path("${DATADIR}")|g' \
		${WRKSRC}/src/pingus_main.cpp

pre-install:
	@${RM} -f ${PLIST}
	@${ECHO_CMD} "bin/${PORTNAME}" >> ${PLIST}
	@${ECHO_CMD} "share/pixmaps/${PORTNAME}.ico" >> ${PLIST}
	@cd ${WRKSRC}/data && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/data && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/win32/icon1.ico ${PREFIX}/share/pixmaps/${PORTNAME}.ico

.include <bsd.port.mk>
