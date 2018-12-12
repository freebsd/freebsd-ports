# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	fracplanet
PORTVERSION=	0.5.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons.tar.gz:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive tool for creating random fractal planets and terrain

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}
qt5_PKGNAMESUFFIX=	-${FLAVOR}

qt4_DEPRECATED=		Qt4 has been EOL since december 2015
qt4_EXPIRATION_DATE=	2019-03-15

USES=		compiler:c++11-lang gl qmake:outsource
USE_GL=		gl glu
QMAKE_ARGS=	VERSION_NUMBER=${PORTVERSION}

.if ${FLAVOR} == qt4
USES+=	qt:4
USE_QT=		corelib gui moc_build opengl
.else
USES+=	qt:5
USE_QT=		buildtools_build core gui opengl
.endif

DESKTOP_ENTRIES=	"Fracplanet" \
			"" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Graphics;" \
			""
INSTALLS_ICONS=	yes
PORTDOCS=	*
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		DOXYGEN DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_IMPLIES=	DOCS

DOCFILES=	BUGS NEWS README THANKS fracplanet.css fracplanet.htm
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

post-patch:
	@${REINPLACE_CMD} -Ee 's|(OBJECTS_DIR)|#\1|' ${WRKSRC}/fracplanet.pro

post-build-DOXYGEN-on:
	cd ${WRKSRC} && doxygen .

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${STAGEDIR}${DOCSDIR})

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "html latex" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
