# $FreeBSD$

PORTNAME=	lumina-pdf
PORTVERSION=	1.4.2
PORTREVISION=	201803061453
CATEGORIES=	deskutils

MAINTAINER=	jt@ixsystems.com
COMMENT=	PDF viewer from the Lumina Desktop

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

CONFLICTS_INSTALL=	lumina-1.2.*

OPTIONS_DEFINE=	I18N
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	I18N
I18N_DESC= Install localization files

.include <bsd.port.options.mk>

MAKE_JOBS_UNSAFE=yes

USES=           qmake
USE_QT5=	core gui widgets network svg multimedia \
		buildtools_build x11extras concurrent printsupport
USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	lumina
GH_TAGNAME=	9b8419b162767929191b20d848b1b9e3d65cab69
WRKSRC_SUBDIR=	src-qt5/desktop-utils/${PORTNAME}

.if${PORT_OPTIONS:MI18N}
USE_QT5+= linguist_build
QMAKE_ARGS+=CONFIG+=WITH_I18N
.endif

.include <bsd.port.mk>
