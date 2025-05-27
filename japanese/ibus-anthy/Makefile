PORTNAME=	ibus-anthy
DISTVERSION=	1.5.17
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/ibus/ibus-anthy/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ja-

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Anthy engine for IBus
WWW=		https://github.com/ibus/ibus-anthy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libibus-1.0.so:textproc/ibus

FLAVORS=	original unicode

original_LIB_DEPENDS=		libanthy.so:japanese/anthy
original_CONFLICTS_INSTALL=	${PORTNAME}-unicode
unicode_PKGNAMESUFFIX=		-unicode
unicode_LIB_DEPENDS=		libanthy-unicode.so:japanese/anthy-unicode
unicode_CONFLICTS_INSTALL=	${PORTNAME}

USES=		gettext gmake gnome libtool pkgconfig python
USE_GNOME=	pygobject3
GLIB_SCHEMAS=	org.freedesktop.ibus.engine.anthy.gschema.xml

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-layout=default
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
