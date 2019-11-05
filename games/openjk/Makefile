# $FreeBSD$

PORTNAME=	openjk
PORTVERSION=	g20190428
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Community effort to maintain Jedi Academy + Jedi Outcast

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c++11-lang cmake gl jpeg localbase sdl xorg
USE_GL=		gl glu
USE_GITHUB=	yes
GH_ACCOUNT=	JACoders
GH_PROJECT=	OpenJK
GH_TAGNAME=	911c537
USE_SDL=	sdl2
USE_XORG=	x11

CXXFLAGS+=	-DNDEBUG
OPENJK_ARCH=	${ARCH:S/powerpc64/ppc64/:S/armv7/arm/}
PLIST_SUB=	ARCH="${OPENJK_ARCH}"
SUB_FILES=	jamp \
		jasp
SUB_LIST=	ARCH="${OPENJK_ARCH}"

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jamp ${WRKDIR}/jasp ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
