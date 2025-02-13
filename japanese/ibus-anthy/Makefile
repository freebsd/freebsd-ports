PORTNAME=	ibus-anthy
DISTVERSION=	1.5.16
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/ibus/ibus-anthy/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ja-

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Anthy engine for IBus
WWW=		https://github.com/ibus/ibus-anthy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libibus-1.0.so:textproc/ibus

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--with-layout=default
USES=		gettext gmake gnome libtool pkgconfig python
USE_GNOME=	pygobject3
GLIB_SCHEMAS=	org.freedesktop.ibus.engine.anthy.gschema.xml

FLAVORS=	original unicode

original_CONFLICTS_INSTALL=	${PORTNAME}-unicode
original_LIB_DEPENDS=		libanthy.so:japanese/anthy
unicode_CONFLICTS_INSTALL=	${PORTNAME}
unicode_LIB_DEPENDS=		libanthy-unicode.so:japanese/anthy-unicode
unicode_PKGNAMESUFFIX=		-unicode

.include <bsd.port.mk>
