PORTNAME=	lumina-calculator
DISTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Scientific calculator from the Lumina Desktop
WWW=		https://github.com/lumina-desktop/lumina

LICENSE=	BSD3CLAUSE

USES=		compiler:c++11-lang gl qmake qt:5 xorg
USE_GL=		gl
USE_XORG=	x11
USE_QT=		buildtools:build core gui svg widgets
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_TAGNAME=	159fc375

QMAKE_ARGS=	L_MANDIR=${PREFIX}/share/man

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USE=	qt=linguist:build
NLS_QMAKE_ON=	CONFIG+=WITH_I18N

CONFLICTS_INSTALL=	lumina-1.2.*

WRKSRC_SUBDIR=	src-qt5

.include <bsd.port.mk>
