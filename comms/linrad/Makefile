# ports collection makefile for:	linrad
# Date created:		7 July 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	linrad
PORTVERSION=	0.16a
CATEGORIES=	comms
MASTER_SITES=	http://www.nitehawk.com/sm5bsz/linuxdsp/archive/
DISTNAME=	lir01-20
EXTRACT_SUFX=	.tbz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio DSP utility (SDR)

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

WRKSRC=		${WRKDIR}/${PORTNAME}-01.20

USE_AUTOCONF_VER=	253
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/configure.in

do-install:
	${INSTALL_PROGRAM} -m04555 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/z_APM.txt ${DOCSDIR}/z_APM.txt
	${INSTALL_DATA} ${WRKSRC}/z_BUFFERS.txt ${DOCSDIR}/z_BUFFERS.txt
	${INSTALL_DATA} ${WRKSRC}/z_CALIBRATE.txt ${DOCSDIR}/z_CALIBRATE.txt
	${INSTALL_DATA} ${WRKSRC}/z_COPYRIGHT.txt ${DOCSDIR}/z_COPYRIGHT.txt
	${INSTALL_DATA} ${WRKSRC}/z_GIFINFO.txt ${DOCSDIR}/z_GIFINFO.txt
	${INSTALL_DATA} ${WRKSRC}/z_INSTALL.txt ${DOCSDIR}/z_INSTALL.txt
	${INSTALL_DATA} ${WRKSRC}/z_MLOCK.txt ${DOCSDIR}/z_MLOCK.txt
	${INSTALL_DATA} ${WRKSRC}/z_SETTINGS.txt ${DOCSDIR}/z_SETTINGS.txt
	${INSTALL_DATA} ${WRKSRC}/z_SPEED.txt ${DOCSDIR}/z_SPEED.txt
	${INSTALL_DATA} ${WRKSRC}/z_SVGALIB.txt ${DOCSDIR}/z_SVGALIB.txt
	${INSTALL_DATA} ${WRKSRC}/z_USERS_HWARE.txt ${DOCSDIR}/z_USERS_HWARE.txt
	${INSTALL_DATA} ${WRKSRC}/z_USLEEP.txt ${DOCSDIR}/z_USLEEP.txt
	@${ECHO} ""
	@${ECHO} "linrad docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
