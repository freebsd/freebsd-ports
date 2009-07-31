# New ports collection makefile for:	ja-mozilla-jlp
# Date created:		02 Jul 2000
# Whom:			Yoichi ASAI <yatt@luna2.org>
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.7.13
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	japanese www
MASTER_SITES=	ftp://ftp.mozilla-japan.org/pub/mozilla/mozilla-japan/mozilla/releases/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,maho/mozilla/&,}
PKGNAMESUFFIX=	-jlp
DISTNAME=	mozilla-${PORTVERSION}.ja-JP.langpack
EXTRACT_SUFX=	.xpi

MAINTAINER=	fortune@n.jpn.ph
COMMENT=	Mozilla Japanese Language Pack (JLP)

BUILD_DEPENDS=	${LOCALBASE}/lib/${MOZILLA}/regxpcom:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${MOZILLA}:${PORTSDIR}/www/${MOZILLA} \
		ja-alias-fonts>=1.0:${PORTSDIR}/japanese/alias-fonts

WRKSRC=		${WRKDIR}/bin

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qo

MOZILLA=	mozilla
PLIST_SUB=	MOZILLA=${MOZILLA}
LOCALENAME=	ja_JP.eucJP

do-build:
	${SED} -e "s^%%PREFIX%%^${PREFIX}^g" \
	       -e "s^%%LOCALBASE%%^${LOCALBASE}^g" \
	       -e "s^%%LOCALENAME%%^${LOCALENAME}^g" \
	       -e "s^%%MOZILLA%%^${MOZILLA}^g" \
	${FILESDIR}/mozilla.sh > ${WRKDIR}/${MOZILLA}

do-install:
	(cd ${PREFIX}/lib/${MOZILLA}/chrome; \
	${MV} -f chrome.rdf chrome.rdf.orig; \
	${MV} -f installed-chrome.txt installed-chrome.txt.orig)
	(cd ${PREFIX}/lib/${MOZILLA}/components; \
	${MV} -f xpti.dat ../xpti.dat.orig)
	${MV} -f ${PREFIX}/bin/${MOZILLA} ${PREFIX}/bin/${MOZILLA}.orig
	${INSTALL_SCRIPT} ${WRKDIR}/${MOZILLA} ${PREFIX}/bin
	(cd ${WRKDIR}/sp; ${TAR} -cf - *) | \
	${TAR} -xf - -C ${PREFIX}/lib/${MOZILLA}/searchplugins
#	(cd ${WRKDIR}/sp_nomac; ${TAR} -cf - *) | \
#	${TAR} -xf - -C ${PREFIX}/lib/${MOZILLA}/searchplugins
	(cd ${WRKSRC}; ${TAR} -cf - chrome defaults) | \
	${TAR} -xf - -C ${PREFIX}/lib/${MOZILLA}
	(cd ${PREFIX}/lib/${MOZILLA}/chrome; \
	${CP} installed-chrome.txt.orig installed-chrome.txt; \
	${CAT} ${FILESDIR}/installed-chrome.txt >> installed-chrome.txt)
	(cd ${PREFIX}/lib/${MOZILLA}; \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
