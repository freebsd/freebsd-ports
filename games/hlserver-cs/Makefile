# New ports collection makefile for:	Counter Strike Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME?=	cs
PORTVERSION?=	1.1b
CATEGORIES=	games linux
MASTER_SITES?=	ftp://ftp.icrontic.com/pub/ \
		http://flf.playnet.com/
PKGNAMEPREFIX=	hlserver-
DISTNAME?=	cs_11b_full

MAINTAINER?=	pat@databits.net

RUN_DEPENDS=	${LINUXBASE}${HLDSDIR}${HL_PROGRAM}:${HALFLIFESERVER_PORT}

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
WRKSRC?=		${WRKDIR}/cstrike
PLIST_SUB=	${PLIST_SUB_MASTER}

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
SORT?=		/usr/bin/sort

HALFLIFESERVER_PORT=	${.CURDIR}/../halflifeserver
HLDSDIR!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V HLDSDIR
HL_PROGRAM!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V HL_PROGRAM
PLIST_SUB_MASTER!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V PLIST_SUB

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
install-parse-plist:
	@${PERL} -e 'open(FHANDLER,"${PLIST}");' \
		-e 'open(FDIR,">${WRKDIR}/dirs.sh.tmp");' \
		-e 'open(FFILES,">${WRKDIR}/files.sh");' \
		-e 'while (!eof(FHANDLER)) {' \
			-e 'chop($$file = <FHANDLER>);' \
			-e '$$file =~ s!%%HLDSDIR%%!!;' \
			-e '$$dir = $$file;' \
			-e '$$file =~ s!^\@.+!!;' \
			-e 'print FDIR "${INSTALL_DIR}", \
				" ", "\"${PREFIX}/${HLDSDIR}/$$dir\"", \
				"\n" if $$dir =~ s!(^\@dirrm\s+)!!;' \
			-e 'print FFILES "${INSTALL_DATA}", \
				" ", "\"${WRKDIR}/$$file\"", \
				" ", "\"${PREFIX}/${HLDSDIR}/$$file\"", \
				"\n" if (length($$file) > 0);' \
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
