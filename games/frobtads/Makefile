PORTNAME=	frobtads
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0
CATEGORIES=	games lang

MAINTAINER=	wes.frazier@avoidbig.tech
COMMENT=	Development tools and text-mode interpreter for TADS adventure games
WWW=		https://github.com/realnc/frobtads

LICENSE=	TADS
LICENSE_NAME=	TADS FREEWARE SOURCE CODE LICENSE
LICENSE_FILE=	${WRKSRC}/tads3/LICENSE.TXT
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake:noninja localbase ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	realnc

CONFLICTS=	tads-2.*

DATADIR=	${PREFIX}/share/frobtads

.include <bsd.port.mk>
