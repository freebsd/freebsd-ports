# New ports collection makefile for:	gcompris2
# Date created:				23 April 2003
# Whom:					Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gcompris2
PORTVERSION=	5.2
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gcompris
DISTNAME=	gcompris-${PORTVERSION}

MAINTAINER=	gnome@freebsd.org
COMMENT=	A simple Gnome2-based education game for children starting at 3

BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html
LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		ao.3:${PORTSDIR}/audio/libao \
		assetml.0:${PORTSDIR}/devel/libassetml

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack lthack gnomeprefix libgnomeui pygnome2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="${PTHREAD_LIBS} -lm"

INFO=		gcompris

.include <bsd.port.mk>
