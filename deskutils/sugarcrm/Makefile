# New ports collection makefile for:	deskutils/sugarcrm
# Date created:				March 25 2005
# Whom:	      				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$

PORTNAME=	sugarcrm
PORTVERSION=	4.5.1b
CATEGORIES=	deskutils www
MASTER_SITES=	${SCRM_DISPATCHER}/:src \
		${DOC_DISPATCHER}/:userdoc \
		${DOC_DISPATCHER}/:admindoc \
		${DOC_DISPATCHER}/:releasenotesdoc
DISTFILES=	${USERDOCFILE}:userdoc \
		${RELEASENOTESFILE}:releasenotesdoc \
		${ADMINDOCFILE}:admindoc \
		${SRCNAME}${EXTRACT_SUFX}:src
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${SRCNAME}${EXTRACT_SUFX}

MAINTAINER=	nick@foobar.org
COMMENT=	A web based customer relationship management suite

IGNORE_WITH_MYSQL=	323 40
USE_PHP=	gd mysql session pcre xml zlib mbstring curl imap
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SugarOS-Full-${PORTVERSION}
SUGARCRMDIR?=	www/${PORTNAME}

OPTIONS=	IMAP "Install with IMAP module (For email campaign support)" on

.if !defined(WITHOUT_IMAP)
USE_PHP+=	imap
.endif

SCRM_DISPATCHER=	http://dl.sugarforge.org/sugarcrm/SugarOS4.5.1Latest/SugarOS4.5.1
DOC_DISPATCHER=		${SCRM_DISPATCHER}

SRCNAME=	SugarOS-${PORTVERSION}
USERDOCFILE=	Sugar_OpenSource_UserGuide_${PORTVERSION}.pdf
RELEASENOTESFILE= Sugar_OpenSource_ReleaseNotes_${PORTVERSION}.pdf
ADMINDOCFILE=	Sugar_OpenSource_AdministrationGuide_${PORTVERSION}.pdf

INSTFILES=	HandleAjaxCall.php SugarSecurity.php TreeData.php \
		WebToLeadCapture.php acceptDecline.php campaign_tracker.php \
		campaign_trackerv2.php cron.php dictionary.php download.php \
		emailmandelivery.php export.php files.md5 image.php \
		index.php install.php json.php json_server.php \
		leadCapture.php log4php.properties log_file_restricted.html \
		maintenance.php metagen.php pdf.php phprint.php removeme.php \
		soap.php sugar_version.php vCard.php vcal_server.php \
		LICENSE.txt .htaccess

INSTDIRS=	ModuleInstall XTemplate cache custom data examples include \
		install jscalendar log4php metadata modules soap themes

INSTDOCS=	INSTALLATION.txt LICENSE.txt PATCH.txt README.txt UPGRADE.TXT

# files and directories to be chown -R'ed to www user
WWWFILES=	config.php custom data modules .htaccess cache

PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_FILES+=	pkg-message pkg-install
SUB_LIST+=	SUGARCRMDIR="${SUGARCRMDIR}"
PLIST_SUB+=	SUGARCRMDIR="${SUGARCRMDIR}" \
		CACHEDIRS="${CACHEDIRS}" \
		WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}" \
		WWWFILES="${WWWFILES}" \
		USERDOCFILE="${USERDOCFILE}" \
		RELEASENOTESFILE="${RELEASENOTESFILE}"

do-install:
	@${MKDIR} ${PREFIX}/${SUGARCRMDIR}

.for i in ${INSTFILES} ${INSTDIRS}
	cd ${WRKSRC} && \
		${FIND} ${i} -type d -exec ${MKDIR} ${PREFIX}/${SUGARCRMDIR}/{} \; ; \
		${FIND} ${i} \! -type d -exec ${INSTALL_DATA} {} ${PREFIX}/${SUGARCRMDIR}/{} \;
	@${TOUCH} ${TOUCH_FLAGS} ${PREFIX}/${SUGARCRMDIR}/config.php
.endfor

.for i in ${WWWFILES}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${SUGARCRMDIR}/${i}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${USERDOCFILE} \
		${DOCSDIR}/${USERDOCFILE}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${RELEASENOTESFILE} \
		${DOCSDIR}/${RELEASENOTESFILE}
.for i in ${INSTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
