# New ports collection makefile for:	Unreal Tournament Dedicated Server
# Date created:				Thu Oct 4 23:38:00 CEST 2001
# Whom:			Martin Matuska <martin@tradex.sk> et al
#
# $FreeBSD$
#

PORTNAME=	utserver
PORTVERSION=	436
PORTREVISION=	5
CATEGORIES=	games linux
MASTER_SITES=	http://public.planetmirror.com/pub/lokigames/installers/ut/ \
		http://fileserver.talkware.net/ut/
DISTNAME=	ut-server-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unreal Tournament Dedicated Server for Linux

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12
BUILD_DEPENDS=	${RUN_DEPENDS}

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_PERL5=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ut-server

UTDIR=		ut-server/
PLIST_SUB=	UTDIR="${UTDIR}"
EXTRA_PATCHES=	${WRKDIR}/patch-ngstatsut
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755
INSTALL_MY_DATA=	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 644

# files which should be installed with executable perms
EXECUTABLES=	ucc ucc-bin ngStatsUT ngStatsUT.exe ngWorldStats \
		bgWorldStats ngWorldStats.exe

pre-patch:
# remove trailing ^M
	@${FIND} -E ${WRKSRC} -type f \
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
					"${INSTALL_MY_DATA}" : "${INSTALL_SCRIPT}", \
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
