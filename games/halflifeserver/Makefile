# New ports collection makefile for:    Half-Life Dedicated Server
# Date created:				Sat Jul 15 14:27:16 SAST 2000
# Whom:					markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hlds
PORTVERSION=	3.1.0.8.0a
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	ftp://files.ausgamers.com/half-life/linux/ \
		http://fileplanet.games-world.net/dl/ftp1.gamespy.com/action/half-life/official/ \
		ftp://ftp.houstonlive.net/CounterStrike/ \
		ftp://mirrors.cstrike.org/pub/mirrors/cstrike/ \
		http://www.redphive.org/files/
DISTFILES=	hlds_l_3108_full.tar.gz \
		hlds_l_3108a_up.tar.gz

MAINTAINER=	pat@databits.net

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/hlds_l
STRIP=
PLIST_SUB=	${PLIST_SUB_FOR_THIS_PORT}
PLIST_SUB_FOR_THIS_PORT=	HLDSDIR="${HLDSDIR:S/^\///}" LDCONFIG="${LDCONFIG_LINUX}"

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755
LDCONFIG_LINUX=	${LINUXBASE}/sbin/ldconfig

HLDSDIR=	/usr/games/hlds_l/
HL_PROGRAM=	hlds_run
SORT?=		/usr/bin/sort

# files which should be installed with executables perms
EXECUTABLES=	${HL_PROGRAM} hltv

pre-patch:
# remove trailing ^M
	@find -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt|rc)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;

do-install: install-parse-plist install-run-scripts scan-libs

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
			-e 'if ($$file !~ m!^\@!) {' \
				-e '$$program_flag = 0;' \
				-e 'if ("${EXECUTABLES}" ne "") {' \
					-e 'foreach $$program_pattern \
						(split (/\s+/,"${EXECUTABLES}")) {' \
						-e '($$program_flag = 1 , break) \
							if ($$file =~ /$$program_pattern$$/);' \
					-e '}' \
				-e '}' \
				-e 'print FFILES ($$program_flag == 0) ? \
					"${INSTALL_DATA}" : "${INSTALL_PROGRAM}";' \
				-e 'print FFILES " ", "\"${WRKSRC}/$$file_partial\"", \
					" ", "\"${PREFIX}/$$file\"", \
					"\n";' \
			-e '}' \
		-e '}' \
		-e 'close(FFILES);' \
		-e 'close(FDIR);' \
		-e 'close(FHANDLER);'
	@${SORT} ${WRKDIR}/dirs.sh.tmp > ${WRKDIR}/dirs.sh

install-run-scripts:
.for script in dirs files
	@${SH} ${WRKDIR}/${script}.sh
.endfor
	@if ! (${GREP} -E \"^${HLDSDIR}$$\" ${PREFIX}/etc/ld.so.conf 1>/dev/null 2>&1) ;\
	then \
		${ECHO} ${HLDSDIR} >> ${PREFIX}/etc/ld.so.conf ;\
	fi

scan-libs:
	@${LDCONFIG_LINUX}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
