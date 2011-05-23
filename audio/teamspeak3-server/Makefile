# Ports collection Makefile for:	teamspeak3-server
# Date created:				22 January 2003
# Whom:					Daniel O'Connor
#
# $FreeBSD$
#

PORTNAME=	teamspeak3-server
PORTVERSION=	3.0.0
CATEGORIES=	audio net
MASTER_SITES=	http://teamspeak.gameserver.gamed.de/ts3/releases/rc1/ \
		http://ftp.4players.de/pub/hosted/ts3/releases/rc1/
DISTNAME=	${PORTNAME}_freebsd-${TEAMSPEAK_ARCH}-3.0.0-rc1

MAINTAINER=	hirner@bitfire.at
COMMENT=	Server side of the TeamSpeak group voice chat system

USE_ICONV=	yes
USE_LDCONFIG=	${PREFIX}/lib/teamspeak/server
USE_RC_SUBR=	teamspeak
SUB_FILES=	pkg-message

RESTRICTED=	No redistribution
ONLY_FOR_ARCHS=	amd64 i386

NO_BUILD=	yes

USERS=	teamspeak
GROUPS=	teamspeak

LICENSE=	teamspeak
LICENSE_NAME=	TeamSpeak 3.x End User License Agreement
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept
LICENSE_FILE=	${FILESDIR}/LICENSE

CONFLICTS=	teamspeak_server-[0-9]*

.include <bsd.port.pre.mk>

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
LIBEXECDIR=	${PREFIX}/libexec/
LOGDIR=	/var/log/teamspeak
SHAREDIR=	${PREFIX}/share/teamspeak/server
PORTDOCS=	ts3_serverquery_manual.pdf \
		permissiondoc.txt \
		server_quickstart.txt \
		server_upgrade.txt

do-install:
	@${MKDIR} ${LIBDIR} ${SHAREDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${SHAREDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${SHAREDIR}
	@${INSTALL_LIB} ${WRKSRC}/*.so ${LIBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/ts3server_freebsd_${TEAMSPEAK_ARCH} \
		${LIBEXECDIR}/teamspeak_server
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "sql serverquerydocs" ${SHAREDIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for DOCFILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${DOCFILE} ${DOCSDIR}
.   endfor
.endif

post-install:
	@${MKDIR} ${DBDIR} && ${CHOWN} -R ${USERS}:${GROUPS} ${DBDIR}
	@${MKDIR} ${ETCDIR}
	@${MKDIR} ${LOGDIR} && ${CHOWN} -R ${USERS}:${BINGRP} ${LOGDIR}
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
