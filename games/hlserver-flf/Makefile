# New ports collection makefile for:    Front Line Force Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat
#
# $FreeBSD$
#

# XXX: this is the master port to games/hlserver-*

PORTNAME?=	flf
PORTVERSION?=	1.8b
CATEGORIES?=	games linux
MASTER_SITES?=	http://nephilim.net/files/
PKGNAMEPREFIX=	hlserver-
.if (${PORTNAME}==flf)
PORTREVISION=	1
.endif
.ifndef(DISTNAME)
DISTFILES?=	frontline${PORTVERSION:S/.//}_full-linux${EXTRACT_SUFX}
.endif

MAINTAINER?=	pat@FreeBSD.org
COMMENT?=	Half-Life mod Frontline Force full server package for Linux

RUN_DEPENDS=	${PREFIX}${HLDSDIR}${HL_PROGRAM}:${HALFLIFESERVER_PORT}

USE_SUBMAKE=	yes

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_PERL5=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
.if (${PORTNAME}==flf)
WRKSRC?=		${WRKDIR}/frontline
.else
.ifndef(NO_WRKSUBDIR)
WRKSRC?=		${WRKDIR}/${PORTNAME}
.endif # NO_WRKSUBDIR
.endif
PLIST_SUB+=	${PLIST_SUB_MASTER}

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

HALFLIFESERVER_PORT=	${.CURDIR}/../halflifeserver
HLDSDIR!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V HLDSDIR
HL_PROGRAM!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V HL_PROGRAM
PLIST_SUB_MASTER!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V PLIST_SUB_FOR_THIS_PORT
PKGMESSAGE!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V PKGMESSAGE

.if !target(slaveport-post-extract)
slaveport-post-extract:
.endif

post-extract: slaveport-post-extract

pre-patch:
# remove trailing ^M
	@${FIND} -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;

# if you change the PLIST, please re-think the following
# Parses PLIST
# creates dirs from @dirrm entries
# copies files from non ^@ entries
do-install: install-parse-plist install-run-scripts

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
			-e '$$file_partial =~ s!^[^/]+/!! if defined(${NO_WRKSUBDIR});' \
			-e 'print FDIR "${INSTALL_DIR}", \
				" ", "\"${PREFIX}/$$dir\"", \
				"\n" if $$dir =~ s!(^\@dirrm\s+)!!;' \
			-e 'print FFILES "${INSTALL_DATA:S/${SHAREMODE}/400/}", \
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

.if !target(slaveport-post-install)
slaveport-post-install:
.endif

post-install: slaveport-post-install
	@${ECHO_CMD} "*README* *README* *README* *README* *README* *README* *README*"
	@${ECHO_CMD} "------------------------------------------------------------"
	@${ECHO_CMD} "              Do not run server as root"
	@${ECHO_CMD} " HLDS ports will be installed in ${PREFIX}/games/hlds_l"
	@${ECHO_CMD} "------------------------------------------------------------"

.ifndef(_DONT_INCLUDE_MK_)
.include <bsd.port.mk>
.endif
