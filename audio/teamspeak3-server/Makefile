# New ports collection makefile for:	teamspeak_server
# Date created:				22 January 2003
# Whom:					Daniel O'Connor
#
# $FreeBSD$
#

PORTNAME=	teamspeak_server
PORTVERSION=	2.0.19.40
PORTREVISION=1
CATEGORIES=	audio net
MASTER_SITES=	ftp://ftp2.teamspeak.org/releases/ \
		ftp://teamspeak.krawall.de/releases/
DISTNAME=	ts2_server_rc2_201940

MAINTAINER=	darius@dons.net.au
COMMENT=	Server side of the TeamSpeak group voice chat system

WRKSRC=		${WRKDIR}/tss2_rc2
ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
NO_BUILD=	yes
USE_LINUX?=	yes
NO_FILTER_SHLIBS=yes

do-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
	${MKDIR} ${PREFIX}/lib/teamspeak_server
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${PREFIX}/lib/teamspeak_server -xf -
	${SED} -e 's#%%TSHOME%%#${PREFIX}/lib/teamspeak_server#' <${FILESDIR}/teamspeak_server.sh >${WRKSRC}/teamspeak_server.sh
	${INSTALL_SCRIPT} ${WRKSRC}/teamspeak_server.sh ${PREFIX}/etc/rc.d/teamspeak_server.sh.sample
	${RM} ${WRKSRC}/teamspeak_server.sh
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

post-deinstall:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDEINSTALL} ${PORTNAME} POST-DEINSTALL

.include <bsd.port.pre.mk>
PKGDEINSTALL=	${PKGINSTALL}
.include <bsd.port.post.mk>
