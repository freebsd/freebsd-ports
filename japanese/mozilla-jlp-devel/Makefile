# New ports collection makefile for:	ja-mozilla-jlp-devel
# Date created:		02 Jul 2000
# Whom:			Yoichi ASAI <yatt@luna2.org>
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.3a
PORTREVISION?=	0
#PORTEPOCH=	1
CATEGORIES=	japanese www
MASTER_SITES=	http://plaza25.mbn.or.jp/~snip/jlp/
#MASTER_SITE_SUBDIR=	jlpmoz
PKGNAMESUFFIX=	-jlp
DISTNAME=	${PORTNAME}${PORTVERSION}-jajppack-tm0.1.3
EXTRACT_SUFX=	.xpi

MAINTAINER=	yatt@luna2.org

BUILD_DEPENDS=	${X11BASE}/lib/mozilla-devel/regxpcom:${PORTSDIR}/www/mozilla-devel
RUN_DEPENDS=	mozilla-devel:${PORTSDIR}/www/mozilla-devel \
		${PKG_DBDIR}/ja-alias-fonts-1.0:${PORTSDIR}/japanese/alias-fonts

WRKSRC=		${WRKDIR}/bin

LATEST_LINK=	ja-mozilla-jlp-devel
USE_X_PREFIX=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qo

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 450002
LOCALENAME=	ja_JP.eucJP
.elif ${OSVERSION} >= 400020
LOCALENAME=	ja_JP.EUC
.else
LOCALENAME=	ja_JP.EUC
LIBXPG4=	LD_PRELOAD=/usr/lib/libxpg4.so.2; export LD_PRELOAD
.endif

post-extract:
	${MKDIR} ${WRKSRC}/defaults/pref
	${CP} ${FILESDIR}/unix.js ${WRKSRC}/defaults/pref

do-build:
	${SED} -e "s^@PREFIX@^${PREFIX}^g" \
	       -e "s^@LOCALENAME@^${LOCALENAME}^g" \
	       -e "s^@LIBXPG4@^${LIBXPG4}^g" \
	${FILESDIR}/mozilla.sh > ${WRKDIR}/mozilla-devel

do-install:
	(cd ${PREFIX}/lib/mozilla-devel/chrome; \
	${MV} -f chrome.rdf chrome.rdf.orig; \
	${MV} -f installed-chrome.txt installed-chrome.txt.orig)
	(cd ${PREFIX}/lib/mozilla-devel/defaults/pref; \
	${MV} -f unix.js unix.js.orig)
	(cd ${PREFIX}/lib/mozilla-devel/components; \
	${MV} -f xpti.dat ../xpti.dat.orig)
	${MV} -f ${PREFIX}/bin/mozilla-devel ${PREFIX}/bin/mozilla-devel.orig
	${INSTALL_SCRIPT} ${WRKDIR}/mozilla-devel ${PREFIX}/bin
	(cd ${WRKDIR}/sp; ${TAR} -cf - *) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla-devel/searchplugins
	(cd ${WRKDIR}/sp_nomac; ${TAR} -cf - *) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla-devel/searchplugins
	(cd ${WRKSRC}; ${TAR} -cf - chrome defaults) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla-devel
	(cd ${PREFIX}/lib/mozilla-devel/chrome; \
	${CP} installed-chrome.txt.orig installed-chrome.txt; \
	${CAT} ${FILESDIR}/installed-chrome.txt >> installed-chrome.txt)
	(cd ${PREFIX}/lib/mozilla-devel; \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
