# $FreeBSD$

PORTNAME=	klatexformula
PORTVERSION=	3.2.11
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Convert LaTeX formula to image

BUILD_DEPENDS=	help2man:misc/help2man

USES=		cmake:outsource desktop-file-utils ghostscript:run \
		shared-mime-info
USE_QT4=	gui xml dbus designer_build linguisttools_build \
		qmake_build moc_build rcc_build uic_build
USE_TEX=	latex dvipsk
CMAKE_ARGS=	-DQT_QMAKE_EXECUTABLE_FINDQT=${QMAKE} \
		-DKLF_BUILD_KTEXTEDITORPLUGIN=off \
		-DKLF_INSTALL_POST_UPDATEMIMEDATABASE=off \
		-DKLF_INSTALL_SHARE_MAN1_DIR=man/man1
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} '/link_libraries(klatexformula /s/)/ -lX11)/' \
		${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
