# Created by: gahr
# $FreeBSD$

PORTNAME=	jack_mixer
PORTVERSION=	10
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/${PORTNAME:S/_//}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Mixer for the jack audio connection kit

LICENSE=	GPLv2

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst \
   		${LOCALBASE}/include/pygtk-2.0/pygtk/pygtk.h:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		pkgconfig
USE_PYTHON=	yes
USE_GNOME=	gconf2
GCONF_SCHEMAS=	jack_mixer.schemas
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
