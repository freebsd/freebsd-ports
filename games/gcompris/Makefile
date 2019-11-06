# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gcompris
PORTVERSION=	15.10
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	http://gcompris.net/download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome2 educational games and activities for kids ages 2 to 10

BROKEN=		unfetchable

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	texi2html:textproc/texi2html \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libao.so:audio/libao \
		libassetml.so:devel/libassetml \
		libdbus-glib-1.so:devel/dbus-glib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		gnucap:cad/gnucap

USES=		display:configure gettext gmake libtool localbase pathfix \
		pkgconfig python:2.7 shebangfix sqlite tar:bzip2 perl5
USE_PERL5=	run
SHEBANG_FILES=	boards/voices/*.sh boards/voices/*.pl
GNU_CONFIGURE=	yes
USE_GSTREAMER=	yes
USE_SDL=	mixer
USE_GNOME=	intlhack gnomeprefix gtk20 pygtk2 libxml2 librsvg2

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/gcompris/gcompris.c
	@${FIND} ${WRKSRC} -type f -name "*.bak" -delete

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gcompris/lib*.so

.include <bsd.port.mk>
