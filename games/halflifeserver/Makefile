# New ports collection makefile for:    Half-Life Dedicated Server
# Date created:				Sat Jul 15 14:27:16 SAST 2000
# Whom:					markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hlds
PORTVERSION=	3.1.0.7
CATEGORIES=	games linux
MASTER_SITES=	http://games.velocity.net/files/Halflife/ \
		ftp://ftp.gmd.de/people/cla/hl/hl-newest/linux/ \
		ftp://ftp.icsmedia.de/pub/games/halflife/hl_server/ \
		http://ftp1download.gamespy.com/fileplanet/fpnew/action/half-life/official/ \
		http://fileplanet.games-world.net/dl/ftp1.gamespy.com/fpnew/action/half-life/official/ \
		ftp://ftp.fh-rosenheim.de/pub/games/halflife/servers/
DISTFILES=	hlds_l3106.tar.gz hlds_l3107_upgrade.tar.gz

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
HL_PROGRAM=	hlds_run
SORT?=		/usr/bin/sort

pre-patch:
# remove trailing ^M
	@find -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt)" \
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
			-e 'print FFILES "${INSTALL_DATA}", \
				" ", "\"${WRKSRC}/$$file_partial\"", \
				" ", "\"${PREFIX}/$$file\"", \
				"\n" if ($$file !~ m!^\@!);' \
		-e '}' \
		-e 'close(FFILES);' \
		-e 'close(FDIR);' \
		-e 'close(FHANDLER);'
	@${SORT} ${WRKDIR}/dirs.sh.tmp > ${WRKDIR}/dirs.sh

install-run-scripts:
.for script in dirs files
	@${SH} ${WRKDIR}/${script}.sh
.endfor

scan-libs:
	@${LDCONFIG_LINUX}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
