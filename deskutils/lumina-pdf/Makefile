PORTNAME=	lumina-pdf
DISTVERSION=	1.6.2
PORTREVISION=	19
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	PDF viewer from the Lumina Desktop
WWW=		https://github.com/lumina-desktop/lumina

LICENSE=	BSD3CLAUSE

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5
USE_QT=		buildtools:build concurrent core gui \
		multimedia network printsupport \
		svg widgets x11extras
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_TAGNAME=	0dd7489a

OPTIONS_DEFINE=	NLS

OPTIONS_SINGLE=	RENDERER
OPTIONS_SINGLE_RENDERER=	POPPLER MUPDF

OPTIONS_DEFAULT=	POPPLER
OPTIONS_SUB=		yes

POPPLER_DESC=		Use Poppler-qt5 backend renderer
MUPDF_DESC=		Use MuPDF backend renderer (broken)

MUPDF_BROKEN=		Does not build with MuPDF backend
MUPDF_QMAKE_ON=		USE_MUPDF=true
MUPDF_LIB_DEPENDS=	libmupdf.so:graphics/mupdf

NLS_QMAKE_ON=		CONFIG+=WITH_I18N
NLS_USE=		qt=linguist:build

POPPLER_QMAKE_ON=	USE_POPPLER=true
POPPLER_LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

WRKSRC_SUBDIR=	src-qt5

CONFLICTS_INSTALL=	lumina-1.2.*

.include <bsd.port.mk>
