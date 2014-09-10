# Created by: Daniel O'Connor
# $FreeBSD$

PORTNAME=	teamspeak3-server
PORTVERSION=	3.0.10.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	http://dl.4players.de/ts/releases/${PORTVERSION}/ \
		http://teamspeak.gameserver.gamed.de/ts3/releases/${PORTVERSION}/ \
		http://files.teamspeak-services.com/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}_freebsd-${TEAMSPEAK_ARCH}-${PORTVERSION}

MAINTAINER=	hirner@bitfire.at
COMMENT=	Server side of the TeamSpeak group voice chat system

LICENSE=	teamspeak
LICENSE_NAME=	TeamSpeak 3.x End User License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

LIB_DEPENDS=	libiconv.so.3:${PORTSDIR}/converters/libiconv

.ifdef (BATCH)
IGNORE=		license ${LICENSE} needs confirmation, but BATCH is defined
.endif

NO_BUILD=	yes
USE_LDCONFIG=	${LIBDIR}
USE_RC_SUBR=	teamspeak
SUB_FILES=	pkg-message
USE_GCC=        yes

RESTRICTED=	No redistribution
ONLY_FOR_ARCHS=	amd64 i386

USERS=	teamspeak
GROUPS=	teamspeak

CONFLICTS=	teamspeak_server-[0-9]*

PLIST_SUB+=	DBDIR=${DBDIR} \
		ETCDIR=${ETCDIR} \
		LOGDIR=${LOGDIR} \
		BINGRP=${BINGRP}

SUB_LIST+=	DBDIR=${DBDIR} \
		ETCDIR=${ETCDIR} \
		LOGDIR=${LOGDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} ==	"i386"
TEAMSPEAK_ARCH=	x86
.endif
.if ${ARCH} ==	"amd64"
TEAMSPEAK_ARCH=	amd64
.endif
WRKSRC=	${WRKDIR}/${PORTNAME}_freebsd-${TEAMSPEAK_ARCH}

DBDIR=	/var/db/teamspeak
ETCDIR=	${PREFIX}/etc/teamspeak
LIBDIR=	${PREFIX}/lib/teamspeak/server
LIBEXECDIR=	${PREFIX}/libexec
LOGDIR=	/var/log/teamspeak
SHAREDIR=	${PREFIX}/share/teamspeak/server
PORTDOCS=	ts3_serverquery_manual.pdf \
		permissiondoc.txt \
		privilegekey_guide.txt \
		server_quickstart.txt \
		server_upgrade.txt

do-install:
	@${MKDIR} ${STAGEDIR}${SHAREDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${SHAREDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${SHAREDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "sql serverquerydocs" ${STAGEDIR}${SHAREDIR})

	@${MKDIR} ${STAGEDIR}${LIBDIR}
	@${INSTALL_LIB} ${WRKSRC}/*.so ${STAGEDIR}${LIBDIR}

	@${INSTALL_PROGRAM} ${WRKSRC}/ts3server_freebsd_${TEAMSPEAK_ARCH} \
		${STAGEDIR}${LIBEXECDIR}/teamspeak_server

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.	for DOCFILE in ${PORTDOCS}
		@${INSTALL_DATA} ${WRKSRC}/doc/${DOCFILE} ${STAGEDIR}${DOCSDIR}
.	endfor

post-install:
	@${INSTALL} -d ${STAGEDIR}${DBDIR}
	@${INSTALL} -d ${STAGEDIR}${LOGDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
