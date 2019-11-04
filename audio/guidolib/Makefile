# $FreeBSD$

PORTNAME=	guidolib
DISTVERSIONPREFIX=	v
DISTVERSION=	164-61
DISTVERSIONSUFFIX=	-gbcd5705d
PORTREVISION=	2
CATEGORIES=	audio graphics print

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	713a205a6e57.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for graphic rendering of music scores

LICENSE=	MPL20

BUILD_DEPENDS=	cmake:devel/cmake

USES=		compiler:c++11-lang gl gmake gnome pkgconfig qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
USE_QT=		core gui widgets printsupport xml buildtools_build qmake_build
USE_GL=		gl
USE_GNOME=	cairo
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/build

MAKE_ARGS=	LINUXMIDI=no

OPTIONS_DEFINE=	DOCS EXAMPLES
PORTDOCS=	*
PORTEXAMPLES=	*

post-extract:
	@${RM} -r ${WRKSRC}/src/midisharelight

post-patch:
	@${REINPLACE_CMD} -i '' -E ' \
		s|Linux|FreeBSD|; \
		s|-DMIDIEXPORT=yes|-DMIDIEXPORT=off|' \
		$$(${FIND} ${WRKSRC} -name Makefile) \
		$$(${FIND} ${WRKSRC}/environments/Qt -name Make.shared)
	@${REINPLACE_CMD} -i '' -e ' \
		s|PUBLIC_HEADER DESTINATION /usr/include/guido|PUBLIC_HEADER DESTINATION ${PREFIX}/include/guido|; \
		s|LIBDEST /usr/lib|LIBDEST ${PREFIX}/lib|; \
		s|LIBPATH "/usr/lib"|LIBPATH "${LOCALBASE}/lib"|; \
		s|-L/usr/local|-L${LOCALBASE}|' \
		${WRKSRC}/build/CMakeLists.txt
	@${REINPLACE_CMD} -i '' -e ' \
		s|-lGUIDOEngine|-L${WRKSRC}/build -lGUIDOEngine|' \
		${WRKSRC}/environments/Qt/apps/GUIDOEngine.shared \
		${WRKSRC}/environments/Qt/GuidoServer/GUIDOEngineLink.pri \
		${WRKSRC}/environments/Qt/libs/GuidoQt/GuidoQt.pro \
		${WRKSRC}/environments/Qt/apps/guido2image/Makefile \
		${WRKSRC}/src/tools/Makefile \
		${WRKSRC}/validate/Makefile
	@${REINPLACE_CMD} -i '' -e ' \
		s|!android:CONFIG += staticlib|#!android:CONFIG += staticlib|' \
		${WRKSRC}/environments/Qt/libs/GuidoQt/GuidoQt.pro
	@${REINPLACE_CMD} -i '' -e ' \
		s|/usr|$$(DESTDIR)$$(PREFIX)|; \
		s|libGuidoQt.a|libGuidoQt.*|' \
		${WRKSRC}/environments/Qt/libs/Makefile
	@${REINPLACE_CMD} -i '' -e ' \
		s|SET(CMAKE_INSTALL_PREFIX /usr )|SET(CMAKE_INSTALL_PREFIX ${PREFIX} )|' \
		${WRKSRC}/build/CMakeLists.txt \
		${WRKSRC}/src/tools/build/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/environments/Qt/apps/GuidoEditor/GuidoEditor \
		${WRKSRC}/environments/Qt/apps/GuidoSceneComposer/GuidoSceneComposer \
		${WRKSRC}/environments/Qt/apps/guido2image/guido2image \
		${WRKSRC}/src/tools/build/linux/midi2proll \
		${WRKSRC}/src/tools/build/linux/guido* \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/guido
	${INSTALL_DATA} \
		${WRKSRC}/src/engine/include/*.h \
		${WRKSRC}/platforms/linux/src/Cairo*.h \
		${WRKSRC}/environments/Qt/libs/GuidoQt/include/*.h \
		${STAGEDIR}${PREFIX}/include/guido
	${INSTALL_LIB} \
		${WRKSRC}/build/libGUIDOEngine.* \
		${WRKSRC}/environments/Qt/libs/libGuidoQt.* \
		${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fonts/guido
	${INSTALL_DATA} \
		${WRKSRC}/src/guido2.ttf \
		${STAGEDIR}${PREFIX}/share/fonts/guido
.for sz in 48 128
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${INSTALL_DATA} \
		${WRKSRC}/environments/Qt/package/debianbase/usr/share/icons/hicolor/${sz}x${sz}/apps/* \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
.endfor
	${INSTALL_DATA} \
		${WRKSRC}/environments/Qt/package/debianbase/usr/share/applications/*.desktop \
		${STAGEDIR}${DESKTOPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/package/doc/*.pdf ${STAGEDIR}${DOCSDIR}
	${CP} -r ${WRKSRC}/package/doc/html ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/gmn-examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
