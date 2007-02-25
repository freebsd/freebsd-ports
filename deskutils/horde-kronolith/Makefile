# Ports collection makefile for:  Kronolith
# Date created:			  Sun Dec 02, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	kronolith
PORTVERSION=	2.1.4
CATEGORIES=	deskutils www
MASTER_SITES=	HORDE
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Kronolith is the Horde calendar application

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION
USE_PHP=	yes	# modules set by Horde, but needed to get PHP_VER
USE_GETTEXT=	yes

REINPLACE_ARGS=	-i ""
DOCS=		README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/RELEASE_NOTES docs/TODO docs/UPGRADING
CONFFILE=	keywords.php menu.php prefs.php
SUB_DIRS=	config js lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LKRONOLITHDIR?=	${LHORDEDIR}/kronolith

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	KRONOLITHDIR=${KRONOLITHDIR}
PLIST_SUB=	KRONOLITHDIR=${LKRONOLITHDIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}

KRONOLITHDIR=	${PREFIX}/${LKRONOLITHDIR}
CONFDIR=	${KRONOLITHDIR}/config

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes
.else
HORDE_INC=	${LOCALBASE}/etc/horde
.endif

pre-configure:
	@(cd ${WRKSRC}/scripts &&	\
		${FIND} . -name "*.php" -exec	\
		${REINPLACE_CMD} -e "s:/usr/local/bin/php: ${LOCALBASE}/bin/php:;s:/usr/bin/php: ${LOCALBASE}/bin/php:" {} \; )
	@${SED} -e "s:/home/httpd/html/horde/kronolith:${KRONOLITHDIR}:"	\
		${FILESDIR}/httpd.conf.kronolith > ${WRKDIR}/httpd-kronolith.conf

do-install:
	@${MKDIR}  ${KRONOLITHDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${KRONOLITHDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${KRONOLITHDIR}

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${KRONOLITHDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd-kronolith.conf ${HORDE_INC}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
