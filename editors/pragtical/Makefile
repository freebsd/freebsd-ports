PORTNAME=	pragtical
PORTVERSION=	3.3.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Practical and pragmatic code editor
WWW=		https://pragtical.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpcre2-8.so:devel/pcre2 \
		libuchardet.so:textproc/uchardet

USES=		desktop-file-utils localbase:ldflags meson pkgconfig sdl
USE_SDL=	sdl2
MESON_ARGS=	-Duse_system_lua=true -Dppm=false

USE_GITHUB=	yes
GH_PROJECT=	colors:clr plugins:plg widget:wgt
GH_TAGNAME=	83be02c:clr eeab671:plg a5f14c2:wgt
GH_SUBDIR=	data/widget:wgt subprojects/colors:clr \
		subprojects/plugins:plg

PORTDOCS=	changelog.md licenses.md

OPTIONS_DEFINE=	JIT DOCS
OPTIONS_DEFAULT=	JIT
OPTIONS_SUB=	yes

JIT_DESC=	Use Lua JIT compiler
JIT_USES=	luajit
JIT_USES_OFF=	lua:54
JIT_MESON_OFF=	-Djit=false

post-extract:
.for sp in colors plugins
	@cd ${WRKSRC}/subprojects && ${CP} -a packagefiles/${sp}/* ${sp}
.endfor

post-patch:
	@${REINPLACE_CMD} -e '/host_machine\.system/s,linux,${OPSYS:tl},' \
		${WRKSRC}/meson.build

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/changelog.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
