# New ports collection makefile for:	darknock
# Date created:		5 August 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	darknock
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that can detect edges in images

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build linguist_build gui
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
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Qt;KDE;Graphics;" \
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
