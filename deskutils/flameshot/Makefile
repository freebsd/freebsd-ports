PORTNAME=	flameshot
PORTVERSION=	14.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils wayland

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful yet simple to use screenshot software
WWW=		https://flameshot.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libkdsingleapplication-qt6.so:devel/kdsingleapplication

USES=		cmake compiler:c++11-lang desktop-file-utils gl qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	flameshot-org

USE_GITLAB=	nodefault
GL_ACCOUNT=	mattbas
GL_PROJECT=	Qt-Color-Widgets
GL_TAGNAME=	5d52e907e50dc88cf969b41cea44665ff6c475b1
GL_TUPLE:=	${GL_ACCOUNT}:${GL_PROJECT}:${GL_TAGNAME}:Qt_Color_Widgets/external/${GL_PROJECT}

USE_GL=		opengl
USE_QT=		base imageformats svg tools:build

CMAKE_ON=	DISABLE_UPDATE_CHECKER
CMAKE_OFF=	USE_BUNDLED_KDSINGLEAPPLICATION

post-patch:
	${REINPLACE_CMD} \
		-e 's,$${CMAKE_INSTALL_FULL_BINDIR},${LOCALBASE}/bin,1' \
		-e 's,^\(Exec=\)@LAUNCHER_EXECUTABLE@,\1${LOCALBASE}/bin/${PORTNAME},1' \
		${WRKSRC}/data/dbus/org.flameshot.Flameshot.service.in \
		${WRKSRC}/data/desktopEntry/package/org.flameshot.Flameshot.desktop

.include <bsd.port.mk>
