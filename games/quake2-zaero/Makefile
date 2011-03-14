# New ports collection makefile for:	quake2-zaero
# Date created:				2006-12-24
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	zaero
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.alepulver.com.ar/distfiles/
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-src-${PORTVERSION}-2${EXTRACT_SUFX}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II Zaero Mission Pack

USE_ZIP=	yes
USE_DOS2UNIX=	*.[ch]
NO_WRKSUBDIR=	yes

OPTIONS=	DEMO "Install demo version of the game data" off \
		DM "Install deathmatch maps" off

DOCSDIR=	${PREFIX}/share/doc/${LATEST_LINK}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_DEMO)
DISTFILES+=	zaerodemo${EXTRACT_SUFX}
PLIST_SUB+=	DEMO=""
.else
PLIST_SUB+=	DEMO="@comment "
SUB_FILES+=	pkg-message
.endif

.if defined(WITH_DM)
DISTFILES+=	zaerodm${EXTRACT_SUFX}
PLIST_SUB+=	DM=""
.else
PLIST_SUB+=	DM="@comment "
.endif

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' ${WRKSRC}/q_shared.[ch]

do-install:
	${MKDIR} ${Q2DIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/game.so ${Q2DIR}/${PORTNAME}
.if defined(WITH_DEMO)
	${INSTALL_DATA} ${WRKSRC}/zaero/pak0.pak ${Q2DIR}/${PORTNAME}
	${MKDIR} ${Q2DIR}/${PORTNAME}/sprites
	${INSTALL_DATA} ${WRKSRC}/zaero/sprites/* ${Q2DIR}/${PORTNAME}/sprites
.endif
	${INSTALL_DATA} ${WRKSRC}/pak1.pak ${Q2DIR}/${PORTNAME}
.if defined(WITH_DM)
	${INSTALL_DATA} ${WRKSRC}/zaero/pak2.pak ${Q2DIR}/${PORTNAME}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changelog.txt ${DOCSDIR}
.endif

.if !defined(WITH_DEMO)
post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
