# ports collection makefile for:	linrad
# Date created:		7 July 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	linrad
PORTVERSION=	2.14
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.nitehawk.com/sm5bsz/linuxdsp/archive/
DISTNAME=	lir02-14
EXTRACT_SUFX=	.tbz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio DSP utility (SDR)

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

WRKSRC=		${WRKDIR}/${PORTNAME}-02.14

USE_AUTOTOOLS=	autoconf:253
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
ONLY_FOR_ARCHS=	i386

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	-e 's|%%X11BASE%%|${X11BASE}|g' \
	-e 's|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}/|' \
		${WRKSRC}/help.c
do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/errors.lir ${DATADIR}/errors.lir
	${INSTALL_DATA} ${WRKSRC}/help.lir ${DATADIR}/help.lir
#	${INSTALL_PROGRAM} -m04555 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} -m04555 ${WRKSRC}/x${PORTNAME} ${PREFIX}/bin/x${PORTNAME}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/z_APM.txt ${DOCSDIR}/z_APM.txt
	${INSTALL_DATA} ${WRKSRC}/z_BUFFERS.txt ${DOCSDIR}/z_BUFFERS.txt
	${INSTALL_DATA} ${WRKSRC}/z_CALIBRATE.txt ${DOCSDIR}/z_CALIBRATE.txt
	${INSTALL_DATA} ${WRKSRC}/z_COPYRIGHT.txt ${DOCSDIR}/z_COPYRIGHT.txt
	${INSTALL_DATA} ${WRKSRC}/z_GIFINFO.txt ${DOCSDIR}/z_GIFINFO.txt
	${INSTALL_DATA} ${WRKSRC}/z_MLOCK.txt ${DOCSDIR}/z_MLOCK.txt
	${INSTALL_DATA} ${WRKSRC}/z_MOUSE.txt ${DOCSDIR}/z_MOUSE.txt
	${INSTALL_DATA} ${WRKSRC}/z_PARALLEL_PORT.txt ${DOCSDIR}/z_PARALLEL_PORT.txt
	${INSTALL_DATA} ${WRKSRC}/z_SETTINGS.txt ${DOCSDIR}/z_SETTINGS.txt
	${INSTALL_DATA} ${WRKSRC}/z_USERS_EXTRA.txt ${DOCSDIR}/z_USERS_EXTRA.txt
	${INSTALL_DATA} ${WRKSRC}/z_USERS_HWARE.txt ${DOCSDIR}/z_USERS_HWARE.txt
	${INSTALL_DATA} ${WRKSRC}/z_USLEEP.txt ${DOCSDIR}/z_USLEEP.txt
	@${ECHO} ""
	@${ECHO} "linrad docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
