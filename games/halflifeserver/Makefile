# New ports collection makefile for:    Half-Life Dedicated Server
# Date created:				Sat Jul 15 14:27:16 SAST 2000
# Whom:					markm@FreeBSD.org
#
# $FreeBSD$
#

# XXX: this is the master port to games/hlserver-cs and games/hlserver-dod

PORTNAME?=	hlds
PORTVERSION?=	1.1.2.0
.if(${PORTNAME} == hlds)
PORTEPOCH=	1
PORTREVISION=	0
.endif
CATEGORIES=	games linux
DISTNAME=	hlds_l_1120_full
EXTRACT_SUFX=	.tgz

MAINTAINER=	pat@FreeBSD.org
COMMENT?=	Steam Enabled Half-Life Dedicated Server with CS and DOD

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_PERL5=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/hlds_l
PLIST_SUB=	${PLIST_SUB_FOR_THIS_PORT}
PLIST_SUB_FOR_THIS_PORT=	HLDSDIR="${HLDSDIR:S/^\///}" \
				HLDSBASE="${HLDSBASE}"

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

HLDSDIR=	/games/hlds_l/
HLDSBASE=	games
HL_PROGRAM=	hlds_run

# files which should be installed with executables perms
EXECUTABLES=	hltv hlds_run hlds_amd hlds_amd64 hlds_i486 hlds_i686 steam

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"Please download and execute ${DISTNAME}.bin to read Valve\'s \
	agreement and get the tarball. Move ${DISTNAME}${EXTRACT_SUFX} \
	to ${DISTDIR} and try again"
.endif

pre-patch:
# remove trailing ^M
	@${FIND} -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt|rc)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;

do-install: install-parse-plist install-run-scripts

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
					"${INSTALL_DATA:S/${SHAREMODE}/400/}" : "${INSTALL_SCRIPT:S/${BINMODE}/500/}";' \
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

post-install:
	@${ECHO_CMD} "*README* *README* *README* *README* *README* *README* *README*"
	@${ECHO_CMD} "------------------------------------------------------------"
	@${ECHO_CMD} "              Do not run server as root"
	@${ECHO_CMD} " HLDS ports will be installed in ${PREFIX}/games/hlds_l"
	@${ECHO_CMD} "------------------------------------------------------------"

.include <bsd.port.post.mk>
