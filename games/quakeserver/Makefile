# New ports collection makefile for:	quakeserver
# Version required:			1.01
# Date created:				October 26th 1996
# Whom:					jfitz@FreeBSD.ORG
#
# $Id: Makefile,v 1.2 1996/10/28 19:16:36 jfitz Exp $
#

PKGNAME=	quakeserver-1.01
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.stomped.com/pub/idstuff/quake/ \
		ftp://ftp.stomped.com/pub/quake/x_linux/ \
		ftp://ftp1.idsoftware.com/idstuff/quake/ \
		ftp://ftp2.idsoftware.com/idsutff/quake/ \
		ftp://ftp.cdrom.com/pub/idgames/idstuff/quake/ \
		ftp://quake.best.com/pub/idsoftware/quake/ \
		ftp://ftp.nuqneH.org/pub/quake/idsoftware/ \
		ftp://PC/games/DOOM/idstuff/quake/ \
		ftp://ftp.sun.ac.za/pub/msdos/idgames/idstuff/quake/ \
		ftp://iconz.co.nz/pub/quake/

DISTFILES=	quake101.zip \
		quake-FreeBSD.tar.gz \
		intel_linux_quake101.tgz

MAINTAINER=	jfitz@freebsd.org

FETCH_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		lha:${PORTSDIR}/archivers/lha

RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect \
		/compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

# Uncomment the next line to include the QuakeC compiler port as well
#RUN_DEPENDS+=	qcc:${PORTSDIR}/games/qcc

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
NO_CDROM=	YES

do-extract:
		@ ${MKDIR} -p work/quake
		@ ${MKDIR} -p work/server
		unzip -o ${DISTDIR}/quake101.zip -d ${WRKDIR}/quake QSW101.?
		@ cat ${WRKDIR}/quake/QSW101.[1-7] > ${WRKDIR}/quake/resource.exe
		cd ${WRKDIR}/quake; lha xf resource.exe id1/pak0.pak
		@ cd ${WRKDIR}/server; tar zxf ${DISTDIR}/quake-FreeBSD.tar.gz
		@ cd ${WRKDIR}/server/quake; tar zxf ${DISTDIR}/intel_linux_quake101.tgz

do-install:
		@ ${MKDIR} -p ${PREFIX}/quakeserver
		@ ${MKDIR} -p ${PREFIX}/quakeserver/id1
		for file in ${WRKDIR}/quake/id1/*; do \
			${INSTALL_DATA} $$file ${PREFIX}/quakeserver/id1; \
		done
		${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${WRKDIR}/server/quake/xquake ${PREFIX}/quakeserver
		${INSTALL_PROGRAM} ${WRKDIR}/server/quake/qstat ${PREFIX}/quakeserver; \
		${INSTALL_DATA} ${WRKDIR}/server/quake/README.FreeBSD ${PREFIX}/quakeserver
		for file in qsrv qsrv.expect qslog; do \
			${INSTALL_SCRIPT} ${WRKDIR}/server/quake/$$file ${PREFIX}/quakeserver; \
		done
		
.include <bsd.port.mk>
