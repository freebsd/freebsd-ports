# New ports collection makefile for:	gcompris2
# Date created:				23 April 2003
# Whom:					Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gcompris2
PORTVERSION=	6.5.2
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gcompris
DISTNAME=	gcompris-${PORTVERSION}

MAINTAINER=	gnome@freebsd.org
COMMENT=	Gnome2 educational games and activities for kids ages 2 to 10

BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html \
		gnuchess:${PORTSDIR}/games/gnuchess
LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		ao.3:${PORTSDIR}/audio/libao \
		assetml.0:${PORTSDIR}/devel/libassetml
RUN_DEPENDS=	gnuchess:${PORTSDIR}/games/gnuchess

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_PYTHON=	yes
USE_SDL=	mixer
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui pygnome2
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="${PTHREAD_LIBS} -lm"

INFO=		gcompris

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-DGNOME_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
