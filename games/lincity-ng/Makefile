# New ports collection makefile for:	lincity-ng
# Date created:		25 June 2005
# Whom:			Andrej Zverev
#
# $FreeBSD$
#

PORTNAME=	lincity-ng
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/lincity-ng/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	az@inec.ru
COMMENT=	Improved rich city simulation game for X

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
LIB_DEPENDS=	physfs-1.0.1:${PORTSDIR}/devel/physfs

USE_BZIP2=	yes
USE_GCC=	3.2+
USE_SDL=	sdl mixer image ttf gfx
USE_GNOME=	libxml2
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libphysfs=${PREFIX}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
pre-configure::
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' \
	${WRKSRC}/src/gui/Filter.cpp ${WRKSRC}/src/gui/Gradient.hpp \
	${WRKSRC}/src/gui/Color.hpp
.endif

.if ${OSVERSION} < 504000
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-src-gui-Gradient.cpp
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-src-gui-PainterSDL-PainterSDL.cpp
.endif

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} jam)

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} jam ${INSTALL_TARGET})

.include <bsd.port.post.mk>
