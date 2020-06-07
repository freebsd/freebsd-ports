# Created by: clement
# $FreeBSD$

PORTNAME=	weechat
DISTVERSION=	2.8
CATEGORIES=	irc
MASTER_SITES=	https://weechat.org/files/src/

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Lightweight and user friendly ncurses based IRC client

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		cmake ncurses libtool tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLIBDATADIR=${LOCALBASE}/libdata

OPTIONS_DEFINE=		BACKTRACE DOCS CA_BUNDLE GNUTLS HEADLESS ICON ICONV \
			MANPAGES NLS
OPTIONS_DEFAULT=	ASPELL BACKTRACE CA_BUNDLE CHARSET GNUTLS HEADLESS \
			ICON LUA MANPAGES PERL PYTHON RUBY TCL
OPTIONS_SUB=		yes

# BROKEN: ruby.h: error: wrong number of arguments specified for 'deprecated' attribute
OPTIONS_EXCLUDE_powerpc64=	RUBY

OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	ASPELL CHARSET GUILE JAVASCRIPT LUA PERL PHP PYTHON RUBY TCL

BACKTRACE_DESC=		Provide crash backtraces
CA_BUNDLE_DESC=		Include CA bundle for certificate verification
CHARSET_DESC=		Charset plugin (implies ICONV)
GUILE_DESC=		Guile script support
HEADLESS_DESC=		Build headless weechat as well
ICON_DESC=		Desktop icon
JAVASCRIPT_DESC=	Javascript script support
PLUGINS_DESC=		Weechat Plugins
PYTHON_DESC=		Python script support
RUBY_DESC=		Ruby script support

.for _opt in ${OPTIONS_GROUP_PLUGINS} BACKTRACE HEADLESS ICONV GNUTLS NLS
${_opt}_CMAKE_BOOL=	ENABLE_${_opt}
.endfor

ASPELL_CMAKE_BOOL=	ENABLE_SPELL
ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
CA_BUNDLE_CMAKE_ON=	-DCA_FILE=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
CHARSET_IMPLIES=	ICONV
DOCS_CMAKE_BOOL=	ENABLE_DOC
DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/asciidoctor:textproc/rubygem-asciidoctor
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig
GUILE_LIB_DEPENDS=	libguile-2.2.so:lang/guile2
GUILE_CMAKE_BOOL=	ENABLE_GUILE
ICONV_USES=		iconv
JAVASCRIPT_LIB_DEPENDS=	libv8.so:lang/v8
LUA_USES=		lua pkgconfig
MANPAGES_CMAKE_BOOL=	ENABLE_MAN
MANPAGES_CMAKE_ON=	-DMANDIR=${MANPREFIX}/man
MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/bin/asciidoctor:textproc/rubygem-asciidoctor
NLS_USES=		gettext
PERL_USES=		perl5
PHP_USES=		php:build,embed
PYTHON_USES=		python
RUBY_USE=		ruby=yes
TCL_CMAKE_ON=		-DTCL_VERSION:STRING="${TCL_VER}" \
			-DTCL_TCLSH:PATH="${TCLSH}"
TCL_USES=		tcl

.include <bsd.port.pre.mk>

.if !empty(PORT_OPTIONS:MPYTHON) && ${PYTHON_MAJOR_VER} == 2
CMAKE_ARGS+=	-DENABLE_PYTHON2:BOOL=true \
#		-DPYTHON_LIBRARIES=${LOCALBASE}/lib
.endif

post-patch:
	@${REINPLACE_CMD} 's|$${LIBDIR}/../pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt
.for f in src/CMakeLists.txt src/core/CMakeLists.txt cmake/*.cmake
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} 's|python${PYTHON_MAJOR_VER}|python-${PYTHON_VER}|' \
		${WRKSRC}/cmake/FindPython.cmake

post-patch-ICON-off:
	@${REINPLACE_CMD} -e '/^# icon$$/,/^$$/d' ${WRKSRC}/CMakeLists.txt

post-install:
	${LN} -sf weechat ${STAGEDIR}${PREFIX}/bin/weechat-curses

.include <bsd.port.post.mk>
