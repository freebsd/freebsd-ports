# New ports collection makefile for:	Counter Strike Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME?=	cs
PORTVERSION?=	1.5
CATEGORIES?=	games linux
MASTER_SITES?=	http://cstrike.thefusion.cc/ \
		http://bteg.net/~ms/hl/ \
		http://www.jetstreamgames.co.nz/files/pub/halflife/cstrike/ \
		http://cs.webcabo.com.br/~mosca/cs/ \
		http://lamas.counter-strike.hu:8080/letolt/extra/cs/
PKGNAMEPREFIX=	hlserver-
.ifndef(DISTFILES)
DISTNAME?=	${PORTNAME}_${PORTVERSION:S/.//}_full
.endif

MAINTAINER?=	pat@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}${HLDSDIR}${HL_PROGRAM}:${HALFLIFESERVER_PORT}

USE_SUBMAKE=	yes

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
USE_PERL5=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
.if (${PORTNAME}==cs)
WRKSRC?=		${WRKDIR}/cstrike
.else
.ifndef(NO_WRKSUBDIR)
WRKSRC?=		${WRKDIR}/${PORTNAME}
.endif # NO_WRKSUBDIR
.endif
PLIST_SUB+=	${PLIST_SUB_MASTER}

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755
SORT?=		/usr/bin/sort

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
	@find -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;

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
	@${CAT} ${PKGMESSAGE}

.ifndef(_DONT_INCLUDE_MK_)
.include <bsd.port.mk>
.endif
