# New ports collection makefile for:	egroupware
# Date created:        27 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	eGroupware
PORTVERSION=	1.8.001.20110216
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}-1.8/${PORTNAME}-${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-egw-pear-${PORTVERSION}.tar.bz2

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A web based GroupWare system

BUILD_DEPENDS=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL \
		${PEARDIR}/Net/IMAP.php:${PORTSDIR}/mail/pear-Net_IMAP \
		${PEARDIR}/Net/Sieve.php:${PORTSDIR}/net/pear-Net_Sieve \
		${PEARDIR}/XML/Feed/Parser.php:${PORTSDIR}/textproc/pear-XML_Feed_Parser \
		${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log \
		${PEARDIR}/HTTP/WebDAV/Server.php:${PORTSDIR}/www/pear-HTTP_WebDAV_Server
RUN_DEPENDS=	${BUILD_DEPENDS}

PEARDIR=	${LOCALBASE}/share/pear
USE_BZIP2=	yes
USE_PHP=	session ctype
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	EG_DIR=${EG_DIR} \
		EG_DATA=${EG_DATA}

OPTIONS=	MYSQL "Use MySQL database" on \
		POSTGRE "Use PostgreSQL Database" off \
		IMAP "Enable Mail support in eGroupware" on \
		GD "Enable graphic support (needs xorg-libraries)" off \
		LDAP "Contacts can be stored using OpenLDAP" off \
		MBSTRING "Support for complete UTF-8 charsets" off

.include <bsd.port.pre.mk>
.if defined(WITH_MYSQL)
USE_PHP+=	mysql
USE_PHP+=	pdo_mysql
.endif
.if defined(WITH_POSTGRE)
USE_PHP+=	pgsql
#USE_PHP+=	pdo_pgsql
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif
.if defined(WITH_MBSTRING)
USE_PHP+=	mbstring
.endif
.if defined(WITH_IMAP)
USE_PHP+=	imap
.endif
.if defined(WITH_GD)
USE_PHP+=	gd
.endif
.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

WRKSRC=	${WRKDIR}/egroupware
EG_DIR=	www/eg
EG_WWWDIR=	${PREFIX}/${EG_DIR}
EG_DATA=	www/egdata
EG_DATADIR=	${PREFIX}/www/egdata

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s#${WRKSRC}#${EG_DIR}#g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s#${WRKSRC}#@dirrm ${EG_DIR}#g" >> ${PLIST}
	@${ECHO} @dirrm ${EG_DATA}/files >> ${PLIST}
	@${ECHO} @dirrm ${EG_DATA}/backup >> ${PLIST}
	@${ECHO} @dirrm ${EG_DATA} >> ${PLIST}

do-install:
	${MKDIR} ${EG_WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${EG_WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${EG_WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${EG_WWWDIR}' \
		>> ${TMPPLIST}
	${CHMOD} -R 755 ${EG_WWWDIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${EG_WWWDIR}' >> ${TMPPLIST}

	${MKDIR} ${EG_DATADIR}
	${MKDIR} ${EG_DATADIR}/files
	${MKDIR} ${EG_DATADIR}/backup
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${EG_DATADIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${EG_DATADIR}' \
		>> ${TMPPLIST}
	${CHMOD} -R 755 ${EG_DATADIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${EG_DATADIR}' >> ${TMPPLIST}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
