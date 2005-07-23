# New ports collection makefile for:	UT Mod: Tactical Ops
# Date created:				Sat Oct  6 11:40:35 EDT 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME?=	to
PORTVERSION?=	2.2.0
PORTREVISION?=	2
CATEGORIES=	games linux
MASTER_SITES?=	http://www.netreachgames.com/downloads/to/ \
		http://downloads.fragism.com/ \
		http://lmb.atom.is/downloads/Tacops/ \
		http://hq.hack.pl/~bond/zip/

PKGNAMEPREFIX=	utserver-
.ifndef(DISTFILES)
DISTNAME?=	TacticalOps220
.endif

MAINTAINER?=	pat@FreeBSD.org
COMMENT?=	Unreal Tournament mod Tactical Ops full server package for Linux

RUN_DEPENDS=	${LOCALBASE}/games/ut-server/System/ucc-bin:${UTSERVER_PORT}

BROKEN=		Unfetchable
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_PERL5=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
.if (${PORTNAME}==to)
EXECUTABLES+=	TacticalOpsLinux\\w+
EXTRA_CLEAN_FILES+=	.+/TacticalOpsLinux.+
DO_USE_WRKSUBDIR=	yes
.endif
.ifndef(DONT_USE_ZIP)
USE_ZIP=	yes
.endif
.ifndef(DO_USE_WRKSUBDIR)
NO_WRKSUBDIR=	yes
.endif

UTDIR=		games/ut-server/
PLIST_SUB+=	UTDIR="${UTDIR}"
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

UTSERVER_PORT=	${.CURDIR}/../utserver
MASTERPKGMESSAGE!=	cd ${UTSERVER_PORT} && ${MAKE} -V PKGMESSAGE

# files which should be installed with executable perms
EXECUTABLES+=	.sh

.if defined(HAS_WIERDPATCHES) && defined(DISTFILES)
post-extract:
.for files in ${DISTFILES:S/${EXTRACT_ONLY}//}
	@cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/${files}
.endfor
.endif

pre-patch:
# remove trailing ^M
	@${FIND} -E ${WRKDIR} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|int|lst|pl|pm|sc|sh|scr|txt|url|uhtm)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;
.ifdef(EXTRA_CLEAN_FILES)
.for pattern in ${EXTRA_CLEAN_FILES}
	@${FIND} -E ${WRKDIR} -type f \
		-iregex "${pattern}" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;
.endfor
.endif

# Parses PLIST
# Contributed by <lioux@FreeBSD.org>
do-install: install-parse-plist install-scripts

# XXX: this is missing a ${BRANDELF} -t Linux <executables>
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
					"${INSTALL_DATA}" : "${INSTALL_PROGRAM}", \
					" ", "\"${WRKSRC}/$$file_partial\"", \
					" ", "\"${PREFIX}/$$file\"", \
					"\n";' \
			-e '}' \
		-e '}' \
		-e 'close(FFILES);' \
		-e 'close(FDIR);' \
		-e 'close(FHANDLER);'
	@${SORT} ${WRKDIR}/dirs.sh.tmp > ${WRKDIR}/dirs.sh

install-scripts:
.for script in dirs files
	@${SH} ${WRKDIR}/${script}.sh
.endfor

post-install:
	@${CAT} ${MASTERPKGMESSAGE}
.if exists(${.CURDIR}/pkg-message)
	@${CAT} ${.CURDIR}/pkg-message
.endif

.include <bsd.port.mk>
