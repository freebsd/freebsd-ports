# New ports collection makefile for:	cdcat
# Date created: 			04 May 2006
# Whom: 				Aren Tyr <aren.tyr@gawab.com>
#
# $FreeBSD$
#

PORTNAME=	cdcat
PORTVERSION=	1.8
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		GOOGLE_CODE:lib7zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${L7Z_DISTFILE}:lib7zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A QT based tool for offline CD/DVD/disk catalogs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/archivers/p7zip:patch \
		${NONEXISTENT}:${PORTSDIR}/multimedia/mediainfo:build
LIB_DEPENDS=	tar.0:${PORTSDIR}/devel/libtar

BUILD_WRKSRC=	${WRKSRC}/src

PROJECTHOST=	lib7zip
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qt3support xml \
		linguist_build moc_build qmake_build uic_build
MAKE_JOBS_SAFE=	yes

QMAKEFLAGS+=	INCLUDEPATH+="${L7Z_WRKSRC}/Lib7Zip" \
		INCLUDEPATH+="${MIF_WRKSRC}/MediaInfoLib/Source" \
		INCLUDEPATH+="${MIF_WRKSRC}/ZenLib/Source" \
		LIBS+="${L7Z_WRKSRC}/Lib7Zip/lib7zip.a" \
		LIBS+="${MIF_WRKSRC}/MediaInfoLib/Project/GNU/Library/.libs/libmediainfo.a" \
		LIBS+="${MIF_WRKSRC}/ZenLib/Project/GNU/Library/.libs/libzen.a" \
		DEFINES+="MEDIAINFO_STATIC"
LRELEASE=	${QT_PREFIX}/bin/lrelease-qt4

# spoof tinderbox: build deps for multimedia/mediainfo
USE_AUTOTOOLS=	automake:env autoconf:env libtool:env

PORTDOCS=	Authors ChangeLog README TRANSLATORS_README
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/${PORTNAME}.png
.for lang in cz de el es fr hu id it pl pt sk sr
PLIST_FILES+=	%%DATADIR%%/translations/${PORTNAME}_${lang}.qm
.endfor
PLIST_DIRS=	%%DATADIR%%/translations %%DATADIR%%

L7Z_NAME=	lib7zip
L7Z_VERSION=	1.4.1
L7Z_DISTFILE=	${L7Z_NAME}-${L7Z_VERSION}.tar.gz
L7Z_WRKSRC=	${WRKDIR}/${L7Z_NAME}

.include <bsd.port.pre.mk>

P7Z_WRKSRC!=	cd ${PORTSDIR}/archivers/p7zip && ${MAKE} -V WRKSRC
MIF_WRKSRC!=	cd ${PORTSDIR}/multimedia/mediainfo && ${MAKE} -V WRKSRC

post-extract:
	@${GZCAT} ${DISTDIR}/${L7Z_DISTFILE} | (cd ${WRKDIR} && ${TAR} -xf -)
	@${LN} -sf ${L7Z_NAME}-${L7Z_VERSION} ${L7Z_WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e \
		'/lib7zip.a/s|^|#| ; \
		 /-lmediainfo/s|^|#| ; \
		 /libmediainfo/s|^|#| ; \
		 s|-ldl|| ; \
		 s|-std=c++0x || ; \
		 s|-g || ; \
		 s|-O2 ||' ${BUILD_WRKSRC}/${PORTNAME}.pro
	@${REINPLACE_CMD} -e \
		's|/dev/sr0|/dev/cd0|' ${BUILD_WRKSRC}/config.cpp
	@${REINPLACE_CMD} -e \
		's|-ldl||' ${L7Z_WRKSRC}/Test7Zip/Makefile.in

pre-configure:
	@cd ${L7Z_WRKSRC} && ./configure --disable-shared \
		CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		P7ZIP_SOURCE_DIR="${P7Z_WRKSRC}"

do-configure:
	@${LRELEASE} ${BUILD_WRKSRC}/${PORTNAME}.pro
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		${PORTNAME}.pro ${QMAKEFLAGS}

pre-build:
	@cd ${L7Z_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${DATADIR}
	@${MKDIR} ${DATADIR}/translations
	${INSTALL_DATA} ${BUILD_WRKSRC}/lang/*.qm ${DATADIR}/translations
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
