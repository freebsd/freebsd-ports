# New ports collection makefile for:	deskutils/sugarcrm
# Date created:				March 25 2005
# Whom:	      				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$

PORTNAME=	sugarcrm
PORTVERSION=	5.5.1
CATEGORIES=	deskutils www
MASTER_SITES=	http://www.sugarforge.org/frs/download.php/6592/
DISTNAME=	SugarCE-${PORTVERSION}

MAINTAINER=	nick@foobar.org
COMMENT=	A web based customer relationship management suite

FETCH_ARGS=	-pRr
IGNORE_WITH_MYSQL=	323 40
USE_PHP=	gd mysql session pcre xml zlib mbstring curl imap spl posix
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SugarCE-Full-${PORTVERSION}

INSTFILES=	HandleAjaxCall.php SugarSecurity.php TreeData.php \
		WebToLeadCapture.php acceptDecline.php campaign_tracker.php \
		campaign_trackerv2.php config.php cron.php \
		demoData.en_us.php demoData.ja_jp.php demoData.zh_cn.php \
		dictionary.php download.php \
		emailmandelivery.php export.php files.md5 image.php \
		index.php install.php json.php json_server.php \
		leadCapture.php log_file_restricted.html \
		maintenance.php metagen.php pdf.php removeme.php \
		soap.php sugar_version.php vCard.php vcal_server.php \
		robots.txt LICENSE.txt .htaccess

INSTDIRS=	ModuleInstall XTemplate cache custom data examples include \
		install jscalendar jssource log4php metadata modules service \
		soap themes 

INSTDOCS=	LICENSE.txt

# files and directories to be chown -R'ed to www user
WWWFILES=	config.php custom data modules .htaccess cache include/javascript

PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_FILES+=	pkg-message pkg-install
PLIST_SUB+=	CACHEDIRS="${CACHEDIRS}" \
		WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}" \
		WWWFILES="${WWWFILES}"

do-install:
	@${MKDIR} ${WWWDIR}

.for i in ${INSTFILES} ${INSTDIRS}
	@cd ${WRKSRC} && \
		${FIND} ${i} -type d -exec ${MKDIR} ${WWWDIR}/{} \; ; \
		${FIND} ${i} \! -type d -exec ${INSTALL_DATA} {} ${WWWDIR}/{} \;
	@${TOUCH} ${TOUCH_FLAGS} ${WWWDIR}/config.php
.endfor

.for i in ${WWWFILES}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/${i}
	@${CHMOD} -R u+w ${WWWDIR}/${i}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${INSTDOCS}
		@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
