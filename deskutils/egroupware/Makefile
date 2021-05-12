# Created by: Jimmy Olgeni <olgeni@uli.it>

PORTNAME=	eGroupware
PORTVERSION=	20.1.20210503
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME:tl}/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME:tl}-docker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based GroupWare system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${PORTNAME:tl}/doc/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/pear/Net/Sieve.php:net/pear-Net_Sieve@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Horde/Imap/Client.php:mail/pear-Horde_Imap_Client@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Horde/Nls.php:devel/pear-Horde_Nls@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Horde/Mail/Transport.php:mail/pear-Horde_Mail@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Horde/Smtp.php:mail/pear-Horde_Smtp@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Horde/Compress.php:archivers/pear-Horde_Compress@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Horde/Icalendar.php:devel/pear-Horde_Icalendar@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Horde/Mapi.php:mail/pear-Horde_Mapi@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Horde/Crypt.php:security/pear-Horde_Crypt@${PHP_FLAVOR} \
		${LOCALBASE}/share/APCu/apc.php:devel/pecl-APCu@${PHP_FLAVOR}

USES=		cpe php tar:bzip2
USE_PHP=	bcmath bz2 ctype filter json session simplexml tidy xsl xmlreader zlib
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	EG_DIR=${EG_DIR} \
		EG_DATA=${EG_DATA}

GH_ACCOUNT=	EGroupware

OPTIONS_DEFINE=	MYSQL POSTGRES SSL ZIP GD LDAP MBSTRING
OPTIONS_DEFAULT=MYSQL SSL ZIP

MBSTRING_DESC=	Support multi-byte character sets
POSTGRES_DESC=	PostgreSQL database support
ZIP_DESC=	Install PHP zip extension

MYSQL_USE=	PHP=mysqli,pdo_mysql
POSTGRES_USE=	PHP=pgsql,pdo_pgsql
MBSTRING_USE=	PHP=mbstring
SSL_USE=	PHP=openssl
ZIP_USE=	PHP=zip
GD_USE=		PHP=gd
LDAP_USE=	PHP=ldap

WRKSRC=	${WRKDIR}/egroupware
EG_DIR=	www/eg
EG_WWWDIR=	${PREFIX}/${EG_DIR}
EG_DATA=	www/egdata
EG_DATADIR=	${PREFIX}/${EG_DATA}

pre-install:
	@${ECHO_CMD} '@mode 644' > ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s#${WRKSRC}#${EG_DIR}#g" >> ${PLIST}
	@${ECHO_CMD} '@mode' >> ${PLIST}
	@${ECHO_CMD} '@mode 755' >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s#${WRKSRC}#@dir ${EG_DIR}#g" >> ${PLIST}
	@${ECHO_CMD} '@owner ${WWWOWN}' >> ${PLIST}
	@${ECHO_CMD} '@group ${WWWGRP}' >> ${PLIST}
	@${ECHO} @dir ${EG_DATA}/files >> ${PLIST}
	@${ECHO} @dir ${EG_DATA}/backup >> ${PLIST}
	@${ECHO} @dir ${EG_DATA} >> ${PLIST}
	@${ECHO_CMD} '@group' >> ${PLIST}
	@${ECHO_CMD} '@owner' >> ${PLIST}
	@${ECHO_CMD} '@mode' >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${EG_WWWDIR}
	@${MKDIR} ${STAGEDIR}${EG_DATADIR}
	@${MKDIR} ${STAGEDIR}${EG_DATADIR}/files
	@${MKDIR} ${STAGEDIR}${EG_DATADIR}/backup
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${EG_WWWDIR}

.include <bsd.port.mk>
