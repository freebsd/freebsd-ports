# Created by: Daniel O'Connor
# $FreeBSD$

PORTNAME=	teamspeak3-server
PORTVERSION=	3.13.3
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	https://files.teamspeak-services.com/releases/server/${PORTVERSION}/
DISTNAME=	${PORTNAME}_freebsd_${TEAMSPEAK_ARCH}-${PORTVERSION}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Server side of the TeamSpeak group voice chat system

LICENSE=	teamspeak
LICENSE_NAME=	TeamSpeak 3.x End User License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		tar:bz2
USE_LDCONFIG=	${LIBDIR}
USE_RC_SUBR=	teamspeak

NO_BUILD=	yes
SUB_FILES=	pkg-message

USERS=	teamspeak
GROUPS=	teamspeak

CONFLICTS=	teamspeak_server-[0-9]*

PLIST_SUB=	DBDIR=${DBDIR} \
		ETCDIR=${ETCDIR} \
		LOGDIR=${LOGDIR} \
		BINGRP=${BINGRP}

SUB_LIST=	DBDIR=${DBDIR} \
		ETCDIR=${ETCDIR} \
		LOGDIR=${LOGDIR}

PORTDOCS=	accounting.txt \
		permissiondoc.txt \
		privilegekey_guide.txt \
		server_quickstart.md \
		server_upgrade.txt \
		update_mysql_to_mariadb.txt \
		webquery.md

OPTIONS_DEFINE=	DOCS MYSQL

MYSQL_USES=	mysql:server
MYSQL_VARS=	SUB_LIST+=MYSQL=mysql
MYSQL_VARS_OFF=	SUB_LIST+=MYSQL=

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
TEAMSPEAK_ARCH=	x86
.elif ${ARCH} == "amd64"
TEAMSPEAK_ARCH=	amd64
.endif

WRKSRC=	${WRKDIR}/${PORTNAME}_freebsd_${TEAMSPEAK_ARCH}

DBDIR=	/var/db/teamspeak
ETCDIR=	${PREFIX}/etc/teamspeak
LIBDIR=	${PREFIX}/lib/teamspeak/server
LIBEXECDIR=	${PREFIX}/libexec
LOGDIR=	/var/log/teamspeak
SHAREDIR=	${PREFIX}/share/teamspeak/server

do-install:
	@${MKDIR} ${STAGEDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${SHAREDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "sql serverquerydocs" ${STAGEDIR}${SHAREDIR})

	@${MKDIR} ${STAGEDIR}${LIBDIR}
	${INSTALL_LIB} ${WRKSRC}/*.so ${STAGEDIR}${LIBDIR}
	${INSTALL_LIB} ${WRKSRC}/redist/*.so* ${STAGEDIR}${LIBDIR}

	${INSTALL_PROGRAM} ${WRKSRC}/ts3server \
		${STAGEDIR}${LIBEXECDIR}/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.	for DOCFILE in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/${DOCFILE} ${STAGEDIR}${DOCSDIR}
.	endfor

	${INSTALL} -d ${STAGEDIR}${DBDIR}
	${INSTALL} -d ${STAGEDIR}${LOGDIR}
	${INSTALL} -d ${STAGEDIR}${ETCDIR}

# Add link to serverquerydocs, this needs to be in the
# same directory as chdir or help commands will fail.
	${RLN} ${STAGEDIR}${SHAREDIR}/serverquerydocs ${STAGEDIR}${DBDIR}

.include <bsd.port.mk>
