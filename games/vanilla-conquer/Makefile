PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	g20220804
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	f1a415ebe08c01ccf317.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Portable version of the original C&C engine

LICENSE=	GPLv3+

USE_GITHUB=	yes
GH_ACCOUNT=	TheAssemblyArmada
GH_PROJECT=	Vanilla-Conquer
GH_TAGNAME=	8fb1a09

USES=		cmake openal sdl
USE_SDL=	sdl2
CMAKE_ON=	BUILD_TOOLS
CONFIGURE_ENV=	GIT_HEAD_SHA1=8fb1a09c91bd64fe599d4f15bd7fe3cdffd00707 \
		GIT_HEAD_SHORT_SHA1=${GH_TAGNAME} \
		GIT_COMMIT_DATE_ISO8601=${_GET_DATE:sh} \
		GIT_AUTHOR_NAME=\<irrelevant\> GIT_TAG=latest \
		GIT_COMMIT_TSTAMP=${_GET_TSTAMP:sh} GIT_IS_DIRTY=true \
		GIT_RETRIEVED_STATE=true GIT_REV_LIST_COUNT=802
LDFLAGS_i386=	-fuse-ld=bfd

PLIST_FILES=	bin/vanillamix bin/vanillara bin/vanillatd \
		share/icons/hicolor/scalable/apps/vanillara_icon.svg \
		share/icons/hicolor/scalable/apps/vanillatd_icon.svg

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BUILD_DEPENDS+=	ld.bfd:devel/binutils
.endif

post-patch:
	@${REINPLACE_CMD} -e '/Obfuscate/s,long,unsigned,' \
		${WRKSRC}/tiberiandawn/function.h \
		${WRKSRC}/tiberiandawn/init.cpp

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/vanilla* \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/resources/*.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.post.mk>

_GET_DATE=	TZ= ${STAT} -f %Sm -t %FT%TZ ${WRKSRC}/.gitignore
_GET_TSTAMP=	TZ= ${STAT} -f %m ${WRKSRC}/.gitignore
