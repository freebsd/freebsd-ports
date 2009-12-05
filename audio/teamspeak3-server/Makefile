# New ports collection makefile for:	teamspeak_server
# Date created:				22 January 2003
# Whom:					Daniel O'Connor
#
# $FreeBSD$
#

PORTNAME=	teamspeak_server
PORTVERSION=	2.0.24.01
CATEGORIES=	audio net
MASTER_SITES=	ftp://ftp.freenet.de/pub/4players/teamspeak.org/releases/:0 \
		ftp://ftp.freenet.de/pub/4players/teamspeak.org/developer/server/202401/:1
DISTFILES=	ts2_server_rc2_202319.tar.bz2:0 server_linux:1
DIST_SUBDIR=	teamspeak
EXTRACT_ONLY=	ts2_server_rc2_202319.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server side of the TeamSpeak group voice chat system

WRKSRC=		${WRKDIR}/tss2_rc2
ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
USE_LINUX=	yes
PKGDEINSTALL=	${PKGINSTALL}

USE_RC_SUBR=	teamspeak-server

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/lib/teamspeak_server
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${PREFIX}/lib/teamspeak_server -xf -
	@${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/server_linux \
                 ${PREFIX}/lib/teamspeak_server

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

post-deinstall:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDEINSTALL} ${PORTNAME} POST-DEINSTALL

.include <bsd.port.mk>
