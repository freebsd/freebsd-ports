PORTNAME=	trackballs
PORTVERSION=	1.3.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	SDL-based Marble Madness clone
WWW=		https://trackballs.github.io/

LICENSE=	GPLv2+ ETHYMONICS
LICENSE_COMB=	multi

USES=		cmake desktop-file-utils gettext-runtime gl gnome \
		guile:2.2,conflicts pkgconfig sdl
USE_GL=		gl
USE_SDL=	image2 mixer2 sdl2 ttf2

LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_ETHYMONICS=	${WRKSRC}/share/music/README
LICENSE_NAME_ETHYMONICS=	Ethymonics Free Music License
LICENSE_PERMS_ETHYMONICS=	dist-mirror dist-sell pkg-mirror pkg-sell \
							auto-accept

USE_GITHUB=	yes

CMAKE_ARGS+=	-DTRACKBALLS_DOC_DIR=${DOCSDIR} \
		-DTRACKBALLS_MAN_DIR=${PREFIX}/share/man

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes
NLS_USES=	gettext-tools
NLS_CMAKE_ON=	-DDISABLE_NLS:BOOL=OFF
NLS_CMAKE_OFF=	-DDISABLE_NLS:BOOL=ON

.include <bsd.port.mk>
