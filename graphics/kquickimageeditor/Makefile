# $FreeBSD$

PORTNAME=	kquickimageeditor
DISTVERSION=	0.1.2
CATEGORIES=	graphics
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION:R}

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Simple image editor for QtQuick applications

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

USES=		cmake compiler:c++17-lang gl kde:5 pkgconfig qt:5 tar:xz
USE_GL=		gl
USE_QT=		core declarative gui network quickcontrols2 \
		buildtools_build linguist_build qmake_build
USE_KDE=	ecm_build

.include <bsd.port.mk>
