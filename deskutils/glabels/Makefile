# New ports collection makefile for:	glabels
# Date created:		29 September 2002
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	glabels
PORTVERSION=	1.91.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://snaught.com/glabels/source/

MAINTAINER=	martin.klaffenboeck@gmx.at
COMMENT=	A programm to create labels and business cards

LIB_DEPENDS=	gnomeprintui-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui20 \
		gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui

USE_GETOPT_LONG=yes
USE_GNOME=	gnomehack gnomeprefix gnomelibs
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CXXFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex -lcompat"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
