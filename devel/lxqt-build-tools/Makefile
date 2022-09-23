PORTNAME=	lxqt-build-tools
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	LXQT/${PORTNAME}

PATCH_SITES+=	https://github.com/lxqt/lxqt-build-tools/commit/
PATCHFILES+=	4991811d9212ec1176af6d1cbe88aa37efad4836.diff:-p1

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Helpers CMake modules for LXQt
WWW=		https://github.com/lxde/lxqt-build-tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-3-Clause

USES=		cmake lxqt pkgconfig qt:5 tar:xz gnome
USE_QT=		qmake:build buildtools:build core
USE_GNOME=	glib20

.include <bsd.port.mk>
