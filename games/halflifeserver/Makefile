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
MASTER_SITES=	http://www.carnage.q-net.net.au/downloads/server/halflife/linux/ \
		http://carnage.q-net.net.au/~carnage/server/halflife/linux/ \
		http://www.redphive.org/files/ \
		ftp://ftp.splatterworld.de/hl/official/server/ \
		http://files.ausgamers.com:81/half-life/linux/
DISTFILES=	hlds_l_3108_full.tar.gz \
		hlds_l_3108a_up.tar.gz

MAINTAINER=	pat@FreeBSD.org

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

.ifdef(WITH_PING_BOOSTER)
MASTER_SITES+=	http://www.udpsoft.com/booster/
DISTFILES+=	HLDSPingBooster-0.99.tar.gz

BOOSTER_FILES=	booster.so hlds_boost
EXECUTABLES+=	hlds_boost

PLIST_SUB+=	BOOSTER=""
.else
PLIST_SUB+=	BOOSTER="@comment "
.endif

pre-everything::
.ifndef(WITH_PING_BOOSTER)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_PING_BOOSTER to enable HLDS Ping Booster.'
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> HLDS Ping Booster is a small tweak to the Half-Life Dedicated'
	@${ECHO_MSG} '===> Server that drastically reduces player pings and generally'
	@${ECHO_MSG} '===> makes the game much more responsive.'
	@${ECHO_MSG} '===> Besides defining this, instead of using hlds_run to start the'
	@${ECHO_MSG} '===> server, use hlds_boost. Clients do not have to install anything.'
	@${ECHO_MSG} '===> Check http://www.udpsoft.com/booster/ for additional information.'
	@${ECHO_MSG} '===>'
.endif

post-extract:
.ifdef(WITH_PING_BOOSTER)
.for file in ${BOOSTER_FILES}
	@${CP} ${WRKDIR}/${file} ${WRKSRC}
.endfor
.endif

pre-patch:
# remove trailing ^M
	@find -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt|rc)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;
.ifdef(WITH_PING_BOOSTER)
	@${PERL} -pi -e 's|booster.so|${PREFIX}${HLDSDIR}booster.so|' \
		${WRKSRC}/hlds_boost
.endif

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
