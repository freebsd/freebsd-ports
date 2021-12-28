# Created by: Emmanuel Vadot <manu@FreeBSD.org>

PORTNAME=	VVVVVV
DISTVERSION=	2.3.6
CATEGORIES=	games
.if ${FLAVOR:U} == makeandplay
# The data file may only be distributed if the MAKEANDPLAY define is set.
# See https://github.com/TerryCavanagh/VVVVVV/blob/master/License%20exceptions.md
MASTER_SITES=	https://thelettervsixtim.es/makeandplay/data.zip?dummy=/:datafile
DISTFILES=	VVVVVV-data-${DISTVERSION}.zip:datafile
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${DISTVERSION}_GH0.tar.gz
.endif

MAINTAINER=	manu@FreeBSD.org
COMMENT=	2D Platformer game

LICENSE=	VVVVVV BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_NAME_VVVVVV=	VVVVVV Source Code License v1.0
LICENSE_FILE_VVVVVV=	${WRKSRC}/../LICENSE.md
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/../third_party/lodepng/LICENSE.txt
LICENSE_PERMS_VVVVVV=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

.if defined(NO_LICENSES_INSTALL)
IGNORE=		license requires that the license be shipped
.endif

BUILD_DEPENDS=	utf8cpp>0:devel/utf8cpp
LIB_DEPENDS=	libtinyxml2.so:textproc/tinyxml2 \
		libphysfs.so:devel/physfs

FLAVORS=	commercial makeandplay
makeandplay_PKGNAMESUFFIX=	-makeandplay

USES=		sdl cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	TerryCavanagh
GH_PROJECT=	${PORTNAME}
USE_SDL=	sdl2 mixer2

CFLAGS+=	-DASSETSPATH='\"${DATADIR}/data.zip\"'
CMAKE_OFF=	BUNDLE_DEPENDENCIES
.if ${FLAVOR:U} == makeandplay
CMAKE_ON=	MAKEANDPLAY
.endif

WRKSRC_SUBDIR=	desktop_version
PLIST_FILES=	bin/VVVVVV${PKGNAMESUFFIX} \
		${"${FLAVOR}"=="makeandplay:?${DATADIR_REL}/data.zip:}
SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/VVVVVV ${STAGEDIR}${PREFIX}/bin/VVVVVV${PKGNAMESUFFIX}
.if ${FLAVOR:U} == makeandplay
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/VVVVVV-data-${DISTVERSION}.zip ${STAGEDIR}${DATADIR}/data.zip
.endif

.include <bsd.port.mk>
