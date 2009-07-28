# New ports collection makefile for:	pingus
# Date created:		2007-10-05
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pingus
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://pingus.seul.org/files/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Lemmings-like game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		boost_regex.4:${PORTSDIR}/devel/boost-libs \
		physfs.1:${PORTSDIR}/devel/physfs

USE_BZIP2=	yes
USE_ICONV=	yes
USE_SCONS=	yes
SCONS_ARGS=	with_linuxusbmouse=0 \
		with_linuxevdev=0
USE_SDL=	sdl image mixer

PLIST=		${WRKDIR}/pkg-plist

post-patch:
	@${REINPLACE_CMD} -e 's|add_path("data")|add_path("${DATADIR}")|g' \
		${WRKSRC}/src/pingus_main.cpp

pre-install:
	@${RM} -f ${PLIST}
	@${ECHO_CMD} "bin/${PORTNAME}" >> ${PLIST}
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

.include <bsd.port.mk>
