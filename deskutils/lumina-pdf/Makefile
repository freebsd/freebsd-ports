# $FreeBSD$

PORTNAME=	lumina-pdf
DISTVERSION=	1.6.0
PORTREVISION=	13
CATEGORIES=	deskutils

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	PDF viewer from the Lumina Desktop

LICENSE=	BSD3CLAUSE

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5
USE_QT=		buildtools_build concurrent core gui \
		multimedia network printsupport \
		svg widgets x11extras
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_PROJECT=	lumina-pdf
GH_TAGNAME=	645ed591ef91c3607d3ab87dd86f7acfd08b05c9

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
NLS_USE=		qt=linguist_build

POPPLER_QMAKE_ON=	USE_POPPLER=true
POPPLER_LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

WRKSRC_SUBDIR=	src-qt5

CONFLICTS_INSTALL=	lumina-1.2.*

.include <bsd.port.mk>
