# New ports collection makefile for:    Half-Life Dedicated Server
# Date created:				Sat Jul 15 14:27:16 SAST 2000
# Whom:					markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	HLDS
PORTVERSION=	3.1.0.6
CATEGORIES=	games linux
MASTER_SITES=	http://204.213.190.22/downloads/ \
		http://ftp1download.gamespy.com/fileplanet/fpnew/action/half-life/official/ \
		http://www.jetstreamgames.co.nz/files/pub/gamespyftp1/fpnew/action/half-life/official/ \
		ftp://ftp.fasta.fh-dortmund.de/gdi/halflife/server/linux/ \
		ftp://fileplanet.ngi.it/fileplanet/fpnew/action/half-life/official/ \
		ftp://ftp.gmd.de/people/cla/hl/hl-newest/linux/ \
		ftp://ftp.icsmedia.de/pub/games/halflife/hl_server/
DISTNAME=	hlds_l3106
EXTRACT_ONLY=

MAINTAINER=	pat@databits.net

BUILD_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
PREFIX=		/compat/linux
WRKSRC=		${WRKDIR}/hlds_l
EXTRACT_ONLY_1=	hlds_l3106.tar.gz

HLDSDIR=	/usr/games/hlds_l

do-install:
	@cd ${PREFIX}/usr/games ;\
	for file in ${EXTRACT_ONLY_1}; do \
		if ! (${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$${file} ${EXTRACT_AFTER_ARGS}) ;\
		then \
			exit 1 ;\
		fi \
	done
	@cd ${PREFIX}${HLDSDIR} ;\
	for file in ${EXTRACT_ONLY_2}; do \
		if ! (${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$${file} ${EXTRACT_AFTER_ARGS}) ;\
		then \
			exit 1 ;\
		fi \
	done

	if ! (cat ${PREFIX}/etc/ld.so.conf | ${GREP} ${HLDSDIR}) ;\
	then \
		${ECHO} ${HLDSDIR} >> ${PREFIX}/etc/ld.so.conf ;\
	fi

	${PREFIX}${SH} -c ${LDCONFIG}

.include <bsd.port.mk>
