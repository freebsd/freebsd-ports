# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	darknock
DISTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that can detect edges in images

USE_QT4=	qmake_build moc_build rcc_build uic_build linguist_build gui
WRKSRC=		${WRKDIR}/${PORTNAME}
LRELEASE=	${QT_PREFIX}/bin/lrelease-qt4
MAKE_JOBS_SAFE=	yes

PORTDOCS=	changelog copyright

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

DESKTOP_ENTRIES=	"${PORTNAME}" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
			"${PORTNAME}" \
			"Graphics;Qt;" \
			"false"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/darknock|${DATADIR}|g' \
		${WRKSRC}/src/main.cpp

pre-build:
	@${LRELEASE} ${BUILD_WRKSRC}/${PORTNAME}.pro
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.png ${PREFIX}/share/pixmaps
.if !defined(WITHOUT_NLS)
	@${MKDIR} ${DATADIR}/locale
	@${INSTALL_DATA} ${WRKSRC}/locale/*.qm ${DATADIR}/locale
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
