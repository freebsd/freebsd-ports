# New ports collection makefile for:	Counter Strike Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME?=	cs
PORTVERSION?=	1.1c
CATEGORIES=	games linux
MASTER_SITES?=	ftp://ftp.icrontic.com/pub/ \
		http://flf.playnet.com/ \
		http://ftp2.gamespy.com/pub/cdrom/counter-strike/ \
		ftp://fileplanet.ngi.it/fileplanet2/counter-strike/ \
		ftp://ftp.fasta.fh-dortmund.de/gdi/halflife/counterstrike/ \
		http://www.death-match.com/fr/download/fichiers/halflife/mods/ \
		ftp://ftp.icsmedia.de/pub/games/halflife/counter_strike/linux_server/ \
		http://ftp1download.gamespy.com/fileplanet/fpnew/action/half-life/modifications/cstrike/ \
		http://fileplanet.games-world.net/dl/ftp1.gamespy.com/fpnew/action/half-life/modifications/cstrike/ \
		ftp://fileplanet.blueyonder.co.uk/ftp1.gamespy.com/fpnew/action/half-life/modifications/cstrike/ \
PKGNAMEPREFIX=	hlserver-
.ifndef(DISTNAME)
DISTFILES?=	cs_11b_full.tar.gz cs_11c_up.tar.gz
.endif

MAINTAINER?=	pat@databits.net

RUN_DEPENDS=	${LINUXBASE}${HLDSDIR}${HL_PROGRAM}:${HALFLIFESERVER_PORT}

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
WRKSRC?=		${WRKDIR}/cstrike
PLIST_SUB+=	${PLIST_SUB_MASTER}

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
SORT?=		/usr/bin/sort

HALFLIFESERVER_PORT=	${.CURDIR}/../halflifeserver
HLDSDIR!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V HLDSDIR
HL_PROGRAM!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V HL_PROGRAM
PLIST_SUB_MASTER!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V PLIST_SUB_FOR_THIS_PORT

pre-patch:
# remove trailing ^M
.for file in *.cfg */*.cfg *.gam */*.gam *.htm */*.htm \
	*.inf */*.inf *.lst */*.lst *.sc */*.sc \
	*.scr */*.scr *.txt */*.txt
	@${PERL} -pi -ne 's!\r\n!\n!' ${WRKDIR}/${file} >/dev/null 2>/dev/null
.endfor

# if you change the PLIST, please re-think the following
# Parses PLIST
# creates dirs from @dirrm entries
# copies files from non ^@ entries
do-install: install-parse-plist install-run-scripts
# scan libraries
	@( cd ${HALFLIFESERVER_PORT} ; ${MAKE} scan-libs )

# kaboom, ashes to ashes, .... The problem is dead :)
# Contributed by <lioux@FreeBSD.org>
install-parse-plist: generate-plist
	@${PERL} -e 'open(FHANDLER,"${TMPPLIST}");' \
		-e 'open(FDIR,">${WRKDIR}/dirs.sh.tmp");' \
		-e 'open(FFILES,">${WRKDIR}/files.sh");' \
		-e 'while (!eof(FHANDLER)) {' \
			-e 'chop($$file = <FHANDLER>);' \
			-e '$$dir = $$file_partial = $$file;' \
			-e '$$file_partial =~ s!^${HLDSDIR:S!^/!!}!!;' \
			-e 'print FDIR "${INSTALL_DIR}", \
				" ", "\"${PREFIX}/$$dir\"", \
				"\n" if $$dir =~ s!(^\@dirrm\s+)!!;' \
			-e 'print FFILES "${INSTALL_DATA}", \
				" ", "\"${WRKDIR}/$$file_partial\"", \
				" ", "\"${PREFIX}/$$file\"", \
				"\n" if ($$file !~ m!^\@!);' \
		-e '}' \
		-e 'close(FFILES);' \
		-e 'close(FDIR);' \
		-e 'close(FHANDLER);'
# we want it sorted
	@${SORT} ${WRKDIR}/dirs.sh.tmp > ${WRKDIR}/dirs.sh

install-run-scripts:
.for script in dirs files
	@${SH} ${WRKDIR}/${script}.sh
.endfor

.include <bsd.port.mk>
