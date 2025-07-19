PORTNAME=	weechat
PORTVERSION=	4.7.0
CATEGORIES=	irc
MASTER_SITES=	https://weechat.org/files/src/

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Lightweight and user friendly ncurses based IRC client
WWW=		https://weechat.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libgpg-error.so:security/libgpg-error

USES=		cmake cpe ncurses pkgconfig tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLIBDATADIR=${LOCALBASE}/libdata

OPTIONS_DEFINE=		API BACKTRACE DOCS HEADLESS ICON ICONV MANPAGES NLS ZSTD
OPTIONS_DEFAULT=	API ASPELL BACKTRACE CHARSET HEADLESS ICON LUA MANPAGES \
			NLS PERL PYTHON RUBY TCL TYPING ZSTD
OPTIONS_SUB=		yes

OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	ASPELL CHARSET GUILE JAVASCRIPT LUA PERL PHP PYTHON \
			RUBY TCL TYPING

API_DESC=		HTTP REST API
BACKTRACE_DESC=		Provide crash backtraces
CHARSET_DESC=		Charset plugin (implies ICONV)
GUILE_DESC=		Guile script support
HEADLESS_DESC=		Build headless weechat as well
ICON_DESC=		Desktop icon
JAVASCRIPT_DESC=	Javascript script support
PLUGINS_DESC=		Weechat Plugins
PYTHON_DESC=		Python script support
RUBY_DESC=		Ruby script support
TYPING_DESC=		Typing status plugin

.for _opt in ${OPTIONS_GROUP_PLUGINS} BACKTRACE HEADLESS ICONV GNUTLS NLS ZSTD
${_opt}_CMAKE_BOOL=	ENABLE_${_opt}
.endfor

API_CMAKE_BOOL=		ENABLE_CJSON
API_LIB_DEPENDS=	libcjson.so:devel/libcjson
ASPELL_CMAKE_BOOL=	ENABLE_SPELL
ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
CHARSET_IMPLIES=	ICONV
DOCS_CMAKE_BOOL=	ENABLE_DOC ENABLE_DOC_INCOMPLETE
DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/asciidoctor:textproc/rubygem-asciidoctor
GUILE_USES=		guile:2.2,conflicts
ICONV_USES=		iconv
JAVASCRIPT_LIB_DEPENDS=	libv8.so:lang/v8
LUA_USES=		lua pkgconfig
MANPAGES_CMAKE_BOOL=	ENABLE_MAN
MANPAGES_CMAKE_ON=	-DMANDIR=${PREFIX}/share/man
MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/bin/asciidoctor:textproc/rubygem-asciidoctor
NLS_USES=		gettext
PERL_USES=		perl5
PHP_USES=		php:build,embed
PYTHON_USES=		python
RUBY_USES=		ruby
TCL_CMAKE_ON=		-DTCL_VERSION:STRING="${TCL_VER}" \
			-DTCL_TCLSH:PATH="${TCLSH}"
TCL_USES=		tcl
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

.include <bsd.port.pre.mk>

post-patch:
.if ${LOCALBASE} != "/usr/local"
.  for f in src/core/CMakeLists.txt cmake/*.cmake
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/$f
.  endfor
.endif

post-patch-ICON-off:
	@${REINPLACE_CMD} -e '/^# icon$$/,/^$$/d' ${WRKSRC}/CMakeLists.txt

post-install:
	${LN} -sf weechat ${STAGEDIR}${PREFIX}/bin/weechat-curses

.include <bsd.port.post.mk>
