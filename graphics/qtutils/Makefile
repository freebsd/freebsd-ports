# ex:ts=8
# Ports collection makefile for:	qtutils
# Date created:			Sep 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qtutils
PORTVERSION=	0.0.6
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.flyn.org/projects/qtutils/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QuickTime Utilities

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		quicktime.0:${PORTSDIR}/multimedia/libquicktime

USE_GNOME=	glib12
USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	qtconv.1 qtsg.1 qtsplit.1

CPPFLAGS=	-I${LOCALBASE}/include `${GLIB_CONFIG} --cflags gthread`
LDFLAGS=	-L${LOCALBASE}/lib `${GLIB_CONFIG} --libs gthread`

post-patch:
	@${REINPLACE_CMD} -e 's|-g -Wall|@CFLAGS@|g ; \
		 s|-lglib||g ; \
		 s|-lpthread||g ; \
		 s|-ldl||g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|quicktime/quicktime.h|lqt/quicktime.h|' ${WRKSRC}/src/*.c

.include <bsd.port.mk>
