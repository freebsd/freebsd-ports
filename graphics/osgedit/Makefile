# ex:ts=8
# Ports collection makefile for:	osgedit
# Date created:			Jan 23, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	osgedit
PORTVERSION=	0.4.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open editor for an open scenegraph

BUILD_DEPENDS=	${X11BASE}/lib/libosg.so:${PORTSDIR}/graphics/osg
LIB_DEPENDS=	gtkgl-2.0.1:${PORTSDIR}/x11-toolkits/gtkglarea2 \
		intl.5:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	${X11BASE}/lib/libosg.so:${PORTSDIR}/graphics/osg

USE_X_PREFIX=	yes
USE_GNOME=	libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

.include <bsd.port.mk>
