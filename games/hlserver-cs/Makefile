# New ports collection makefile for:	Counter Strike Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME?=	cs
PORTVERSION?=	1.3
CATEGORIES?=	games linux
MASTER_SITES?=	http://games.velocity.net/files/Counter-Strike/ \
		http://www.redphive.org/files/ \
		http://files.ausgamers.com:81/half-life/counter-strike/linux/
PKGNAMEPREFIX=	hlserver-
.ifndef(DISTFILES)
DISTNAME?=	${PORTNAME}_${PORTVERSION:S/.//}_full
.endif

MAINTAINER?=	pat@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}${HLDSDIR}${HL_PROGRAM}:${HALFLIFESERVER_PORT}

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
.if (${PORTNAME}==cs)
PORTREVISION=	1
BUILD_DEPENDS+=	${NONEXISTENT}:${HALFLIFESERVER_PORT}:patch
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

# 3.1.0.8 Beta A patch
HALFLIFESERVER_PORT_WRKSRC!=	cd ${HALFLIFESERVER_PORT} && ${MAKE} -V WRKSRC

.if (${PORTNAME}==cs) && !target(post-extract)
post-extract:
.if exists(${HALFLIFESERVER_PORT_WRKSRC}/cstrike)
	${CP} -Rp ${HALFLIFESERVER_PORT_WRKSRC}/cstrike ${WRKDIR}
.else
	@${ECHO_MSG} "Please update your ports tree, it is not syncronized to the latest tree"
	@${ECHO_MSG} "This port will not work. Check the FreeBSD Handbook on how to update"
	@${FALSE}
.endif
.endif

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
			-e 'print FFILES "${INSTALL_DATA}", \
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

.include <bsd.port.mk>
