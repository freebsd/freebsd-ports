PORTNAME=	feathernotes
PORTVERSION=	1.3.0
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/tsujan/FeatherNotes/releases/download/V${PORTVERSION}/
DISTNAME=	FeatherNotes-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight Qt-based notes manager
WWW=		https://github.com/tsujan/FeatherNotes

LICENSE=	GPLv3+

USES=		cmake desktop-file-utils qt:6 shared-mime-info tar:xz xorg
USE_QT=		base svg translations
USE_XORG=	ice sm x11 xext

OPTIONS_DEFINE=	HUNSPELL
OPTIONS_DEFAULT=	HUNSPELL

HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
HUNSPELL_USES=		pkgconfig
HUNSPELL_CMAKE_OFF=	-DWITH_HUNSPELL:BOOL=OFF

.include <bsd.port.mk>
