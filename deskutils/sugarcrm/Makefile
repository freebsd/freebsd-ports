# New ports collection makefile for:	deskutils/sugarcrm
# Date created:				March 25 2005
# Whom:	      				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$

PORTNAME=	sugarcrm
PORTVERSION=	3.5.1
CATEGORIES=	deskutils www
MASTER_SITES=	${SCRM_DISPATCHER}/392/:src \
		${SCRM_DISPATCHER}/387/:userdoc \
		${SCRM_DISPATCHER}/389/:installdoc
DISTFILES=	${USERDOCFILE}:userdoc \
		${INSTALLDOCFILE}:installdoc \
		${SRCNAME}${EXTRACT_SUFX}:src
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${SRCNAME}${EXTRACT_SUFX}

MAINTAINER=	nick@foobar.org
COMMENT=	A web based customer relationship management suite

USE_PHP=	gd mysql session pcre xml
USE_PHP=	gd mysql session pcre xml
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUGARCRMDIR?=	www/${PORTNAME}

SCRM_DISPATCHER=	http://sugarforge.org/frs/download.php
SRCNAME=	SugarSuite-${PORTVERSION}
USERDOCFILE=	Sugar_Open_Source_User_Guide_v35.pdf
INSTALLDOCFILE=	Sugar_Open_Source_Installation_Guide_v35.pdf

INSTFILES=	acceptDecline.php campaign_tracker.php config.php \
		dictionary.php emailmandelivery.php export.php index.php \
		install.php json.php json_server.php leadCapture.php \
		log4php.properties log_file_restricted.html maintenance.php \
		metagen.php pdf.php phprint.php removeme.php robots.txt \
		soap.php sugar_version.php vCard.php vcal_server.php \
		LICENSE.txt .htaccess

INSTDIRS=	ModuleInstall XTemplate cache custom data examples include \
		install jscalendar log4php metadata modules soap themes upgrade

INSTDOCS=	INSTALLATION.txt LICENSE.txt PATCH.txt README.txt UPGRADE.TXT UPGRADE-FreeBSD.txt

# files and directories to be chown -R'ed to www user
WWWFILES=	config.php custom data modules .htaccess cache

PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_FILES+=	pkg-message
SUB_LIST+=	SUGARCRMDIR="${SUGARCRMDIR}"
PLIST_SUB+=	SUGARCRMDIR="${SUGARCRMDIR}" \
		CACHEDIRS="${CACHEDIRS}" \
		WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}" \
		WWWFILES="${WWWFILES}" \
		USERDOCFILE="${USERDOCFILE}" \
		INSTALLDOCFILE="${INSTALLDOCFILE}"

post-patch:
	${CP} ${FILESDIR}/UPGRADE-FreeBSD.txt ${WRKSRC}
	@${REINPLACE_CMD}	-e 's|%%PREFIX%%|${PREFIX}|' \
				-e 's|%%SUGARCRMDIR%%|${SUGARCRMDIR}|' \
				${WRKSRC}/UPGRADE-FreeBSD.txt

do-install:
	@${MKDIR} ${PREFIX}/${SUGARCRMDIR}

.for i in ${INSTFILES} ${INSTDIRS}
	cd ${WRKSRC} && \
		${FIND} ${i} -type d -exec ${MKDIR} ${PREFIX}/${SUGARCRMDIR}/{} \; ; \
		${FIND} ${i} \! -type d -exec ${INSTALL_DATA} {} ${PREFIX}/${SUGARCRMDIR}/{} \;
.endfor

	@${MKDIR} ${PREFIX}/${SUGARCRMDIR}/cache/dynamic_fields

.for i in ${WWWFILES}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${SUGARCRMDIR}/${i}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${USERDOCFILE} \
		${DOCSDIR}/${USERDOCFILE}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${INSTALLDOCFILE} \
		${DOCSDIR}/${INSTALLDOCFILE}
.for i in ${INSTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
