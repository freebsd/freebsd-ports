# ex:ts=8
# Ports collection makefile for:	qtutils
# Date created:			Sep 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qtutils
PORTVERSION=	0.0.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.flyn.org/projects/qtutils/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QuickTime Utilities

LIB_DEPENDS=	vorbis.2:${PORTSDIR}/audio/libvorbis \
		quicktime.0:${PORTSDIR}/graphics/libquicktime

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	qtconv.1 qtsg.1 qtsplit.1

CPPFLAGS=	-I${LOCALBASE}/include `${GLIB_CONFIG} --cflags gthread`
LDFLAGS=	-L${LOCALBASE}/lib `${GLIB_CONFIG} --libs gthread`

.if !exists(/usr/include/getopt.h)
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
LDFLAGS+=	-lgnugetopt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-g -Wall|@CFLAGS@|g ; \
		 s|-lglib||g ; \
		 s|-lpthread||g ; \
		 s|-ldl||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
