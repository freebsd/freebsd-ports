# New ports collection makefile for:    Half-Life Dedicated Server
# Date created:				Sat Jul 15 14:27:16 SAST 2000
# Whom:					markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hlds
PORTVERSION=	3.1.0.6
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://ftp1download.gamespy.com/fileplanet/fpnew/action/half-life/official/ \
		http://www.jetstreamgames.co.nz/files/pub/gamespyftp1/fpnew/action/half-life/official/ \
		ftp://ftp.fasta.fh-dortmund.de/gdi/halflife/server/linux/ \
		ftp://fileplanet.ngi.it/fileplanet/fpnew/action/half-life/official/ \
		ftp://ftp.gmd.de/people/cla/hl/hl-newest/linux/ \
		ftp://ftp.icsmedia.de/pub/games/halflife/hl_server/
DISTNAME=	hlds_l3106

MAINTAINER=	pat@databits.net

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/hlds_l
PLIST_SUB=	${PLIST_SUB_FOR_THIS_PORT}
PLIST_SUB_FOR_THIS_PORT=	HLDSDIR="${HLDSDIR:S/^\///}" LDCONFIG="${LDCONFIG_LINUX}"

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
LDCONFIG_LINUX=	${LINUXBASE}/sbin/ldconfig

HLDSDIR=	/usr/games/hlds_l/
HL_DIRS=	valve/maps valve/events valve/dlls valve/cl_dlls \
		tfc/tfstats tfc/sound/weapons tfc/sound/vox \
		tfc/sound/misc tfc/models/player/spy \
		tfc/models/player/soldier tfc/models/player/sniper \
		tfc/models/player/scout tfc/models/player/pyro \
		tfc/models/player/medic tfc/models/player/hvyweapon \
		tfc/models/player/engineer tfc/models/player/demo \
		tfc/models/player/civilian tfc/maps tfc/manual \
		tfc/events/wpn tfc/events/misc tfc/events/explode \
		tfc/events/door tfc/dlls tfc/cl_dlls
HL_PROGRAM=	hlds_run

pre-patch:
# remove trailing ^M
.for file in *.cfg */*.cfg *.gam */*.gam *.htm */*.htm \
	*.inf */*.inf *.lst */*.lst *.sc */*.sc \
	*.scr */*.scr *.txt */*.txt
	@${PERL} -pi -ne 's!\r\n!\n!' ${WRKSRC}/${file} >/dev/null 2>/dev/null
.endfor

do-install: install-files scan-libs

install-files:
# directories
.for directory in ${HL_DIRS}
	@${INSTALL_DIR} ${PREFIX}${HLDSDIR}${directory}
.endfor
# if you change the PLIST, please re-think the following
# files
	@for file in `${SED} -E -e "s!^\@.+!!" -e "s!%%HLDSDIR%%!!" ${PLIST}` ;\
	do \
		${INSTALL_DATA} ${WRKSRC}/$${file} ${PREFIX}${HLDSDIR}$${file} ;\
	done
# trim/set permissions
	@${CHMOD} ${BINMODE} ${PREFIX}${HLDSDIR}${HL_PROGRAM}
# libraries
# this should go in a pkg-install, should be checked later
	@if ! (${GREP} -E \"^${HLDSDIR}$$\" ${PREFIX}/etc/ld.so.conf >/dev/null 2>/dev/null) ;\
	then \
		${ECHO} ${HLDSDIR} >> ${PREFIX}/etc/ld.so.conf ;\
	fi

scan-libs:
	@${LDCONFIG_LINUX}

.include <bsd.port.mk>
