# Ports collection makefile for:	nag
# Date created:			Sun Dec 14, 2001
# Whom:				Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	nag
PORTVERSION=	2.1.3
DISTVERSIONPREFIX=	h3-
CATEGORIES=	deskutils www
MASTER_SITES=	HORDE

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Simple multiuser task list manager

RUN_DEPENDS=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION
USE_GETTEXT=	yes

PLIST_SUB=	NAGDIR=${LNAGDIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	NAGDIR=${NAGDIR}

REINPLACE_ARGS=	-i ""
PORTDOCS=	README CHANGES CREDITS INSTALL	\
		RELEASE_NOTES TODO UPGRADING
CONFFILE=	menu.php prefs.php
SUB_DIRS=	config js lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LNAGDIR?=	${LHORDEDIR}/nag

NAGDIR=		${PREFIX}/${LNAGDIR}
CONFDIR=	${NAGDIR}/config

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes
.else
HORDE_INC=	${LOCALBASE}/etc/horde
.endif

post-extract:
	@${MV} ${WRKSRC}/README ${WRKSRC}/docs/

pre-configure:
	@(cd ${WRKSRC}/scripts &&	\
		${FIND} . -name "*.php" -exec	\
		${REINPLACE_CMD} -e "s:/usr/local/bin/php: ${LOCALBASE}/bin/php:;s:/usr/bin/php: ${LOCALBASE}/bin/php:" {} \; )
	@${SED} -e "s:/home/httpd/html/horde/nag:${NAGDIR}:g"		\
		${FILESDIR}/httpd.conf.nag > ${WRKDIR}/httpd-nag.conf

do-install:
	@${INSTALL} -d ${NAGDIR}/
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${NAGDIR}/
	@${CP} -p ${WRKSRC}/*.php ${NAGDIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${INSTALL_DATA} ${WRKDIR}/httpd-nag.conf ${HORDE_INC}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${NAGDIR}/
	@${CHMOD} -R o-rwx ${CONFDIR}/
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
