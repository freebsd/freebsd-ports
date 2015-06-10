# $FreeBSD$

PORTNAME=	ppsspp
DISTVERSIONPREFIX=	v
DISTVERSION?=	1.0.1
PORTREVISION?=	3
CATEGORIES=	emulators

PATCH_SITES=	https://projects.archlinux.org/svntogit/community.git/plain/trunk/
PATCHFILES=	${PORTNAME}-ffmpeg.patch?id=f2b9251:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PSP emulator in C++ with dynarec JIT for x86, ARM, MIPS

LICENSE=	GPLv2 # or any later version

LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_GITHUB=	yes
GH_ACCOUNT=	hrydgard:DEFAULT,lang,native Kingcom:ext_armips
GH_PROJECT=	${PORTNAME}-lang:lang native:native armips:ext_armips
GH_TAGNAME?=	52c757e:lang 52ce9c1:native a0b878f:ext_armips

CONFLICTS_INSTALL?=	${PORTNAME}-devel-[0-9]*

USES=		compiler:c++11-lib pkgconfig
USE_GL=		glu
USE_SDL=	sdl2 # joystick
QMAKE_SOURCE_PATH=	${WRKSRC}/Qt/PPSSPPQt.pro
QMAKE_ARGS=	CONFIG+="system_ffmpeg" LREL_TOOL="${LRELEASE}"
NINJA_VERBOSE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFAULT=QT5
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	QT4 QT5 SDL

QT4_USES=	qmake:outsource
QT4_USE=	QT4=qmake_build,moc_build,rcc_build,uic_build,linguisttools_build,gui,opengl
QT5_USES=	qmake:outsource
QT5_USE=	QT5=qmake_build,buildtools_build,linguisttools_build,gui,opengl,widgets
SDL_USES=	cmake:outsource ninja
SDL_BUILD_DEPENDS=	png>=1.6:${PORTSDIR}/graphics/png
SDL_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
SDL_LDFLAGS=	-L${LOCALBASE}/lib # ffmpeg

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MQT*}
PORTDATA+=	assets ${PORTNAME}
.endif

post-extract:
# Convert USE_GITHUB groups to git-submodule(1) paths
.for group in ${GH_PROJECT:C/.*://}
	@${RMDIR} ${WRKSRC}/${group:S,_,/,g}
	@${MV} ${WRKSRC_${group}} ${WRKSRC}/${group:S,_,/,g}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/UI/NativeApp.cpp
	@${REINPLACE_CMD} -e '/find_package(Git)/d' \
		-e 's/"unknown"/"${GH_TAGNAME}"/' \
		-e 's/^\(VERSION =\).*/\1 ${GH_TAGNAME}/' \
		${WRKSRC}/git-version.cmake \
		${WRKSRC}/Qt/Settings.pri

do-install:
.if ! ${PORT_OPTIONS:MQT*}
# cmake doesn't pack assets into the app unlike qmake
# XXX Convert to ${PORTDATA:N${PORTNAME}} once fmake is EOL
	(cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDATA:Nppsspp}" ${STAGEDIR}${DATADIR})
# Install the app alongside assets to avoid warnings with GetExeDirectory()
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME:tu}* \
		${STAGEDIR}${DATADIR}/${PORTNAME}
	${LN} -sf ${DATADIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.else
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
.endif
	${INSTALL_DATA} ${WRKSRC}/debian/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_MAN} ${WRKSRC}/debian/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	(cd ${WRKSRC}/assets/unix-icons && ${COPYTREE_SHARE} \
		"hicolor" ${STAGEDIR}${PREFIX}/share/icons)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/assets/unix-icons/icon-512.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg

.include <bsd.port.mk>
