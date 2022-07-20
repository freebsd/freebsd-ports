PORTNAME=	ibus-anthy
PORTVERSION=	1.5.11
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/ibus/ibus-anthy/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	ja-

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Anthy engine for IBus

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libanthy.so:japanese/anthy \
		libibus-1.0.so:textproc/ibus

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--with-layout=default
USES=		gettext gmake gnome libtool pkgconfig python:3.6+
USE_GNOME=	pygobject3
GLIB_SCHEMAS=	org.freedesktop.ibus.engine.anthy.gschema.xml

.include <bsd.port.mk>
