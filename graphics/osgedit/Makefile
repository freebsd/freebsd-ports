# ex:ts=8
# Ports collection makefile for:	osgedit
# Date created:			Jan 23, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	osgedit
PORTVERSION=	0.5.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open editor for an open scenegraph

BUILD_DEPENDS=	${X11BASE}/lib/libosg.so:${PORTSDIR}/graphics/osg
LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext
RUN_DEPENDS=	${X11BASE}/lib/libosg.so:${PORTSDIR}/graphics/osg

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-gtkglext

CFLAGS+=	-O0

post-patch:
.for file in src/gui/interface.cc
	@cd ${WRKSRC} && ${MV} ${file} ${file}.pre_conv \
		&& ${TR} -d '\015' < ${file}.pre_conv > ${file} || ${TRUE}
.endfor

.include <bsd.port.mk>
