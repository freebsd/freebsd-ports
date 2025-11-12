PORTNAME=		featherpad
PORTVERSION=		1.6.2
DISTVERSIONPREFIX=	V
CATEGORIES=		editors

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Lightweight Qt6 plain-text editor
WWW=		https://github.com/tsujan/FeatherPad

LICENSE=	GPLv3

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		compiler:c++17-lang desktop-file-utils pkgconfig cmake qt:6 gl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	tsujan
GH_PROJECT=	FeatherPad

USE_QT=		base:run tools:build svg
USE_XORG=	x11 sm ice xext
USE_GL=		gl

.include <bsd.port.mk>
