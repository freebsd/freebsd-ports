# New ports collection makefile for:    linux_nwnclient
# Date created:         1 April 2003
# Whom:                 Erik Olson <erikolson@olsonexpress.com>
#
# $FreeBSD$
#

PORTNAME=	linux_nwnclient
PORTVERSION=	1.30
CATEGORIES=	games linux
MASTER_SITES=	http://nwdownloads.bioware.com/neverwinternights/linux/${PORTVERSION:S/.//}/ \
		http://nwdownloads.bioware.com/neverwinternights/linux/129/
DISTFILES=	nwclient129.tar.gz linuxclientupdate129to${PORTVERSION:S/.//}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Neverwinter Nights Linux (x86) Client

RUN_DEPENDS=	/compat/linux/usr/games/nwn/nwm:${PORTSDIR}/games/nwndata \
		/compat/linux/usr/X11R6/lib/libGL.so.1.2:${PORTSDIR}/graphics/linux_dri

USE_LINUX=	yes
USE_LINUX_PREFIX=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
NWNDIR=		usr/games/nwn
WRKSRC=		${WRKDIR}
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755
PLIST_SUB+=	NWNDIR="${NWNDIR}"
# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

do-install:
	${INSTALL_DIR} ${PREFIX}/${NWNDIR}
	${INSTALL_DIR} ${PREFIX}/${NWNDIR}/miles
	${INSTALL_DIR} ${PREFIX}/${NWNDIR}/override
	${INSTALL_DIR} ${PREFIX}/${NWNDIR}/lib
	${INSTALL_DIR} ${PREFIX}/${NWNDIR}/nwm
	${INSTALL_DIR} ${PREFIX}/${NWNDIR}/data
.for f in nwmain nwserver
	${INSTALL_PROGRAM} ${WRKDIR}/${f} ${PREFIX}/${NWNDIR}
.endfor
.for f in dmclient fixinstall nwn
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/${NWNDIR}
.endfor
.for f in nwn.ini movies-OC.txt dialog.tlk patch.key
	${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/${NWNDIR}
.endfor
.for f in miles/mssdsp.flt miles/mssmp3.asi miles/msssoft.m3d miles/libmss.so.6.5.2 miles/libmss.so.6 miles/libmss.so
	${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/${NWNDIR}/miles
.endfor
.for f in data/patch.bif
	${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/${NWNDIR}/data
.endfor
.for f in nwm/Chapter1.nwm nwm/Chapter1E.nwm nwm/Chapter2.nwm nwm/Chapter3.nwm nwm/Prelude.nwm
	${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/${NWNDIR}/nwm
.endfor
.for f in override/soundprovider.2da override/load_legal2.tga override/load_legal.tga
	# Removed - override/gui_srv_lst_pnl.tga
	${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/${NWNDIR}/override
.endfor
.for f in lib/libSDL-1.2.so.0 lib/libSDL-1.2.so.0.0.5
	${INSTALL_PROGRAM} ${WRKDIR}/${f} ${PREFIX}/${NWNDIR}/lib
.endfor
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in readme.txt readme-SDL.txt EULA.txt NWNv130.txt readme.linuxserver.txt
	${INSTALL_DATA} ${WRKDIR}/${f} ${DOCSDIR}
.endfor
.endif
#	cd ${PREFIX}/${NWNDIR}/ ; /compat/linux/bin/bash ./fixinstall
	${CHOWN} -R root:games ${PREFIX}/${NWNDIR}/
	${CHMOD} -R 775 ${PREFIX}/${NWNDIR}/

.include <bsd.port.mk>
