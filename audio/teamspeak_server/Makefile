# New ports collection makefile for:	teamspeak_server
# Date created:				22 January 2003
# Whom:					Daniel O'Connor
#
# $FreeBSD$
#

PORTNAME=	teamspeak_server
PORTVERSION=	2.0.19.40
CATEGORIES=	audio net
MASTER_SITES=	http://www.teamspeak.org/files/ \
		ftp://ftp.ngz-network.de/pub/11/4/releases/ \
		http://www.gsoft.com.au/~doconnor/
DISTNAME=	ts2_server_rc2_201940

MAINTAINER=	darius@dons.net.au
COMMENT=	Server side of the TeamSpeak group voice chat system

WRKSRC=		${WRKDIR}/tss2_rc2
USE_BZIP2=	yes
NO_BUILD=	yes
USE_LINUX=	yes
NO_FILTER_SHLIBS=yes

do-install:
	${MKDIR} ${PREFIX}/lib/teamspeak_server
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${PREFIX}/lib/teamspeak_server -xf -
	${CHMOD} -R u+w ${PREFIX}/lib/teamspeak_server
	${SED} -e 's#%%TSHOME%%#${PREFIX}/lib/teamspeak_server#' <${FILESDIR}/teamspeak_server.sh >${WRKSRC}/teamspeak_server.sh
	${INSTALL_SCRIPT} ${WRKSRC}/teamspeak_server.sh ${PREFIX}/etc/rc.d/
	${RM} ${WRKSRC}/teamspeak_server.sh

.include <bsd.port.mk>
