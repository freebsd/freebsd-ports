PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	V
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight Qt-based notes manager
WWW=		https://github.com/tsujan/FeatherNotes

LICENSE=	GPLv3+

USES=		cmake desktop-file-utils qt:5 shared-mime-info xorg
USE_QT=		buildtools:build linguisttools:build qmake:build dbus \
		core gui network printsupport svg widgets x11extras xml
USE_XORG=	ice sm x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	tsujan
GH_PROJECT=	FeatherNotes

OPTIONS_DEFINE=	HUNSPELL
OPTIONS_DEFAULT=	HUNSPELL

HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
HUNSPELL_USES=		pkgconfig
HUNSPELL_CMAKE_OFF=	-DWITH_HUNSPELL:BOOL=OFF

.include <bsd.port.mk>
