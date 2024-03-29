PORTNAME=	klatexformula
PORTVERSION=	4.0.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert LaTeX formula to image
WWW=		https://klatexformula.sourceforge.io

LICENSE=	GPLv2

BUILD_DEPENDS=	help2man:misc/help2man

USES=		cmake compiler:c++11-lang desktop-file-utils ghostscript:run \
		gl qt:5 shared-mime-info tar:bzip2 localbase tex
USE_GL=		gl
USE_QT=		core dbus gui sql svg widgets x11extras xml \
		buildtools:build designer:build linguisttools:build \
		qmake:build uitools:build
USE_TEX=	latex dvipsk
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DKLF_INSTALL_POST_UPDATEMIMEDATABASE=off

post-patch:
	${REINPLACE_CMD} '/CMAKE_SYSTEM_NAME STREQUAL/s,Linux,FreeBSD,' \
	    ${WRKSRC}/src/klftools/CMakeLists.txt

.include <bsd.port.mk>
