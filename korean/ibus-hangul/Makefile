PORTNAME=	ibus-hangul
PORTVERSION=	1.5.5
CATEGORIES=	korean

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul input engine for IBus
WWW=		https://github.com/libhangul/ibus-hangul/wiki

LICENSE=	GPLv2

LIB_DEPENDS=	libhangul.so:korean/libhangul \
		libibus-1.0.so:textproc/ibus

USES=		autoreconf gmake gnome libtool pkgconfig python
USE_GNOME=	gtk30 intlhack pygobject3
USE_PYTHON=	py3kplist

GH_ACCOUNT=	choehwanjin
GH_TAGNAME=	aa4b71c
USE_GITHUB=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	NLS

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-python="${PYTHON_CMD}"

GLIB_SCHEMAS=	org.freedesktop.ibus.engine.hangul.gschema.xml

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
