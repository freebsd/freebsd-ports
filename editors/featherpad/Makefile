# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=		featherpad
PORTVERSION=		0.14.2
DISTVERSIONPREFIX=	V
CATEGORIES=		editors

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Lightweight Qt5 plain-text editor

LICENSE=	GPLv3

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		compiler:c++11-lang desktop-file-utils pkgconfig cmake qt:5 gl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	tsujan
GH_PROJECT=	FeatherPad

USE_QT=		buildtools_build qmake_build core gui printsupport network \
		svg widgets x11extras linguisttools
USE_XORG=	x11 sm ice xext
USE_GL=		gl

.include <bsd.port.mk>
