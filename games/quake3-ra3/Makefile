# New ports collection makefile for:	Q3 Mod: Rocket Arena 3
# Date created:				Sun Jun  3 00:53:00 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME?=	ra3
PORTVERSION?=	1.65
CATEGORIES=	games linux
MASTER_SITES?=	http://gamefiles.blueyonder.co.uk/blueyondergames/quake3arena/modifications/rocketarena/patches/linux/ \
		http://mir2.ovh.net/ftp.planetquake3.net/modifications/rocketarena3/
PKGNAMEPREFIX=	q3server-
.ifndef(DISTNAME)
DISTFILES?=	${PORTNAME}${PORTVERSION:S/.//}cl.zip \
		${PORTNAME}${PORTVERSION:S/.//}sv.zip
.endif

MAINTAINER?=	pat@FreeBSD.org
COMMENT?=	Quake III Arena Mod: Rocket Arena 3 for Linux

RUN_DEPENDS=	${LOCALBASE}/games/quake3/q3ded:${Q3SERVER_PORT}

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_PERL5=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
.if (${PORTNAME}==ra3)
WRKSRC=		${WRKDIR}/arena
.endif
.ifndef(DONT_USE_ZIP)
USE_ZIP=	yes
.endif
.if defined(HAS_WIERDPATCHES)
EXTRACT_ONLY?=	${PORTNAME}${PORTVERSION:S/.//}cl.zip
.endif
.ifndef(NO_WRKSUBDIR)
Q3SUBDIR?=	${WRKSRC:T}
WRKSRC?=	${WRKDIR}/${PORTNAME}
.else
Q3SUBDIR?=	${PORTNAME}
.endif

Q3DIR=		games/quake3/${Q3SUBDIR}/

PLIST_SUB+=	Q3DIR="${Q3DIR}"
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

Q3SERVER_PORT=	${.CURDIR}/../q3server
PKGMESSAGE!=	cd ${Q3SERVER_PORT} && ${MAKE} -V PKGMESSAGE

.if defined(HAS_WIERDPATCHES) && defined(DISTFILES)
post-extract:
.for files in ${DISTFILES:S/${EXTRACT_ONLY}//}
	@cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/${files}
.endfor
.endif

pre-patch:
# remove trailing ^M
	@${FIND} -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt|url)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;

# Parses PLIST
# Contributed by <lioux@FreeBSD.org>
do-install: install-parse-plist install-scripts

install-parse-plist: generate-plist
	@${PERL} -e 'open(FHANDLER,"${TMPPLIST}");' \
		-e 'open(FDIR,">${WRKDIR}/dirs.sh.tmp");' \
		-e 'open(FFILES,">${WRKDIR}/files.sh");' \
		-e 'while (!eof(FHANDLER)) {' \
			-e 'chop($$file = <FHANDLER>);' \
			-e '$$dir = $$file_partial = $$file;' \
			-e '$$file_partial =~ s!^${Q3DIR}!!;' \
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

install-scripts:
	@${INSTALL_DIR} ${PREFIX}/${Q3DIR}
	@${SORT} ${WRKDIR}/dirs.sh.tmp > ${WRKDIR}/dirs.sh
	@${SH} ${WRKDIR}/dirs.sh
	@${SH} ${WRKDIR}/files.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
