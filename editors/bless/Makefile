PORTNAME=	bless
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	mono@FreeBSD.org
COMMENT=	High-quality, full-featured hexadecimal editor
WWW=		https://github.com/afrantzis/bless

LICENSE=	GPLv2+

USES=		gnome meson mono pkgconfig
USE_GNOME=	gtksharp20
USE_GITHUB=	yes
GH_ACCOUNT=	afrantzis

MESON_ARGS=	-Dtests=false

OPTIONS_DEFINE=	HELP
OPTIONS_DEFAULT=	HELP
OPTIONS_SUB=	yes

HELP_DESC=	Install DocBook and HTML user documentation
HELP_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:textproc/docbook-xsl \
		itstool:textproc/itstool xsltproc:textproc/libxslt
HELP_USES=	gettext-tools
HELP_MESON_OFF=	-Duser_doc=false -Dhtml_user_doc=false

post-patch:
	@${REINPLACE_CMD} -E 's,https?://.*/release/xsl/current,${LOCALBASE}/share/xsl/docbook,' \
		${WRKSRC}/doc/user/meson.build

.include <bsd.port.mk>

# XXX: stripping Mono/.Net PE32 executables (DLLs) does not work
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:N--strip}
