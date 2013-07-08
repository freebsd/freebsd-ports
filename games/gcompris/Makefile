# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gcompris
PORTVERSION=	12.11
CATEGORIES=	games gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome2 educational games and activities for kids ages 2 to 10

LICENSE=	GPLv2

BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html \
		gnuchess:${PORTSDIR}/games/gnuchess \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ao.4:${PORTSDIR}/audio/libao \
		assetml.0:${PORTSDIR}/devel/libassetml \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	gnuchess:${PORTSDIR}/games/gnuchess \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		gnucap:${PORTSDIR}/cad/gnucap

USE_BZIP2=	yes
USES=		gettext gmake display:configure
GNU_CONFIGURE=	yes
USE_GSTREAMER=	yes
USE_PYTHON=	-2.7
USE_SDL=	mixer
USE_DISPLAY=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk20 pygtk2 libxml2 librsvg2
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS} -lm"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN6=		gcompris.6

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    	${WRKSRC}/src/gcompris/gcompris.c
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-DGTK_DISABLE_DEPRECATED||g' -e \
		's|-DGNOME_DISABLE_DEPRECATED||g'
	@${FIND} ${WRKSRC} -type f -name "*.bak" -delete

.include <bsd.port.mk>
