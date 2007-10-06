# New ports collection makefile for:	pingus
# Date created:		2007-10-05
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pingus
PORTVERSION=	0.7.1
CATEGORIES=	games
MASTER_SITES=	http://pingus.seul.org/files/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Lemmings-like game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		boost_regex.4:${PORTSDIR}/devel/boost \
		physfs-1.0.1:${PORTSDIR}/devel/physfs

USE_BZIP2=	yes
USE_ICONV=	yes
USE_SCONS=	yes
USE_SDL=	sdl image mixer

PLIST=          ${WRKDIR}/pkg-plist
SUB_FILES=	pkg-message

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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
