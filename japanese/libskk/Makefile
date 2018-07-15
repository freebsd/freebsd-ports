# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	libskk
DISTVERSION=	1.0.4
CATEGORIES=	japanese

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Library to deal with Japanese Kana-to-Kanji conversion method

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala \
		p5-XML-Parser>=0:textproc/p5-XML-Parser
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libjson-glib-1.0.so:devel/json-glib

USES=		autoreconf gmake libtool pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ueno
GNU_CONFIGURE=	yes
USE_GNOME=	intlhack introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
