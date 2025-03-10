PORTNAME=	kquickimageeditor
DISTVERSION=	0.5.1
CATEGORIES=	graphics
MASTER_SITES=	KDE/stable/${PORTNAME}/
PKGNAMESUFFIX=	-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image editor for QtQuick applications
WWW=		https://invent.kde.org/libraries/kquickimageeditor

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

USES=		cmake compiler:c++17-lang gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
