# $FreeBSD$

PORTNAME=	ppsspp
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	emulators
.ifndef GITHUB_GROUPS
MASTER_SITES=	https://codeload.github.com/${GH_ACCOUNT}/${PORTNAME}-lang/tar.gz/52c757e?dummy=/:lang \
		https://codeload.github.com/${GH_ACCOUNT}/native/tar.gz/52ce9c1?dummy=/:native \
		https://codeload.github.com/Kingcom/armips/tar.gz/a0b878f?dummy=/:ext_armips
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		${GH_ACCOUNT}-${PORTNAME}-lang-52c757e_GH${_GITHUB_REV}${EXTRACT_SUFX}:lang \
		${GH_ACCOUNT}-native-52ce9c1_GH${_GITHUB_REV}${EXTRACT_SUFX}:native \
		Kingcom-armips-a0b878f_GH${_GITHUB_REV}${EXTRACT_SUFX}:ext_armips
.endif

PATCH_SITES=	https://projects.archlinux.org/svntogit/community.git/plain/trunk/
PATCHFILES=	${PORTNAME}-ffmpeg.patch?id=f2b9251:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PSP emulator in C++ with dynarec JIT for x86, ARM, MIPS

LICENSE=	GPLv2 # or any later version

LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_GITHUB=	yes
.ifndef GITHUB_GROUPS
GH_ACCOUNT=	hrydgard
.else # XXX D2608 version, groups are converted to paths later
GH_ACCOUNT=	hrydgard:DEFAULT,lang,native Kingcom:ext_armips
GH_PROJECT=	${PORTNAME}-lang:lang native:native armips:ext_armips
GH_TAGNAME=	52c757e:lang 52ce9c1:native a0b878f:ext_armips
.endif

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
SDL_LDFLAGS=	-L${LOCALBASE}/lib # ffmpeg

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MQT*}
PORTDATA+=	assets ${PORTNAME}
.endif

post-extract:
.ifndef GITHUB_GROUPS
	@${RMDIR} ${WRKSRC}/lang
	@${MV} ${WRKDIR}/${PORTNAME}-lang-52c757e ${WRKSRC}/lang
	@${RMDIR} ${WRKSRC}/native
	@${MV} ${WRKDIR}/native-52ce9c1 ${WRKSRC}/native
	@${RMDIR} ${WRKSRC}/ext/armips
	@${MV} ${WRKDIR}/armips-a0b878f ${WRKSRC}/ext/armips
.else # XXX D2608 version
# Convert USE_GITHUB groups to git-submodule(1) paths
.for group in ${GH_PROJECT:C/.*://}
	@${RMDIR} ${WRKSRC}/${group:S,_,/,g}
	@${MV} ${WRKSRC_${group}} ${WRKSRC}/${group:S,_,/,g}
.endfor
.endif

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
	${INSTALL_DATA} ${WRKSRC}/debian/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	(cd ${WRKSRC}/assets/unix-icons && ${COPYTREE_SHARE} \
		"hicolor" ${STAGEDIR}${PREFIX}/share/icons)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/assets/unix-icons/icon-512.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg

.include <bsd.port.mk>
