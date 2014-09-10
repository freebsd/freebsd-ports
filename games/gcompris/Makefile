# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gcompris
PORTVERSION=	14.07
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome2 educational games and activities for kids ages 2 to 10

LICENSE=	GPLv2

BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libao.so:${PORTSDIR}/audio/libao \
		libassetml.so:${PORTSDIR}/devel/libassetml \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		gnucap:${PORTSDIR}/cad/gnucap

USES=		display:configure gettext gmake libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GSTREAMER=	yes
USE_PYTHON=	2
USE_SQLITE=	3
USE_SDL=	mixer
USE_GNOME=	intlhack gnomeprefix gtk20 pygtk2 libxml2 librsvg2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    	${WRKSRC}/src/gcompris/gcompris.c
	@${FIND} ${WRKSRC} -type f -name "*.bak" -delete

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gcompris/lib*.so

.include <bsd.port.mk>
