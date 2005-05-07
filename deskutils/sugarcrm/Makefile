# New ports collection makefile for:	deskutils/sugarcrm
# Date created:				March 25 2005
# Whom:	      				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$

PORTNAME=	sugarcrm
PORTVERSION=	2.5.1b
CATEGORIES=	deskutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	SugarSuite-Full-2_5_1b.zip \
		Sugar_Open_Source_User_Guide_v25_MSWord_2005-01-31.zip

MAINTAINER=	nick@foobar.org
COMMENT=	A web based customer relationship management suite

USE_PHP=	gd mysql session
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUGARCRMDIR?=	www/${PORTNAME}

INSTFILES=	config.php export.php index.php install.php json.php \
		leadCapture.php pdf.php phprint.php soap.php \
		sugar_version.php vCard.php robots.txt log4php.properties

INSTDIRS=	XTemplate custom data examples include install jscalendar \
		log4php modules soap themes

INSTDOCS=	INSTALLATION.txt LICENSE.txt README.txt

# empty directories to be created and chowned to www user
CACHEDIRS=	custom_fields dyn_lay feeds images import layout pdf upload xml

# files and directories to be chown -R'ed to www user
WWWFILES=	config.php custom data modules

PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_FILES+=	pkg-message
SUB_LIST+=	SUGARCRMDIR="${SUGARCRMDIR}"
PLIST_SUB+=	SUGARCRMDIR="${SUGARCRMDIR}" \
		CACHEDIRS="${CACHEDIRS}" \
		WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}" \
		WWWFILES="${WWWFILES}"

do-install:
	@${FIND} ${WRKSRC} -name .cvsignore -delete

	@${MKDIR} ${PREFIX}/${SUGARCRMDIR}

.for i in ${INSTFILES} ${INSTDIRS}
	@cd ${WRKSRC} && \
		${FIND} ${i} -type d -exec ${MKDIR} ${PREFIX}/${SUGARCRMDIR}/{} \; ; \
		${FIND} ${i} \! -type d -exec ${INSTALL_DATA} {} ${PREFIX}/${SUGARCRMDIR}/{} \;
.endfor

.for i in ${CACHEDIRS}
	${MKDIR} ${PREFIX}/${SUGARCRMDIR}/cache/${i}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${SUGARCRMDIR}/cache/${i}
.endfor

	@${INSTALL_DATA} ${WRKSRC}/cache/custom_fields/custom_fields_def.php \
		${PREFIX}/${SUGARCRMDIR}/cache/custom_fields

.for i in ${WWWFILES}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${SUGARCRMDIR}/${i}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Sugar\ Open\ Source\ User\ Guide\ v25.doc \
		${DOCSDIR}/Sugar_Open_Source_User_Guide_v25.doc
.for i in ${INSTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
