# $FreeBSD$

PORTNAME=	klatexformula
PORTVERSION=	4.0.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert LaTeX formula to image

LICENSE=	GPLv2

BUILD_DEPENDS=	help2man:misc/help2man

USES=		cmake compiler:c++11-lang desktop-file-utils ghostscript:run \
		qt:5 shared-mime-info tar:bzip2 localbase
USE_QT=		core dbus gui sql svg widgets x11extras xml \
		buildtools_build designer_build linguisttools_build \
		qmake_build uitools_build
USE_TEX=	latex dvipsk
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DKLF_INSTALL_POST_UPDATEMIMEDATABASE=off \
		-DKLF_INSTALL_SHARE_MAN1_DIR=man/man1

post-patch:
	${REINPLACE_CMD} '/CMAKE_SYSTEM_NAME STREQUAL/s,Linux,FreeBSD,' \
		${WRKSRC}/src/klftools/CMakeLists.txt

.include <bsd.port.mk>
