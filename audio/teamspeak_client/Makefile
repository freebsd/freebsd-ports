# New ports collection makefile for:	teamspeak
# Date created:				22 January 2003
# Whom:					Daniel O'Connor
#
# $FreeBSD$
#

PORTNAME=	teamspeak_client
PORTVERSION=	2.0.29.47
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.teamspeak.org/releases/ \
		http://www.gsoft.com.au/~doconnor/ \
		ftp://teamspeak.krawall.de/releases/
DISTNAME=	ts2_client_rc2_2029
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} setduplexfake.so.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	darius@dons.net.au
COMMENT=	Client side of a group voice chat system

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

USE_BZIP2=	yes
NO_BUILD=	yes
USE_LINUX=	yes
NO_FILTER_SHLIBS=yes

do-install:
	${MKDIR} ${PREFIX}/lib/teamspeak_client
	${TAR} -C ${WRKSRC}/setup.data/image -cf ${WRKSRC}/files.tar ./
	${TAR} -C ${PREFIX}/lib/teamspeak_client -xf ${WRKSRC}/files.tar
	${GZIP_CMD} -dc ${DISTDIR}/setduplexfake.so.gz >${PREFIX}/lib/teamspeak_client/setduplexfake.so
	${SED} -e 's#%%TSHOME%%#${PREFIX}/lib/teamspeak_client#' <${FILESDIR}/TeamSpeak >${WRKSRC}/TeamSpeak
	${INSTALL_SCRIPT} ${WRKSRC}/TeamSpeak ${PREFIX}/bin/

.include <bsd.port.mk>
