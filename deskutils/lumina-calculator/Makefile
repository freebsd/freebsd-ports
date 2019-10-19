# $FreeBSD$

PORTNAME=	lumina-calculator
DISTVERSION=	1.5.0
CATEGORIES=	deskutils

MAINTAINER=	ken@project-trident.org
COMMENT=	Scientific calculator from the Lumina Desktop

LICENSE=	BSD3CLAUSE

USES=		compiler:c++11-lang gl qmake qt:5 xorg
USE_GL=		gl
USE_XORG=	x11
USE_QT=		buildtools_build core gui svg widgets
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_PROJECT=	lumina-calculator
GH_TAGNAME=	ccb792fc713aa7163fffd37fc20c83ffe9ca7523

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

CONFLICTS_INSTALL=	lumina-1.2.*

WRKSRC_SUBDIR=	src-qt5

NLS_USE=	qt=linguist_build
NLS_QMAKE_ON=	CONFIG+=WITH_I18N

.include <bsd.port.mk>
