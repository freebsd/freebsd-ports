# $FreeBSD$

PORTNAME=	cmake
PORTVERSION=	2.8.12
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v2.8/
PKGNAMESUFFIX=	-gui

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 GUI for cmake

USE_QT4=	gui qmake_build moc_build uic_build rcc_build
USES=		cmake:run
CMAKE_ARGS=	-DBUILD_QtDialog:bool=on \
		-DCMAKE_DATA_DIR:STRING="/${DATADIR_REL}" \
		-DCMAKE_DOC_DIR:STRING="/${DOCSDIR_REL}"

BUILD_WRKSRC=	${WRKSRC}/Source/QtDialog
INSTALL_WRKSRC=	${BUILD_WRKSRC}

DISTINFO_FILE=  ${.CURDIR}/../cmake/distinfo

post-patch:
	@(${FIND} ${WRKSRC}/Modules -name "*.cmake" -print0; \
		${FIND} ${WRKSRC}/Tests -name "CMakeLists.txt" -print0 ) | \
		${XARGS} -0 -n 100 ${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g; \
			s,/usr/X11R6,${LOCALBASE},g'

pre-install:
	${LN} -sf ${CMAKE_BIN} ${WRKSRC}/bin
	${WRKSRC}/bin/cmake-gui --help-man > ${WRKSRC}/cmake-gui.1

post-install:
	${MKDIR} ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cmake-gui.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
