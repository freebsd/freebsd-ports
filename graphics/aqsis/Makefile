# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	0.6.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A photorealistic rendering system

BUILD_DEPENDS=	${LOCALBASE}/lib/libargparse.a:${PORTSDIR}/devel/libargparse
LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff

USE_REINPLACE=	yes
USE_MESA=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
	LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib"
INSTALLS_SHLIB=	yes

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e "s|-ldl||g"

.include <bsd.port.mk>
