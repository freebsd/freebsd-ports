# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina-pdf
PORTVERSION=	1.3.3
PORTREVISION=	201709211618
CATEGORIES=	deskutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PDF viewer from the Lumina Desktop

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

CONFLICTS_INSTALL=	lumina-1.2.*

OPTIONS_DEFINE=	I18N
OPTIONS_DEFAULT=	I18N
I18N_DESC= Install localization files

.include <bsd.port.options.mk>

MAKE_JOBS_UNSAFE=yes

USE_QT5=	core gui widgets network svg multimedia \
		buildtools_build x11extras concurrent printsupport
USES=		qmake
USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	lumina
GH_TAGNAME=	a27815312eaac620881d67e8776c743595975b38
WRKSRC_SUBDIR=	src-qt5/desktop-utils/${PORTNAME}

.if${PORT_OPTIONS:MI18N}
USE_QT5+= linguist_build
QMAKE_ARGS+=CONFIG+=WITH_I18N
.endif

.include <bsd.port.mk>
