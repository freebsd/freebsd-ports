# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=		featherpad
PORTVERSION=		0.9.1
PORTREVISION=	1
DISTVERSIONPREFIX=	V
CATEGORIES=		editors

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Lightweight Qt5 plain-text editor

LICENSE=	GPLv3

USES=		compiler:c++11-lang desktop-file-utils pkgconfig qmake:outsource qt:5 gl

USE_GITHUB=	yes
GH_ACCOUNT=	tsujan
GH_PROJECT=	FeatherPad

USE_QT=		buildtools_build core gui printsupport network \
		svg widgets x11extras linguisttools
USE_XORG=	x11
USE_GL=		gl

.include <bsd.port.mk>
