# Created by: Daniel O'Connor
# $FreeBSD$

PORTNAME=	teamspeak_client
PORTVERSION=	2.0.32
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.freenet.de/pub/4players/teamspeak.org/releases/:main \
		http://www.gsoft.com.au/~doconnor/:misc
DISTNAME=	ts2_client_rc2_2032
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main setduplexfake.so.gz:misc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client side of a group voice chat system

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	jpeg xorglibs
NO_BUILD=	yes

TSIMG=		${WRKSRC}/setup.data/image
TSHOME=		${PREFIX}/lib/teamspeak_client

SUB_FILES=	TeamSpeak
SUB_LIST=	TSHOME="${TSHOME}"

PORTDOCS=	*

DESKTOP_ENTRIES="TeamSpeak" \
		"Voice-chat with people" \
		"${TSHOME}/icon.xpm" \
		"TeamSpeak" \
		"Network;Telephony;" \
		false

post-extract:
	@${MKDIR} ${WRKDIR}/programs
	@${GZIP_CMD} -dc ${DISTDIR}/setduplexfake.so.gz >${WRKDIR}/programs/setduplexfake.so

post-patch:
	@${RM} -f ${TSIMG}/TeamSpeak
	@${MKDIR} ${WRKDIR}/doc
.for f in Readme.txt clicense.txt manual
	@${MV} -f ${TSIMG}/${f} ${WRKDIR}/doc
.endfor
.for f in TeamSpeak.bin lib*
	@${MV} ${TSIMG}/${f} ${WRKDIR}/programs
.endfor
	@${MKDIR} ${WRKDIR}/programs/client_sdk
.for f in lib* tsControl
	@${MV} ${TSIMG}/client_sdk/${f} ${WRKDIR}/programs/client_sdk
.endfor

do-install:
	cd ${TSIMG} && \
	${FIND} * -type d -exec ${MKDIR} "${TSHOME}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${TSHOME}/{}" \;
	cd ${WRKDIR}/programs && \
	${FIND} * -type d -exec ${MKDIR} "${TSHOME}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_PROGRAM} "{}" "${TSHOME}/{}" \;
	${INSTALL_SCRIPT} ${WRKDIR}/TeamSpeak ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	cd ${WRKDIR}/doc && \
	${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
