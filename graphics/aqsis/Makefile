# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	0.9.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A photorealistic rendering system

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_GCC=	3.3
USE_GNOME=	gnometarget lthack
USE_BISON=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		aqsis.1

CFLAGS+=	-O0
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -fPIC
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|PLUGIN_FLAGS=|#PLUGIN_FLAGS=|g' ${WRKSRC}/configure
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
