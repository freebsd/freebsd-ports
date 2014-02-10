# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	libskk
PORTVERSION=	1.0.1
CATEGORIES=	japanese
MASTER_SITES=	https://bitbucket.org/libskk/libskk/downloads/

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Library to deal with Japanese Kana-to-Kanji conversion method

LICENSE=	GPLv3

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		valac:${PORTSDIR}/lang/vala \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	libgee.so:${PORTSDIR}/devel/libgee06 \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

USES=		gmake pathfix pkgconfig
USE_GNOME=	intltool introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -w

PORTDOCS=	ChangeLog NEWS README

OPTIONS_DEFINE=	 DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libskk.so.0

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
