# Created by: Jimmy Olgeni <olgeni@uli.it>
# $FreeBSD$

PORTNAME=	eGroupware
PORTVERSION=	14.3.20160428
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}-14.3/${PORTNAME}-${PORTVERSION}
DISTFILES=	${PORTNAME:tl}-epl-${PORTVERSION}.tar.bz2

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Web-based GroupWare system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

USES=		cpe tar:bzip2
USE_PHP=	bcmath bz2 ctype json mcrypt session simplexml xmlreader zlib
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	EG_DIR=${EG_DIR} \
		EG_DATA=${EG_DATA}

OPTIONS_DEFINE=	MYSQL POSTGRES OSSL ZIP GD LDAP MBSTRING
OPTIONS_DEFAULT=MYSQL OSSL ZIP

OSSL_DESC=	Enable SSL connection support
MBSTRING_DESC=	Support multi-byte character sets
POSTGRES_DESC=	PostgreSQL database support
ZIP_DESC=	Install PHP zip extension

MYSQL_USE=	PHP=mysqli,pdo_mysql
POSTGRES_USE=	PHP=pgsql,pdo_pgsql
MBSTRING_USE=	PHP=mbstring
OSSL_USE=	PHP=openssl
ZIP_USE=	PHP=zip
GD_USE=		PHP=gd
LDAP_USE=	PHP=ldap

WRKSRC=	${WRKDIR}/egroupware
EG_DIR=	www/eg
EG_WWWDIR=	${PREFIX}/${EG_DIR}
EG_DATA=	www/egdata
EG_DATADIR=	${PREFIX}/${EG_DATA}

pre-install:
	@${ECHO_CMD} '@owner ${WWWOWN}' > ${PLIST}
	@${ECHO_CMD} '@group ${WWWGRP}' >> ${PLIST}
	@${ECHO_CMD} '@mode 755' >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s#${WRKSRC}#${EG_DIR}#g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s#${WRKSRC}#@dir ${EG_DIR}#g" >> ${PLIST}
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
