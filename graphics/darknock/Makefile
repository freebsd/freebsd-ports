# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	darknock
PORTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that can detect edges in images

LICENSE=	GPLv2 # (or later)

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT4=	gui linguist_build moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

PORTDOCS=	changelog
PLIST_FILES=	bin/darknock share/pixmaps/darknock.png

DESKTOP_ENTRIES=	"${PORTNAME}" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
			"${PORTNAME}" \
			"Graphics;Qt;" \
			"false"

LRELEASE=	${QT_PREFIX}/bin/lrelease-qt4

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
.for lang in fr it pl ro sv tr
PLIST_FILES+=	%%DATADIR%%/locale/darknock_${lang}.qm
.endfor
PLIST_DIRS+=	%%DATADIR%%/locale %%DATADIR%%
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/darknock|${DATADIR}|g' \
		${WRKSRC}/src/main.cpp

pre-build:
	@${LRELEASE} ${BUILD_WRKSRC}/${PORTNAME}.pro
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.png ${PREFIX}/share/pixmaps
.if ${PORT_OPTIONS:MNLS}
	@${MKDIR} ${DATADIR}/locale
	${INSTALL_DATA} ${WRKSRC}/locale/*.qm ${DATADIR}/locale
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
