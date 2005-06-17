# New ports collection makefile for:	teamspeak
# Date created:				22 January 2003
# Whom:					Daniel O'Connor
#
# $FreeBSD$
#

PORTNAME=	teamspeak_client
PORTVERSION=	2.0.32
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.freenet.de/pub/4players/teamspeak.org/releases/:main \
		http://www.gsoft.com.au/~doconnor/:misc
DISTNAME=	ts2_client_rc2_2032
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main setduplexfake.so.gz:misc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	darius@dons.net.au
COMMENT=	Client side of a group voice chat system

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
USE_LINUX=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/teamspeak_client
	${TAR} -C ${WRKSRC}/setup.data/image -cf ${WRKSRC}/files.tar ./
	${TAR} -C ${PREFIX}/lib/teamspeak_client -xf ${WRKSRC}/files.tar
	${GZIP_CMD} -dc ${DISTDIR}/setduplexfake.so.gz >${PREFIX}/lib/teamspeak_client/setduplexfake.so
	${SED} -e 's#%%TSHOME%%#${PREFIX}/lib/teamspeak_client#' <${FILESDIR}/TeamSpeak >${WRKSRC}/TeamSpeak
	${INSTALL_SCRIPT} ${WRKSRC}/TeamSpeak ${PREFIX}/bin/

.include <bsd.port.mk>
