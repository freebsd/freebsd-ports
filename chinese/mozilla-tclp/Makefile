# New ports collection makefile for:	zh-mozilla-tclp
# Date created:		07 March 2001
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#
# If this version is out-of-date, please visit 
#    http://www.csie.ntu.edu.tw/~b7506051/mozilla/
# And just download and install there.
# Or, change the PORTVERSION below to feasible version and make makesum all

PORTNAME=	mozilla
PORTVERSION=	1.0.1
CATEGORIES=	chinese www
MASTER_SITES=	http://www.csie.ntu.edu.tw/~b7506051/mozilla/langpack/distfiles/
PKGNAMESUFFIX=	-tclp
# Same as ftp://ftp.mozilla.org/pub/mozilla/l10n/lang/$MOZVER/langzhtw.xpi.
# Use this to avoid checksum problems.
DISTNAME=	${PORTNAME}-langzhtw-${PORTVERSION}
EXTRACT_SUFX=	.xpi

MAINTAINER=	piaip@csie.ntu.edu.tw

BUILD_DEPENDS=	${X11BASE}/lib/mozilla/regxpcom:${PORTSDIR}/www/mozilla
RUN_DEPENDS=	mozilla:${PORTSDIR}/www/mozilla

WRKSRC=		${WRKDIR}/bin

USE_X_PREFIX=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qo

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400020
MOZILLA_SH=	mozilla.noxpg4
.else
MOZILLA_SH=	mozilla.xpg4
.endif

post-extract:
	${MKDIR} ${WRKSRC}/defaults/pref
	${CP} ${FILESDIR}/unix.js ${WRKSRC}/defaults/pref/.
	${CP} ${FILESDIR}/user.js ${WRKSRC}/defaults/profile/.
	${CP} ${FILESDIR}/user.js ${WRKSRC}/defaults/profile/TW/.
	${CHMOD} -R a+rX ${WRKSRC}

do-build:
	${SED} -e "s;@PREFIX@;${PREFIX};g" \
	${FILESDIR}/${MOZILLA_SH} > ${WRKDIR}/mozilla

# The 'HOME=/tmp' was solving 1.0rc2 regxpcom bug

do-install:
	(cd ${PREFIX}/lib/mozilla; \
	${SETENV} HOME=/tmp LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	${SETENV} HOME=/tmp LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${MV} -f chrome.rdf chrome.rdf.orig; \
	${MV} -f installed-chrome.txt installed-chrome.txt.orig)
	(cd ${PREFIX}/lib/mozilla/defaults/pref; \
	${MV} -f unix.js unix.js.orig)
	(cd ${PREFIX}/lib/mozilla/searchplugins; \
	${MV} -f google.gif google.gif.orig; \
	${MV} -f google.src google.src.orig)
	${MV} -f ${PREFIX}/bin/mozilla ${PREFIX}/bin/mozilla.orig
	${INSTALL_SCRIPT} ${WRKDIR}/mozilla ${PREFIX}/bin
	(cd ${WRKSRC}; ${TAR} -cf - chrome defaults searchplugins res) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${CP} installed-chrome.txt.orig installed-chrome.txt; \
	${CAT} ${FILESDIR}/installed-chrome.txt >> installed-chrome.txt)
	(cd ${PREFIX}/lib/mozilla; \
	${SETENV} HOME=/tmp LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	${SETENV} HOME=/tmp LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
