PORTNAME=	libskk
DISTVERSION=	1.1.1
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/ueno/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Library to deal with Japanese Kana-to-Kanji conversion method
WWW=		https://github.com/ueno/libskk

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libjson-glib-1.0.so:devel/json-glib \
		libxkbcommon.so:x11/libxkbcommon

USES=		autoreconf gettext-tools gmake gnome libtool pathfix pkgconfig \
		tar:xz vala:build
GNU_CONFIGURE=	yes
USE_GNOME=	introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
