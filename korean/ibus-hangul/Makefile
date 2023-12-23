PORTNAME=	ibus-hangul
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	korean
MASTER_SITES=	https://github.com/choehwanjin/ibus-hangul/releases/download/${PORTVERSION}/

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul input engine for IBus
WWW=		https://github.com/libhangul/ibus-hangul/wiki

LICENSE=	GPLv2

LIB_DEPENDS=	libhangul.so:korean/libhangul \
		libibus-1.0.so:textproc/ibus

USES=		gmake gnome libtool pkgconfig python
USE_GNOME=	gtk30 intlhack pygobject3
USE_PYTHON=	py3kplist

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
