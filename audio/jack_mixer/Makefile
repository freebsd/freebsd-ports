# Created by: gahr
# $FreeBSD$

PORTNAME=	jack_mixer
PORTVERSION=	10
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/${PORTNAME:S/_//}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mixer for the jack audio connection kit

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/fpconst.py:math/py-fpconst \
		${LOCALBASE}/include/pygtk-2.0/pygtk/pygtk.h:x11-toolkits/py-gtk2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		libtool pkgconfig python shebangfix
SHEBANG_FILES=	jack_mixer.py
USE_GNOME=	gconf2
GCONF_SCHEMAS=	jack_mixer.schemas
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
