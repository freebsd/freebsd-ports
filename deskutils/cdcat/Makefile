# Created by: Aren Tyr <aren.tyr@gawab.com>
# $FreeBSD$

PORTNAME=	cdcat
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		GOOGLE_CODE:lib7zip
PROJECTHOST=	lib7zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${L7Z_DISTFILE}:lib7zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt based tool for offline CD/DVD/disk catalogs

BROKEN=		Fails to build with new p7zip

LICENSE=	GPLv2 MPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/archivers/p7zip:patch \
		cryptopp>0:${PORTSDIR}/security/cryptopp
LIB_DEPENDS=	libtar.so:${PORTSDIR}/devel/libtar \
		libexif.so:${PORTSDIR}/graphics/libexif \
		libmediainfo.so:${PORTSDIR}/multimedia/libmediainfo \
		libzen.so:${PORTSDIR}/multimedia/libzen

CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}

USES=		libtool qmake:norecursive tar:bzip2
USE_QT4=	corelib gui xml linguist_build moc_build uic_build
QMAKE_ARGS=	INCLUDEPATH+="${L7Z_WRKSRC}/Lib7Zip" \
		LIBS+="${L7Z_WRKSRC}/Lib7Zip/lib7zip.a" \
		LIBS+="${LOCALBASE}/lib/libcryptopp.a" \
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

L7Z_NAME=	lib7zip
L7Z_VERSION=	1.6.5
L7Z_DISTFILE=	${L7Z_NAME}-${L7Z_VERSION}.tar.gz
L7Z_WRKSRC=	${WRKDIR}/${L7Z_NAME}

.include <bsd.port.pre.mk>

P7Z_WRKSRC=	$$(cd ${PORTSDIR}/archivers/p7zip && ${MAKE_CMD} -V WRKSRC)

post-extract:
	@${GZCAT} ${DISTDIR}/${L7Z_DISTFILE} | (cd ${WRKDIR} && ${TAR} -xf -)
	@${LN} -sf ${L7Z_NAME}-${L7Z_VERSION} ${L7Z_WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e \
		'/LIBS/s|^|#|' ${BUILD_WRKSRC}/${PORTNAME}.pro
	@${REINPLACE_CMD} -e \
		's|/dev/sr0|/dev/cd0|' ${BUILD_WRKSRC}/config.cpp
.for i in newdbdialog.cpp wdbfile.h
	@${REINPLACE_CMD} -e \
		's|crypto++/|cryptopp/|' ${BUILD_WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e \
		's|-ldl||' ${L7Z_WRKSRC}/Test7Zip/Makefile.in

pre-configure:
	@cd ${L7Z_WRKSRC} && ./configure --disable-shared \
		CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		P7ZIP_SOURCE_DIR="${P7Z_WRKSRC}"
	@${LRELEASE} ${BUILD_WRKSRC}/${PORTNAME}.pro

pre-build:
	@cd ${L7Z_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	(cd ${BUILD_WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTNAME}.png \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	(cd ${BUILD_WRKSRC}/lang && ${INSTALL_DATA} *.qm \
		${STAGEDIR}${DATADIR}/translations)
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTNAME}_logo.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps)
.for size in 16 22 32 48 64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTNAME}_logo_${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}_logo.png)
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.post.mk>
