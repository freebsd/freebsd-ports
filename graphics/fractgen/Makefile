PORTNAME=	fractgen
DISTVERSION=	3.0.11
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://www.nntb.no/~dreibh/fractalgenerator/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	Fractal Generator
WWW=		https://www.nntb.no/~dreibh/fractalgenerator/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++23-lang gl qt:6 tar:xz
USE_GL=		opengl
USE_QT=		base tools:build imageformats:run

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	CLI QT
OPTIONS_MULTI=		PLATFORM
OPTIONS_MULTI_PLATFORM=	CLI KDE QT
OPTIONS_SUB=		yes

CLI_DESC=	Build the command-line version
KDE_DESC=	Build the KDE version
QT_DESC=	Build the Qt version

CLI_CMAKE_BOOL=		WITH_CLI

EXAMPLES_CMAKE_BOOL=	WITH_EXAMPLES

KDE_USES=		desktop-file-utils kde:6 shared-mime-info
KDE_USE=		KDE=ecm:build,colorscheme,config,configwidgets \
			KDE=coreaddons,guiaddons,widgetsaddons,xmlgui
KDE_CMAKE_BOOL=		WITH_KDE

QT_USES=		desktop-file-utils shared-mime-info
QT_CMAKE_BOOL=		WITH_QT

.include <bsd.port.mk>
