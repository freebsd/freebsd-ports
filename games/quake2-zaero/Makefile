# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

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

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
USES=		dos2unix zip
DOS2UNIX_FILES=	*.[ch]
NO_WRKSUBDIR=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

OPTIONS_DEFINE=	DEMO DM_MAPS DOCS
OPTIONS_SUB=	yes

DEMO_DESC=	Demo version of the game data
DM_MAPS_DESC=	Install deathmatch maps

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEMO}
DISTFILES+=	zaerodemo${EXTRACT_SUFX}
.else
SUB_FILES+=	pkg-message
.endif

.if ${PORT_OPTIONS:MDM_MAPS}
DISTFILES+=	zaerodm${EXTRACT_SUFX}
.endif

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' ${WRKSRC}/q_shared.[ch]

do-install:
	@${MKDIR} ${STAGEDIR}${Q2DIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/game.so ${STAGEDIR}${Q2DIR}/${PORTNAME}
.if ${PORT_OPTIONS:MDEMO}
	${INSTALL_DATA} ${WRKSRC}/zaero/pak0.pak ${STAGEDIR}${Q2DIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${Q2DIR}/${PORTNAME}/sprites
	${INSTALL_DATA} ${WRKSRC}/zaero/sprites/* \
		${STAGEDIR}${Q2DIR}/${PORTNAME}/sprites
.endif
	${INSTALL_DATA} ${WRKSRC}/pak1.pak ${STAGEDIR}${Q2DIR}/${PORTNAME}
.if ${PORT_OPTIONS:MDM_MAPS}
	${INSTALL_DATA} ${WRKSRC}/zaero/pak2.pak \
		${STAGEDIR}${Q2DIR}/${PORTNAME}
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changelog.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
