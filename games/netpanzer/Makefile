# New ports collection makefile for:    netpanzer
# Date created:				29 May 2004
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	netpanzer
PORTVERSION=	0.1.5
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/netpanzer/

MAINTAINER=	mad@madpilot.net
COMMENT=	Real time, isometric view, tank strategy game(multiplayer)

LIB_DEPENDS=	physfs-1.0.0:${PORTSDIR}/devel/physfs
BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
RUN_DEPENDS=	${X11BASE}/share/netpanzer/wads/netp.act:${PORTSDIR}/games/netpanzerdata

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libphysfs=${LOCALBASE} --without-wx-config
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_SDL=	sdl net mixer image ttf
USE_GNOME=	libxml2
USE_REINPLACE=	yes
USE_GCC=	3.4

post-patch:
	@for ff in `${FIND} ${WRKDIR} -type f -name '*.[ch]pp' -exec ${GREP} -q stdint.h {} \; -print`; do \
		${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' $${ff}; \
	done

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} jam)

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} jam ${INSTALL_TARGET})

.include <bsd.port.mk>
