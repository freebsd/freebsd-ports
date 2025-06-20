PORTNAME=	VVVVVV
DISTVERSION=	2.4.3
CATEGORIES=	games
.if ${FLAVOR:U} == makeandplay
# The data file may only be distributed if the MAKEANDPLAY define is set.
# See https://github.com/TerryCavanagh/VVVVVV/blob/master/License%20exceptions.md
MASTER_SITES=	https://thelettervsixtim.es/makeandplay/data.zip?dummy=/:datafile
DISTFILES=	VVVVVV-data-${DISTVERSION}.zip:datafile
EXTRACT_ONLY=	${_DISTFILES:NVVVVVV-data-${DISTVERSION}.zip}
.endif

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	2D Platformer game
WWW=		https://thelettervsixtim.es/

LICENSE=	VVVVVV APACHE20 BSD3CLAUSE ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_VVVVVV=	VVVVVV Source Code License v1.0
LICENSE_FILE_VVVVVV=	${WRKSRC}/../LICENSE.md
LICENSE_FILE_APACHE20=	${WRKSRC}/../third_party/SheenBidi/LICENSE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/../third_party/c-hashmap/LICENSE
# physfs is ZLIB, too
LICENSE_FILE_ZLIB=	${WRKSRC}/../third_party/lodepng/LICENSE
LICENSE_PERMS_VVVVVV=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

.if defined(NO_LICENSES_INSTALL)
IGNORE=		license requires that the license be shipped
.endif

BUILD_DEPENDS=	${LOCALBASE}/include/stb/stb_vorbis.c:devel/stb
LIB_DEPENDS=	libFAudio.so:audio/faudio@sdl2 \
		libtinyxml2.so:textproc/tinyxml2 \
		libphysfs.so:devel/physfs

FLAVORS=	commercial makeandplay
FLAVOR?=	${FLAVORS:[1]}
makeandplay_PKGNAMESUFFIX=	-makeandplay

USES=		sdl cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	TerryCavanagh
# physfs is unbundled, but the code still needs extras/physfsrwops.c, which is not
# compiled into libphysfs.so
GH_TUPLE=	lvandeve:lodepng:18964554bc769255401942e0e6dfd09f2fab2093:lodepng/../third_party/lodepng \
		Tehreer:SheenBidi:v2.9.0:SheenBidi/../third_party/SheenBidi \
		Mashpoe:c-hashmap:dedf70e0a769bc52a17a36da840d96770fc26d12:chashmap/../third_party/c-hashmap \
		icculus:physfs:bfa7997c671957eb0a340ff1cf3c634e6269904a:physfs/../third_party/physfs
USE_SDL=	sdl2

CFLAGS+=	-DDATADIR='\"${DATADIR}\"'
CMAKE_OFF=	BUNDLE_DEPENDENCIES GIT_FOUND
.if ${FLAVOR:U} == makeandplay
CMAKE_ON=	MAKEANDPLAY
.endif

WRKSRC_SUBDIR=	desktop_version
commercial_PLIST_FILES=	bin/VVVVVV
makeandplay_PLIST_FILES=	${DATADIR_REL}/data.zip \
				bin/VVVVVV-makeandplay
PLIST_FILES=	${${FLAVOR}_PLIST_FILES}

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/VVVVVV ${STAGEDIR}${PREFIX}/bin/VVVVVV${PKGNAMESUFFIX}
.if ${FLAVOR:U} == makeandplay
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/VVVVVV-data-${DISTVERSION}.zip ${STAGEDIR}${DATADIR}/data.zip
.endif
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "fonts lang" ${STAGEDIR}${DATADIR}/)

.include <bsd.port.mk>
