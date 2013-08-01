# Created by: Jimmy Olgeni <olgeni@uli.it>
# $FreeBSD$

PORTNAME=	eGroupware
PORTVERSION=	1.8.004.20130727
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}-1.8/${PORTNAME}-${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-egw-pear-${PORTVERSION}.tar.bz2

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	A web based GroupWare system

BUILD_DEPENDS=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL \
		${PEARDIR}/Net/IMAP.php:${PORTSDIR}/mail/pear-Net_IMAP \
		${PEARDIR}/Net/Sieve.php:${PORTSDIR}/net/pear-Net_Sieve \
		${PEARDIR}/XML/Feed/Parser.php:${PORTSDIR}/textproc/pear-XML_Feed_Parser \
		${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log \
		${PEARDIR}/HTTP/WebDAV/Server.php:${PORTSDIR}/www/pear-HTTP_WebDAV_Server
RUN_DEPENDS:=	${BUILD_DEPENDS}

PEARDIR=	${LOCALBASE}/share/pear
USE_BZIP2=	yes
USE_PHP=	session ctype zlib bz2 mcrypt xmlreader
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	EG_DIR=${EG_DIR} \
		EG_DATA=${EG_DATA}

OPTIONS_DEFINE=	MYSQL POSTGRES OSSL TNEF ZIP IMAP GD LDAP MBSTRING
OPTIONS_DEFAULT=MYSQL OSSL TNEF ZIP IMAP

OSSL_DESC=	enable SSL connection support
TNEF_DESC=	decoding winmail.dat attachments in felamimail support
IMAP_DESC=	IMAP support
MBSTRING_DESC=	Support multi-byte character sets
POSTGRES_DESC=	PostgreSQL database support
ZIP_DESC=	Install PHP zip extension

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
USE_PHP+=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MPOSTGRES}
USE_PHP+=	pgsql
USE_PHP+=	pdo_pgsql
.endif

.if ${PORT_OPTIONS:MMBSTRING}
USE_PHP+=	mbstring
.endif

.if ${PORT_OPTIONS:MIMAP}
USE_PHP+=	imap
.endif

.if ${PORT_OPTIONS:MOSSL}
USE_PHP+=	openssl
.endif

.if ${PORT_OPTIONS:MTNEF}
RUN_DEPENDS+=	tnef:${PORTSDIR}/converters/tnef
.endif

.if ${PORT_OPTIONS:MZIP}
USE_PHP+=	zip
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

.if ${PORT_OPTIONS:MLDAP}
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

.include <bsd.port.mk>
