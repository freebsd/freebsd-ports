# Created by: nbm
# $FreeBSD$

PORTNAME=	criticalmass
PORTVERSION=	1.5.0
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Critical%20Mass/${PORTVERSION}-RC
DISTNAME=	CriticalMass-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL/OpenGL space shoot'em up game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtinyxml.so:textproc/tinyxml

USES=		tar:bzip2
USE_XORG=	x11
USE_GL=		gl
USE_SDL=	image mixer sdl
USE_CXXSTD=	gnu++98
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimize

# libtinyxml is linked using cc and thus is not linked with libc++
# which leads to most configure checks failing here; apply a band-aid
# and use CXX for everything
CC=		${CXX}

CONFLICTS=	shaaft-[0-9]*

PLIST_FILES=	bin/Packer \
		bin/critter \
		man/man6/critter.6.gz \
		share/Critical_Mass/resource.dat
PLIST_DIRS=	share/Critical_Mass

DESKTOP_ENTRIES="CriticallMass" "" "" "critter" "" ""

.include <bsd.port.mk>
