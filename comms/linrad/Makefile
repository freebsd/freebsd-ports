# ports collection makefile for:	linrad
# Date created:		7 July 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	linrad
PORTVERSION=	2.20
CATEGORIES=	comms
MASTER_SITES=	http://www.nitehawk.com/sm5bsz/linuxdsp/archive/\
		http://g7rau.demon.co.uk/sm5bsz/linuxdsp/archive/\
		http://www.sm5bsz.com/linuxdsp/archive/
DISTNAME=	lir02-20
EXTRACT_SUFX=	.tbz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio DSP utility (SDR)

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

WRKSRC=		${WRKDIR}/${PORTNAME}-02.20

USE_AUTOTOOLS=	autoconf:253
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
ALL_TARGET=	xlinrad
USE_X_PREFIX=	yes
ONLY_FOR_ARCHS=	i386
X11_PATCHFILES=	Makefile.in help.c xmain.c

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	-e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}/|' \
		${WRKSRC}/help.c
.for f in ${X11_PATCHFILES}
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/${f}
.endfor

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/errors.lir ${DATADIR}/errors.lir
	${INSTALL_DATA} ${WRKSRC}/help.lir ${DATADIR}/help.lir
	${INSTALL_SCRIPT} -m04555 ${FILESDIR}/linrad ${PREFIX}/bin/linrad
# Some day we may want the svga version as well.
#	${INSTALL_PROGRAM} -m04555 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}.svga
	${INSTALL_PROGRAM} -m04555 ${WRKSRC}/x${PORTNAME} ${PREFIX}/bin/x${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/z_APM.txt ${DOCSDIR}/z_APM.txt
	${INSTALL_DATA} ${WRKSRC}/z_BUFFERS.txt ${DOCSDIR}/z_BUFFERS.txt
	${INSTALL_DATA} ${WRKSRC}/z_CALIBRATE.txt ${DOCSDIR}/z_CALIBRATE.txt
	${INSTALL_DATA} ${WRKSRC}/z_COPYRIGHT.txt ${DOCSDIR}/z_COPYRIGHT.txt
	${INSTALL_DATA} ${WRKSRC}/z_GIFINFO.txt ${DOCSDIR}/z_GIFINFO.txt
	${INSTALL_DATA} ${WRKSRC}/z_MOUSE.txt ${DOCSDIR}/z_MOUSE.txt
	${INSTALL_DATA} ${WRKSRC}/z_MOUSE.txt ${DOCSDIR}/z_PARALLEL_PORT.txt
	${INSTALL_DATA} ${WRKSRC}/z_MOUSE.txt ${DOCSDIR}/z_SETTINGS.txt
	${INSTALL_DATA} ${WRKSRC}/z_MOUSE.txt ${DOCSDIR}/z_USERS_EXTRA.txt
	${INSTALL_DATA} ${WRKSRC}/z_MOUSE.txt ${DOCSDIR}/z_USERS_HWARE.txt
	${INSTALL_DATA} ${WRKSRC}/z_USLEEP.txt ${DOCSDIR}/z_USLEEP.txt
	@${ECHO} ""
	@${ECHO} "linrad docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
