# New ports collection makefile for:    netpanzer
# Date created:				29 May 2004
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	netpanzer
PORTVERSION=	0.8.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_BERLIOS}/${PORTNAME}/

MAINTAINER=	mad@madpilot.net
COMMENT=	Real time, isometric view, tank multiplayer strategy game

LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs
BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
RUN_DEPENDS=	${LOCALBASE}/share/netpanzer/wads/netp.act:${PORTSDIR}/games/netpanzer-data

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libphysfs=${LOCALBASE} --without-wx-config
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"

USE_BZIP2=	yes
USE_SDL=	sdl net mixer image ttf
USE_GNOME=	libxml2
USE_GCC=	3.4

post-patch:
	@for ff in `${FIND} ${WRKDIR} -type f -name '*.[ch]pp' -exec ${GREP} -q stdint.h {} \; -print`; do \
		${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' $${ff}; \
	done
	@${REINPLACE_CMD} -e "s|##DOCSDIR##|${DOCSDIR}|" ${WRKSRC}/Jamconfig.in

.if defined(NOPORTDOCS)
post-configure:
	${REINPLACE_CMD} -e '/InstallDoc/d' ${WRKSRC}/Jamfile
.endif

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} jam)

do-install:
	@(cd ${INSTALL_WRKSRC} && jam ${INSTALL_TARGET})

.include <bsd.port.mk>
