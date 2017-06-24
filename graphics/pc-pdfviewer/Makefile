# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	pc-pdfviewer
PORTVERSION=	201706210943
CATEGORIES=	graphics

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	QT5 PDF Viewer

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libtrueos-ui.so:sysutils/trueos-libqt5 \
		libpoppler-qt5.so:${PORTSDIR}/graphics/poppler-qt5

WRKSRC_SUBDIR=	src-qt5
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

CONFLICTS=      pcbsd-utils-[0-9]*

MAKE_JOBS_UNSAFE=yes
ONLY_FOR_ARCHS= amd64
USE_LDCONFIG=   yes
USE_QT5=        core gui network svg linguist \
		buildtools x11extras widgets multimedia
USES=		qmake

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	pc-pdfviewer
GH_TAGNAME=	21feb8a9e5869417ceda55b77ed1fe90ca07522f

.include <bsd.port.mk>
