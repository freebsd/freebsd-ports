# Created by: clement
# $FreeBSD$

PORTNAME=	weechat
PORTVERSION=	2.1
CATEGORIES=	irc
MASTER_SITES=	https://weechat.org/files/src/

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Lightweight and user friendly ncurses based IRC client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		cmake:outsource,noninja ncurses libtool tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DENABLE_GUILE=no \
		-DLIBDATADIR=${LOCALBASE}/libdata

OPTIONS_DEFINE=		BACKTRACE DOCS CA_BUNDLE GNUTLS HEADLESS ICON ICONV \
			MANPAGES NLS
OPTIONS_DEFAULT=	ASPELL BACKTRACE CA_BUNDLE CHARSET GNUTLS HEADLESS \
			ICON LUA MANPAGES PERL PYTHON RUBY TCL
OPTIONS_SUB=		yes

# BROKEN: ruby.h: error: wrong number of arguments specified for 'deprecated' attribute
OPTIONS_EXCLUDE_powerpc64=	RUBY

OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	ASPELL CHARSET JAVASCRIPT LUA PERL PYTHON PHP RUBY TCL

BACKTRACE_DESC=		Provide crash backtraces
CA_BUNDLE_DESC=		Include CA bundle for certificate verification
CHARSET_DESC=		Charset plugin (implies ICONV)
ICON_DESC=		Desktop icon
HEADLESS_DESC=		Build headless weechat as well
JAVASCRIPT_DESC=	Javascript script support
PLUGINS_DESC=		Weechat Plugins
PYTHON_DESC=		Python script support
RUBY_DESC=		Ruby script support

.for _opt in ASPELL CHARSET ICONV JAVASCRIPT GNUTLS LUA NLS PERL PHP PYTHON RUBY TCL
${_opt}_CMAKE_BOOL=	ENABLE_${_opt}
.endfor

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
BACKTRACE_CMAKE_BOOL=	ENABLE_BACKTRACE
CA_BUNDLE_CMAKE_ON=	-DCA_FILE=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
CHARSET_IMPLIES=	ICONV
DOCS_CMAKE_BOOL=	ENABLE_DOC
DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/asciidoctor:textproc/rubygem-asciidoctor
HEADLESS_CMAKE_BOOL=	ENABLE_HEADLESS
ICONV_USES=		iconv
JAVASCRIPT_LIB_DEPENDS=	libv8.so:lang/v8
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig
LUA_USES=		lua pkgconfig
MANPAGES_CMAKE_BOOL=	ENABLE_MAN
MANPAGES_CMAKE_ON=	-DMANDIR=${MANPREFIX}/man
MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/bin/asciidoctor:textproc/rubygem-asciidoctor
NLS_USES=		gettext
PERL_USES=		perl5
PHP_USES=		php:embed
PYTHON_USES=		python
RUBY_USE=		ruby=yes
TCL_USES=		tcl:85+

.include <bsd.port.pre.mk>

.if !empty(PORT_OPTIONS:MPYTHON) && ${PYTHON_MAJOR_VER} >= 3
WARNING=	"Using Python 3.x is NOT recommended because many \"official\" scripts won\'t work"
CMAKE_ARGS+=	-DENABLE_PYTHON3:BOOL=true \
		-DPYTHON_LIBRARY:FILEPATH=${LOCALBASE}/lib/libpython${PYTHON_VER}m.so
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${LIBDIR}/../pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt
.for f in src/CMakeLists.txt src/core/CMakeLists.txt cmake/*.cmake
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/${f}
.endfor

post-patch-ICON-off:
	@${REINPLACE_CMD} -e '/^# icon$$/,/^$$/d' ${WRKSRC}/CMakeLists.txt

post-install:
	${LN} -sf weechat ${STAGEDIR}${PREFIX}/bin/weechat-curses

.include <bsd.port.post.mk>
