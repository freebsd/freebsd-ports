# ex:ts=8
# Ports collection makefile for:	osgedit
# Date created:			Jan 23, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	osgedit
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open editor for an open scenegraph

BUILD_DEPENDS=	${X11BASE}/lib/libosg.so:${PORTSDIR}/graphics/osg
LIB_DEPENDS=	gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui \
		gtkgl-2.0.1:${PORTSDIR}/x11-toolkits/gtkglarea2 \
		intl.4:${PORTSDIR}/devel/gettext \
		iconv.3:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	${X11BASE}/lib/libosg.so:${PORTSDIR}/graphics/osg

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

post-extract:
# This port has bogus config.{sub,guess} symlinks that point to where these
# files presumably live on the author's machine.  It causes the automatic
# replacement code to fail unless we replace them with files.
	@${RM} ${WRKSRC}/config.guess ${WRKSRC}/config.sub; \
	${TOUCH} ${WRKSRC}/config.guess ${WRKSRC}/config.sub

.include <bsd.port.mk>
