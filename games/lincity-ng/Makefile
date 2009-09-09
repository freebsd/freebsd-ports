# New ports collection makefile for:	lincity-ng
# Date created:		25 June 2005
# Whom:			Andrej Zverev
#
# $FreeBSD$
#

PORTNAME=	lincity-ng
PORTVERSION=	2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	az@FreeBSD.org
COMMENT=	Improved rich city simulation game for X

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs

USE_BZIP2=	yes
USE_SDL=	sdl mixer image ttf gfx
USE_GL=		yes
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libphysfs=${PREFIX} \
		--x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} jam)

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} jam ${INSTALL_TARGET})

.include <bsd.port.mk>
