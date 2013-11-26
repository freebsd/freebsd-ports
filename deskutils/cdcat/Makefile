# Created by: Aren Tyr <aren.tyr@gawab.com>
# $FreeBSD$

PORTNAME=	cdcat
PORTVERSION=	2.1
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

LICENSE=	GPLv2 MPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/archivers/p7zip:patch \
		${NONEXISTENT}:${PORTSDIR}/multimedia/mediainfo:build
LIB_DEPENDS=	libtar.so:${PORTSDIR}/devel/libtar \
		libexif.so:${PORTSDIR}/graphics/libexif

OPTIONS_DEFINE=	DOCS

CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}

USES=		qmake
USE_BZIP2=	yes
USE_QT4=	corelib gui xml \
		linguist_build moc_build uic_build
INSTALLS_ICONS=	yes

QMAKE_ARGS+=	INCLUDEPATH+="${L7Z_WRKSRC}/Lib7Zip" \
		INCLUDEPATH+="${MIF_WRKSRC}/MediaInfoLib/Source" \
		INCLUDEPATH+="${MIF_WRKSRC}/ZenLib/Source" \
		LIBS+="${L7Z_WRKSRC}/Lib7Zip/lib7zip.a" \
		LIBS+="${MIF_WRKSRC}/MediaInfoLib/Project/GNU/Library/.libs/libmediainfo.a" \
		LIBS+="${MIF_WRKSRC}/ZenLib/Project/GNU/Library/.libs/libzen.a" \
		LIBS+="-lz -lbz2 -ltar -lexif" \
		DEFINES+="MEDIAINFO_STATIC" \
		DEFINES+="MEDIAINFO_UNICODE" \
		DEFINES+="USE_LIBEXIF"
QMAKE_SOURCE_PATH=	${BUILD_WRKSRC}/cdcat.pro

# spoof tinderbox: build deps for multimedia/mediainfo
USE_AUTOTOOLS=	autoconf:env automake:env libtool:env

PORTDOCS=	Authors ChangeLog README TRANSLATORS_README
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/${PORTNAME}.png
.for lang in cz de el es fr hu id it pl pt sk sr
PLIST_FILES+=	%%DATADIR%%/translations/${PORTNAME}_${lang}.qm
.endfor
.for size in 16 22 32 48 64
PLIST_FILES+=	share/icons/hicolor/${size}x${size}/apps/${PORTNAME}_logo.png
.endfor
PLIST_FILES+=	share/icons/hicolor/scalable/apps/${PORTNAME}_logo.svg
PLIST_DIRS=	%%DATADIR%%/translations %%DATADIR%%

L7Z_NAME=	lib7zip
L7Z_VERSION=	1.6.3
L7Z_DISTFILE=	${L7Z_NAME}-${L7Z_VERSION}.tar.gz
L7Z_WRKSRC=	${WRKDIR}/${L7Z_NAME}

.include <bsd.port.pre.mk>

P7Z_WRKSRC=	$$(cd ${PORTSDIR}/archivers/p7zip && ${MAKE} -V WRKSRC)
MIF_WRKSRC=	$$(cd ${PORTSDIR}/multimedia/mediainfo && ${MAKE} -V WRKSRC)

post-extract:
	@${GZCAT} ${DISTDIR}/${L7Z_DISTFILE} | (cd ${WRKDIR} && ${TAR} -xf -)
	@${LN} -sf ${L7Z_NAME}-${L7Z_VERSION} ${L7Z_WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e \
		'/LIBS/s|^|#|' ${BUILD_WRKSRC}/cdcat.pro
	@${REINPLACE_CMD} -e \
		's|/dev/sr0|/dev/cd0|' ${BUILD_WRKSRC}/config.cpp
	@${REINPLACE_CMD} -e \
		's|-ldl||' ${L7Z_WRKSRC}/Test7Zip/Makefile.in

pre-configure:
	@cd ${L7Z_WRKSRC} && ./configure --disable-shared \
		CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		P7ZIP_SOURCE_DIR="${P7Z_WRKSRC}"
	@${LRELEASE} ${BUILD_WRKSRC}/cdcat.pro

pre-build:
	@cd ${L7Z_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${BUILD_WRKSRC}/lang/*.qm ${STAGEDIR}${DATADIR}/translations
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}_logo.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}_logo.svg
.for size in 16 22 32 48 64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}_logo_${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}_logo.png
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
