# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	leocad
DISTVERSIONPREFIX=	v
DISTVERSION=	18.02.20190517
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CAD program for creating virtual LEGO models

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

RUN_DEPENDS=	ldraw>0:cad/ldraw

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5 shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	leozide
GH_TAGNAME=	f392e3c
USE_QT=		core gui concurrent network opengl printsupport widgets xml buildtools_build linguisttools_build
USE_GL=		gl

QMAKE_ARGS=	INSTALL_PREFIX=${PREFIX} MAN_DIR=${PREFIX}/man/man1 LDRAW_LIBRARY_PATH=${PREFIX}/share/ldraw

PLIST_FILES=	bin/leocad \
		share/applications/leocad.desktop \
		share/icons/hicolor/scalable/mimetypes/application-vnd.leocad.svg \
		man/man1/leocad.1.gz \
		share/metainfo/leocad.appdata.xml \
		share/mime/packages/leocad.xml \
		share/pixmaps/leocad.png

.include <bsd.port.mk>
