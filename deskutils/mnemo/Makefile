# Ports collection makefile for:  Mnemo
# Date created:			  Sun May 19, 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mnemo
PORTVERSION=	2.1.1
DISTVERSIONPREFIX=	h3-
PORTREVISION=	1
CATEGORIES=	deskutils www
MASTER_SITES=	HORDE
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Mnemo is the Horde notes and memos application

RUN_DEPENDS=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

NO_BUILD=	yes
USE_GETTEXT=	yes

PLIST_SUB=	MNEMODIR=${LMNEMODIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	MNEMODIR=${MNEMODIR}

REINPLACE_ARGS=	-i ""
PORTDOCS=	README CHANGES CREDITS INSTALL	\
		RELEASE_NOTES  TODO UPGRADING
CONFFILE=	prefs.php
SUB_DIRS=	config js lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LMNEMODIR?=	${LHORDEDIR}/mnemo

MNEMODIR=	${PREFIX}/${LMNEMODIR}
CONFDIR=	${MNEMODIR}/config

.include <bsd.port.pre.mk>

post-extract:
	@${MV} ${WRKSRC}/README ${WRKSRC}/docs/

pre-configure:
	@(cd ${WRKSRC}/scripts &&	\
		${FIND} . -name "*.php" -exec	\
		${REINPLACE_CMD} -e "s:/usr/local/bin/php: ${LOCALBASE}/bin/php:;s:/usr/bin/php: ${LOCALBASE}/bin/php:" {} \; )

do-install:
	@${INSTALL} -d ${MNEMODIR}/
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${MNEMODIR}/
	@${CP} -p ${WRKSRC}/*.php ${MNEMODIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${MNEMODIR}/
	@${CHMOD} -R o-rwx ${MNEMODIR}/
	${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP}\
		%D/${MNEMODIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	${ECHO_CMD} @exec ${CHMOD} -R o-rwx\
		%D/${MNEMODIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
