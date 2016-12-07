# Created by: Aren Tyr <aren.tyr@gawab.com>
# $FreeBSD$

PORTNAME=	cdcat
PORTVERSION=	2.3.1
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt based tool for offline CD/DVD/disk catalogs

LICENSE=	GPLv2 MPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	cryptopp>0:security/cryptopp
LIB_DEPENDS=	libtar.so:devel/libtar \
		libexif.so:graphics/libexif \
		libmediainfo.so:multimedia/libmediainfo \
		libzen.so:multimedia/libzen

CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}

USES=		libtool qmake:norecursive tar:bzip2
USE_QT4=	corelib gui xml linguisttools_build moc_build uic_build
QMAKE_ARGS=	LIBS+="${LOCALBASE}/lib/libcryptopp.a" \
		LIBS+="-lz -lbz2 -ltar -lexif -lmediainfo -lzen" \
		DEFINES+="MEDIAINFO_STATIC" \
		DEFINES+="MEDIAINFO_UNICODE" \
		DEFINES+="USE_LIBEXIF"
QMAKE_SOURCE_PATH=	${BUILD_WRKSRC}/${PORTNAME}.pro
INSTALLS_ICONS=	yes

PORTDOCS=	Authors ChangeLog README TRANSLATORS_README
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/${PORTNAME}.png
.for lang in cz de el es fr hu id it pl pt ru sk sr
PLIST_FILES+=	%%DATADIR%%/translations/${PORTNAME}_${lang}.qm
.endfor
.for size in 16 22 32 48 64
PLIST_FILES+=	share/icons/hicolor/${size}x${size}/apps/${PORTNAME}_logo.png
.endfor
PLIST_FILES+=	share/icons/hicolor/scalable/apps/${PORTNAME}_logo.svg

DESKTOP_ENTRIES="CdCat" "Hyper's CD Catalog" "${DATADIR}/${PORTNAME}.png" \
		"${PORTNAME}" "AudioVideo;Qt;" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/USE_LIB7ZIP/s|^|#| ; \
		 /LIBS/s|^|#|' ${BUILD_WRKSRC}/${PORTNAME}.pro
	@${REINPLACE_CMD} -e \
		's|/dev/sr0|/dev/cd0|' ${BUILD_WRKSRC}/config.cpp
.for i in newdbdialog.cpp wdbfile.h
	@${REINPLACE_CMD} -e \
		's|crypto++/|cryptopp/|' ${BUILD_WRKSRC}/${i}
.endfor

pre-configure:
	@${LRELEASE} ${BUILD_WRKSRC}/${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${BUILD_WRKSRC}/lang/*.qm \
		${STAGEDIR}${DATADIR}/translations
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}_logo.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
.for size in 16 22 32 48 64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}_logo_${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}_logo.png
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
