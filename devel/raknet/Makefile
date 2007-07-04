# New ports collection makefile for:	RakNet
# Date created:				11 October 2005
# Whom:					Andrew Baznikin <dikiy@scn.ru>
#
# $FreeBSD$
#

PORTNAME=	raknet
PORTVERSION=	2.0.13
CATEGORIES=	devel net
MASTER_SITES=	http://www.rakkarsoft.com/raknet/downloads/
DISTNAME=	RakNet

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Networking API that provides reliable UDP primarily for online games

USE_ZIP=	yes
USE_LDCONFIG=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	[^ ]*/(makefile.*|.*\.([^x]|cpp))
WRKSRC=		${WRKDIR}
PORTDOCS=	*

post-patch: .SILENT
	${FIND} ${WRKSRC} -name CVS -delete
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" -e "s|-lpthread|${PTHREAD_LIBS}|" -e "s|-fPIC|-fPIC ${CFLAGS}|" ${WRKSRC}/makefile.defs
	${REINPLACE_CMD} -e "s|rm -f|#rm -f|g" -e "s|ln -s|${LN} -sf|" ${WRKSRC}/Makefile
	${MKDIR} ${WRKSRC}/Lib/linux
	${LN} -s ${WRKSRC}/Lib ${WRKSRC}/lib
# Some GCC 4.2 gimmick
	${REINPLACE_CMD} -e 's,PlayerID::,,' ${WRKSRC}/Include/NetworkTypes.h
	${REINPLACE_CMD} -e 's,RakVoice::,,' ${WRKSRC}/Include/RakVoice/RakVoice.h
	${ECHO_CMD} -e '3730,$$t62\n3863,$$d\nwq' | ${ED} -s \
		${WRKSRC}/Source/RakPeer.cpp

post-install:
	${LN} -sf ${PREFIX}/lib/libraknet.so.2.0.13 ${PREFIX}/lib/libraknet.so.0
	${LN} -sf ${PREFIX}/lib/librakvoice.so.2.0.13 ${PREFIX}/lib/librakvoice.so.0
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/DOxygen
	@cd ${WRKDIR}/Help && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKDIR}/Help && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

ED?=	/bin/ed

.include <bsd.port.mk>
