# New ports collection makefile for:	zh-mozilla-tclp
# Date created:		07 March 2001
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#
# This is a rewritten 'universal' version port Makefile.
# Port version 'x.Uy' stands for Mozilla version x.*, edition y
# We will detect the Mozilla you installed and try to fetch correct
# version of language pack.
#
# Just install your favorite Mozilla first ( ports/www/mozilla/ or
# ports/www/mozilla-devel/ or ports/www/mozilla-vendor ) and then
# install mozilla-tclp. The language pack installed will match your
# Mozilla installation. But remember that if you upgrade your Mozilla,
# you have to come and reinstall mozilla-tclp again.
#
# If this version is out-of-date, please visit 
#    http://www.csie.ntu.edu.tw/~b7506051/mozilla/download.html
# And just download and install there.
#

PORTNAME=	mozilla
PORTVERSION=	1.U
PORTEPOCH=	1
CATEGORIES=	chinese www
MASTER_SITES=	http://www.csie.ntu.edu.tw/~b7506051/mozilla/langpack/distfiles/
# Same as ftp://ftp.mozilla.org/pub/mozilla/l10n/lang/$MOZVER/langzhtw.xpi.
# Use this to avoid checksum problems.
PKGNAMESUFFIX=	-tclp
DISTNAME=	${PORTNAME}-langzhtw-${MOZRV}
EXTRACT_SUFX=	.xpi
#NO_CHECKSUM=	YES
#IGNOREFILES=	${PORTNAME}-langzhtw-${MOZRV}${EXTRACT_SUFX}

MAINTAINER=	piaip@csie.ntu.edu.tw

FETCH_DEPENDS=	${PREFIX}/lib/mozilla/mozilla:${PORTSDIR}/www/mozilla
BUILD_DEPENDS=	${PREFIX}/lib/mozilla/regxpcom:${PORTSDIR}/www/mozilla
RUN_DEPENDS=	mozilla:${PORTSDIR}/www/mozilla

WRKSRC=		${WRKDIR}/bin

USE_X_PREFIX=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qo

MOZRV=		`${SH} ${FILESDIR}/mozver ${SED} ${PREFIX}/lib/mozilla/mozilla`

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400020
MOZILLA_SH=	mozilla.noxpg4
.else
MOZILLA_SH=	mozilla.xpg4
.endif

pre-fetch:
	@${ECHO_MSG} "=======================================================>"
	@${ECHO_MSG} "Detecting your Mozilla revision... "
	@${ECHO_MSG} "Revision=${MOZRV}"
	@${ECHO_MSG} "We are going to fetch language pack for this revision."
	@${ECHO_MSG} "* If you see incorrect revision in the Revision message,"
	@${ECHO_MSG} "  please upgrade or update your Mozilla installation."
	@${ECHO_MSG} "* If you see error messages of 'Error code 1' like "
	@${ECHO_MSG} "  'distinfo is out of date' or 'spelled incorrectly',"
	@${ECHO_MSG} "  you may try to 'make NO_CHECKSUM=yes'"
	@${ECHO_MSG} "* If you then got 'file not found' on MASTERSITE, that"
	@${ECHO_MSG} "  means you've installed a newer or unsupported revision"
	@${ECHO_MSG} "  of Mozilla that doesn't have any language packs (yet)."
	@${ECHO_MSG} "=======================================================<"

post-extract:
	${MKDIR} ${WRKSRC}/defaults/pref
	${CP} ${FILESDIR}/unix.js ${WRKSRC}/defaults/pref/.
	${CP} ${FILESDIR}/user.js ${WRKSRC}/defaults/profile/.
	${CP} ${FILESDIR}/user.js ${WRKSRC}/defaults/profile/TW/.
	# fix up file permission if broken
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} a+r-x {} \;
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} a+r+x {} \;
	#${CHMOD} -R a+rX ${WRKSRC}

do-build:
	${SED} -e "s;@PREFIX@;${PREFIX};g" \
	${FILESDIR}/${MOZILLA_SH} > ${WRKDIR}/mozilla

# The 'HOME=/tmp' was solving 1.0rc2 regxpcom bug

do-install:
	(cd ${PREFIX}/lib/mozilla; \
	${SETENV} HOME=/tmp LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	${SETENV} HOME=/tmp LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)
	# backing up
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${MV} -f chrome.rdf chrome.rdf.orig; \
	${MV} -f installed-chrome.txt installed-chrome.txt.orig)
	(cd ${PREFIX}/lib/mozilla/defaults/pref; \
	${MV} -f unix.js unix.js.orig)
	(cd ${PREFIX}/lib/mozilla/searchplugins; \
	${MV} -f google.gif google.gif.orig; \
	${MV} -f google.src google.src.orig)
	${MV} -f ${PREFIX}/bin/mozilla ${PREFIX}/bin/mozilla.orig
	# start installation
	${INSTALL_SCRIPT} ${WRKDIR}/mozilla ${PREFIX}/bin
	(cd ${WRKSRC}; ${TAR} -cf - chrome defaults searchplugins) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${CP} installed-chrome.txt.orig installed-chrome.txt; \
	${CAT} ${FILESDIR}/installed-chrome.txt >> installed-chrome.txt)
	# finalize chrome registeration
	(cd ${PREFIX}/lib/mozilla; \
	${SETENV} HOME=/tmp LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	${SETENV} HOME=/tmp LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
