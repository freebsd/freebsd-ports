# New ports collection makefile for:	Unreal Tournament Dedicated Server
# Date created:				Thu Oct 4 23:38:00 CEST 2001
# Whom:			Martin Matuska <matuska@wu-wien.ac.at> et al
#
# $FreeBSD$
#

PORTNAME=	utserver
PORTVERSION=	436
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	ftp://utservers:idspispopd@ftp.lokigames.com/ \
		http://arcadia.inf.udec.cl/ftp/pub/linux/ut-server/ \
		http://ucc.sobservers.com/ \
		http://game.dkm.cz/downloads/files/Unreal%20Tournament/ucc/
DISTFILES=	ut-server-${PORTVERSION}${EXTRACT_SUFX} \
		DM-Curse%5D%5B.unr.uz \
		DM-Deck16%5D%5B.unr.uz \
		DM-Morbias%5D%5B.unr.uz
EXTRACT_ONLY=	ut-server-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	matuska@wu-wien.ac.at

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ut-server

UTDIR=		usr/games/ut-server/
PLIST_SUB=	UTDIR="${UTDIR}"
EXTRA_PATCHES=	${WRKDIR}/patch-ngstatsut
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
SORT?=		/usr/bin/sort

# files which should be installed with executable perms
EXECUTABLES=	ucc ucc-bin

post-extract:
.for file in ${DISTFILES:S/${EXTRACT_ONLY}//}
	@${SETENV} HOME=${WRKDIR} ${WRKSRC}/ucc decompress \
		${DISTDIR}/${file} >/dev/null
.endfor
.for file in ${DISTFILES:S/${EXTRACT_ONLY}//}
	@${CP} -f "${WRKDIR}/.loki/ut/System/${file:R:S/%5D/]/:S/%5B/[/}" \
		${WRKSRC}/Maps
.endfor

pre-patch:
# remove trailing ^M
	@find -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|int|lst|pl|pm|sc|sh|scr|txt|url|uhtm)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;
	@${SED} -e "s!%%LOCALBASE%%!${LOCALBASE}!" \
		-e "s!%%LINUXBASE%%!${LINUXBASE}!" \
		-e "s!%%UTDIR%%!${UTDIR}!" \
		${FILESDIR}/template-patch-ngstatsut > \
		${WRKDIR}/patch-ngstatsut

do-install: install-parse-plist install-run-scripts

# Contributed by <lioux@FreeBSD.org>
install-parse-plist: generate-plist
	@${PERL} -e 'open(FHANDLER,"${TMPPLIST}");' \
		-e 'open(FDIR,">${WRKDIR}/dirs.sh.tmp");' \
		-e 'open(FFILES,">${WRKDIR}/files.sh");' \
		-e 'while (!eof(FHANDLER)) {' \
			-e 'chop($$file = <FHANDLER>);' \
			-e '$$dir = $$file_partial = $$file;' \
			-e '$$file_partial =~ s!^${UTDIR}!!;' \
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
					"${INSTALL_DATA}" : "${INSTALL_SCRIPT}", \
					" ", "\"${WRKSRC}/$$file_partial\"", \
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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
