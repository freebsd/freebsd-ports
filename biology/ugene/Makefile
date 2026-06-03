PORTNAME=	ugene
PORTVERSION=	53.1
PORTREVISION=	1
CATEGORIES=	biology science

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Integrated bioinformatics toolkit
WWW=		https://ugene.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libhts.so:biology/htslib
RUN_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++14-lang desktop-file-utils gl \
		localbase:ldflags pkgconfig qt:5 shared-mime-info \
		shebangfix xorg
USE_GL=		gl glu
USE_QT=		buildtools:build linguisttools:build qmake:build \
		core gui network networkauth printsupport \
		svg testlib websockets widgets xml \
		imageformats:run
USE_XORG=	x11 xtst
USE_LDCONFIG=	${UGENE_LIBDIR}

USE_GITHUB=	yes
GH_ACCOUNT=	ugeneunipro

CXXFLAGS_i386=	-msse2
LDFLAGS+=	-pthread
SHEBANG_FILES=	etc/shared/ugene
PORTDATA=	*

UGENE_LIBDIR=	${PREFIX}/lib/ugene

.include <bsd.port.pre.mk>

.if empty(ARCH:Mamd64) && empty(ARCH:Mi386)
BUILD_DEPENDS+=	${LOCALBASE}/include/sse2neon.h:devel/sse2neon
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-bit version|& for ${OPSYS}/${ARCH}|' \
		${WRKSRC}/src/ugeneui/src/main_window/AboutDialogController.cpp
	${REINPLACE_CMD} 's,stdc++fs,,' \
		${WRKSRC}/src/libs_3rdparty/QSpec/CMakeLists.txt
	${REINPLACE_CMD} 's,/usr/local/share/ugene,${DATADIR},' \
		${WRKSRC}/src/ugenecl/src/Main.cpp
# breakpad is not aware of FreeBSD
	${REINPLACE_CMD} '/libs_3rdparty\/breakpad/d' \
		${WRKSRC}/src/corelibs/U2Private/CMakeLists.txt \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} 's,breakpad,,' \
		${WRKSRC}/src/ugeneui/CMakeLists.txt \
		${WRKSRC}/src/ugenecl/CMakeLists.txt \
		${WRKSRC}/src/corelibs/U2Private/CMakeLists.txt
# Do not alter binary names for debug build
	${REINPLACE_CMD} '/DEBUG_POSTFIX/d' \
		${WRKSRC}/src/plugins_checker/CMakeLists.txt \
		${WRKSRC}/src/ugenecl/CMakeLists.txt \
		${WRKSRC}/src/ugenem/CMakeLists.txt \
		${WRKSRC}/src/ugeneui/CMakeLists.txt \
		${WRKSRC}/CMakeLists.txt

do-install:
	${MKDIR} ${STAGEDIR}/${UGENE_LIBDIR}
	cd ${BUILD_WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}/${UGENE_LIBDIR}/
.for prog in ugene ugenecl ugenem ugeneui
	${RLN} ${STAGEDIR}${UGENE_LIBDIR}/${prog} ${STAGEDIR}/${PREFIX}/bin/${prog}
.endfor
	${MKDIR} ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etc/shared/ugene.desktop ${STAGEDIR}/${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/shared/ugene.png ${STAGEDIR}/${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/etc/shared/application-x-ugene-ext.png ${STAGEDIR}/${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/etc/shared/ugene.1.gz ${STAGEDIR}/${PREFIX}/share/man/man1/
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/etc/shared/application-x-ugene.xml ${STAGEDIR}/${PREFIX}/share/mime/packages/

.include <bsd.port.post.mk>
