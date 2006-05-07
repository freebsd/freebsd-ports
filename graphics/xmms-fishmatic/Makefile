# New ports collection makefile for:	xmms-fishmatic
# Date created:				20 Jan 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-fishmatic
PORTVERSION=	0.0.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://stukach.com/hosted/
DISTNAME=	fishmatic

MAINTAINER=	dyeske@yahoo.com
COMMENT=	An XMMS non-static OpenGL stereogram visualization plugin

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

PLIST_FILES=	lib/xmms/Visualization/libfishmatic.so
USE_X_PREFIX=   yes
USE_GNOME=      gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=  yes

CONFIGURE_ENV=	LIBS="-lGL -lXext ${LIBS}"
CFLAGS+=	-I${X11BASE}/include -L${X11BASE}/lib

post-patch:
	@${RM} -f ${WRKSRC}/config.cache
	@${REINPLACE_CMD} -e 's|-O2||; \
		s|-lpthreads|${PTHREAD_LIBS:S/"//g}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
