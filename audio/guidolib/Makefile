# $FreeBSD$

PORTNAME=	guidolib
DISTVERSIONPREFIX=	v
DISTVERSION=	168
CATEGORIES=	audio graphics print

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for graphic rendering of music scores

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libmidisharelight.so:audio/midisharelight

USES=		compiler:c++11-lang gl gmake gnome localbase:ldflags pkgconfig qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
USE_QT=		core gui widgets printsupport xml buildtools_build qmake_build
USE_GL=		gl
USE_GNOME=	cairo
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${WRKSRC}/build

MAKE_ARGS=	LINUXMIDI=no

LDFLAGS+=	-lmidisharelight

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

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/libGUIDOEngine.so.*
	${RM} -r ${STAGEDIR}${DATADIR}/python

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/package/doc/*.pdf ${STAGEDIR}${DOCSDIR}
	${CP} -r ${WRKSRC}/package/doc/html ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/gmn-examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
