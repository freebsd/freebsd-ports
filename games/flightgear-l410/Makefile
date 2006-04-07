# New ports collection makefile for:	flightgear-l410
# Date created:				11 Dec 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-l410
PORTVERSION=	4.0
PORTREVISION=	1
MASTER_SITES=	http://javky.rozhled.cz/download/fgfsl410/:l410
DISTNAME=	FlightGear-${FGVERSION}
DISTFILES=	${DATADIST}:l410 ${SRCDIST}:l410
EXTRACT_ONLY=	FlightGear-${FGVERSION}${EXTRACT_SUFX} ${DATADIST}

COMMENT=	A simulation of the Turbolet L410 commuter aircraft

DATADIST=	l410-${FGVERSION}-v${PORTVERSION}${EXTRACT_SUFX}
SRCDIST=	l410-${FGVERSION}-src-v${PORTVERSION}${EXTRACT_SUFX}

MASTERDIR=	${.CURDIR}/../flightgear
MD5_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
PKGMESSAGE=	${WRKDIR}/.pkg-message

PLIST=		${WRKDIR}/.plist
PLIST_FILES=	bin/fgfs-l410

IGNORE=		is incompatible with the latest FlightGear release

post-extract:
	@cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${SRCDIST} ${EXTRACT_AFTER_ARGS}
	@${CAT} ${MASTERDIR}/pkg-message ${.CURDIR}/pkg-message > ${PKGMESSAGE}

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKDIR} && \
	${FIND} l410 -type f | ${SORT} \
		| ${SED} -e 's|^|share/FlightGear/Aircraft/|' >> ${PLIST} && \
	${FIND} -d l410 -type d \
		| ${SED} -e 's|^|@dirrm share/FlightGear/Aircraft/|' >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Main/fgfs ${PREFIX}/bin/fgfs-l410
	cd ${WRKDIR} && \
	${FIND} l410 -type d -exec \
		${MKDIR} "${PREFIX}/share/FlightGear/Aircraft/{}" \; && \
	${FIND} l410 -type f -exec \
		${INSTALL_DATA} "{}" "${PREFIX}/share/FlightGear/Aircraft/{}" \;

.include "${MASTERDIR}/Makefile"
