# $FreeBSD$

PORTNAME=	klatexformula
PORTVERSION=	3.2.7
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Convert LaTeX formula to image

USES=		cmake:outsource shared-mime-info
USE_QT4=	gui xml dbus designer_build linguist_build \
		qmake_build moc_build rcc_build uic_build
USE_TEX=	latex dvipsk
HAS_CONFIGURE=	yes
USE_GHOSTSCRIPT=	yes
CMAKE_ARGS=	-DQT_QMAKE_EXECUTABLE_FINDQT=${QMAKE} \
		-DKLF_BUILD_KTEXTEDITORPLUGIN=off \
		-DKLF_INSTALL_POST_UPDATEMIMEDATABASE=off
CXXFLAGS=	-I${LOCALBASE}/include

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
