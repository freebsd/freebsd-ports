# New ports collection makefile for:	gcompris2
# Date created:				23 April 2003
# Whom:					Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gcompris
PORTVERSION=	9.6.1
CATEGORIES=	games gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome2 educational games and activities for kids ages 2 to 10

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html \
		gnuchess:${PORTSDIR}/games/gnuchess \
		${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite20
LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ao.4:${PORTSDIR}/audio/libao \
		assetml.0:${PORTSDIR}/devel/libassetml \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		gnet-2.0.0:${PORTSDIR}/net/gnet2 \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	gnuchess:${PORTSDIR}/games/gnuchess \
		${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite20 \
		gnucap:${PORTSDIR}/cad/gnucap

USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GSTREAMER=	yes
USE_PYTHON=	yes
USE_SDL=	mixer
USE_DISPLAY=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk20 pygtk2 libxml2 librsvg2
CONFIGURE_ARGS=	--enable-gnet \
		--enable-dbus
CPPFLAGS=	"-I${LOCALBASE}/include"
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="${PTHREAD_LIBS} -lm"

MAN6=		gcompris.6
INFO=		gcompris

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    	${WRKSRC}/src/gcompris/gcompris.c
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-DGTK_DISABLE_DEPRECATED||g' -e \
		's|-DGNOME_DISABLE_DEPRECATED||g'
	@${FIND} ${WRKSRC} -type f -name "*.bak" -delete

.if !defined(DISPLAY)
pre-configure:
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
		${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
		${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
	${LOCALBASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5

post-configure:
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
		${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
		${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
.endif

.include <bsd.port.post.mk>
