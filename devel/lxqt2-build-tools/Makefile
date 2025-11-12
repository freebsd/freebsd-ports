PORTNAME=	lxqt2-build-tools
PORTVERSION=	2.3.0
CATEGORIES=	devel
MASTER_SITES=   LXQT/${PORTNAME:S/2//}

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Helpers CMake modules for LXQt2
WWW=		https://github.com/lxqt/lxqt-build-tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-3-Clause

USES=		cmake lxqt:2 pkgconfig qt:6 tar:xz gnome
USE_QT=		base:run tools:build
USE_GNOME=	glib20

CMAKE_ARGS+=	-DLXQT_ETC_XDG_DIR=${PREFIX}/etc/xdg

.include <bsd.port.mk>
