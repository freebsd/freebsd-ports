# New ports collection makefile for:	gcompris2
# Date created:				23 April 2003
# Whom:					Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gcompris2
PORTVERSION=	7.0.3
PORTREVISION=	3
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gcompris
DISTNAME=	gcompris-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome2 educational games and activities for kids ages 2 to 10

BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html \
		gnuchess:${PORTSDIR}/games/gnuchess \
		${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite20
LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		ao.3:${PORTSDIR}/audio/libao \
		assetml.0:${PORTSDIR}/devel/libassetml \
		sqlite3.8:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	gnuchess:${PORTSDIR}/games/gnuchess \
		${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite20

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_SDL=	mixer
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui pygnome2
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="${PTHREAD_LIBS} -lm"

INFO=		gcompris

.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT} \
		${X11BASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	Does not build on 4.X
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-DGNOME_DISABLE_DEPRECATED||g'

.include <bsd.port.post.mk>
