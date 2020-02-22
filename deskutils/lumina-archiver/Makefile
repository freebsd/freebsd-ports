# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina-archiver
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	deskutils

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Archive manager from the Lumina Desktop

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../../LICENSE

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5
USE_QT=		buildtools_build concurrent core gui \
		multimedia network svg widgets x11extras
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_PROJECT=	lumina

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USE=	qt=linguist_build
NLS_QMAKE_ON=	CONFIG+=WITH_I18N

CONFLICTS_INSTALL=	lumina-1.2.*

WRKSRC_SUBDIR=	src-qt5/desktop-utils/${PORTNAME}

.include <bsd.port.mk>
