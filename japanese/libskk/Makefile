# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	libskk
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	https://bitbucket.org/libskk/libskk/downloads/

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Library to deal with Japanese Kana-to-Kanji conversion method

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:lang/vala \
		p5-XML-Parser>=0:textproc/p5-XML-Parser
LIB_DEPENDS=	libgee.so:devel/libgee06 \
		libjson-glib-1.0.so:devel/json-glib

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	intlhack introspection:build
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
