PORTNAME=	lumina-fm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Insight file manager from the Lumina Desktop
WWW=		https://github.com/lumina-desktop/lumina/tree/master/src-qt5/desktop-utils/lumina-fm

LICENSE=	BSD3CLAUSE

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5
USE_QT=		buildtools:build concurrent core gui imageformats \
		multimedia network svg widgets x11extras
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_PROJECT=	lumina

QMAKE_ARGS=	L_MANDIR=${PREFIX}/share/man

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USE=	QT=linguist:build
NLS_QMAKE_ON=	CONFIG+=WITH_I18N

CONFLICTS_INSTALL=	lumina-1.2.*

WRKSRC_SUBDIR=	src-qt5/desktop-utils/${PORTNAME}

.include <bsd.port.mk>
