# New ports collection makefile for:	teamspeak
# Date created:				22 January 2003
# Whom:					Daniel O'Connor
#
# $FreeBSD$
#

PORTNAME=	teamspeak_client
PORTVERSION=	2.0.26.27
CATEGORIES=	audio
MASTER_SITES=	http://www.teamspeak.org/files/ \
		http://www.gsoft.com.au/~doconnor/
DISTNAME=	ts2_client_rc1_2026
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
	${TAR} -C ${PREFIX}/lib/teamspeak_client -xf ${WRKSRC}/setup.data/files.tar
	${LN} -fs ${PREFIX}/lib/teamspeak_client/libborqt-6.9.0-qt2.3.so ${PREFIX}/lib/teamspeak_client/libborqt-6.9-qt2.3.so
	${GZIP_CMD} -dc ${DISTDIR}/setduplexfake.so.gz >${PREFIX}/lib/teamspeak_client/setduplexfake.so
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/clicense.txt ${DOCSDIR}
	${SED} -e 's#%%TSHOME%%#${PREFIX}/lib/teamspeak_client#' <${FILESDIR}/TeamSpeak >${WRKSRC}/TeamSpeak
	${INSTALL_SCRIPT} ${WRKSRC}/TeamSpeak ${PREFIX}/bin/

.include <bsd.port.mk>
