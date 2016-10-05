# Created by: clement
# $FreeBSD$

PORTNAME=	weechat
PORTVERSION=	1.6
CATEGORIES=	irc
MASTER_SITES=	https://weechat.org/files/src/

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Lightweight and user friendly ncurses based IRC client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	weechat-devel-[0-9]*

LIB_DEPENDS+=	libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		cmake:outsource ncurses tar:bzip2
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DENABLE_GUILE=no \
		-DLIBDATADIR=${LOCALBASE}/libdata

OPTIONS_DEFINE=		BACKTRACE DOCS CA_BUNDLE GNUTLS ICON ICONV MANPAGES NLS
OPTIONS_DEFAULT=	ASPELL BACKTRACE CA_BUNDLE CHARSET GNUTLS ICON LUA MANPAGES PERL PYTHON RUBY TCL
OPTIONS_SUB=		yes

OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	ASPELL CHARSET JAVASCRIPT LUA PERL PYTHON RUBY TCL

BACKTRACE_DESC=		Provide crash backtraces
CA_BUNDLE_DESC=		Include CA bundle for certificate verification
ICON_DESC=		Desktop icon

PLUGINS_DESC=		Weechat Plugins
CHARSET_DESC=		Charset plugin (implies ICONV)
JAVASCRIPT_DESC=	Javascript script support
PYTHON_DESC=		Python script support
RUBY_DESC=		Ruby script support

ASPELL_CMAKE_BOOLL=	ENABLE_ASPELL
ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell

BACKTRACE_CMAKE_BOOL=	ENABLE_BACKTRACE
BACKTRACE_USES=		execinfo

CA_BUNDLE_CMAKE_ON=	-DCA_FILE=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

CHARSET_CMAKE_BOOL=	ENABLE_CHARSET
CHARSET_IMPLIES=	ICONV

DOCS_CMAKE_BOOL=	ENABLE_DOC
DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/asciidoctor:textproc/rubygem-asciidoctor

ICONV_CMAKE_BOOL=	ENABLE_ICONV
ICONV_USES=		iconv

JAVASCRIPT_CMAKE_BOOL=	ENABLE_JAVASCRIPT
JAVASCRIPT_LIB_DEPENDS=	libv8.so:lang/v8

GNUTLS_CMAKE_BOOL=	ENABLE_GNUTLS
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig

LUA_CMAKE_BOOL=		ENABLE_LUA
LUA_USES=		lua pkgconfig

MANPAGES_CMAKE_BOOL=	ENABLE_MAN
MANPAGES_CMAKE_ON=	-DMANDIR=${MANPREFIX}/man
MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/bin/asciidoctor:textproc/rubygem-asciidoctor

NLS_CMAKE_BOOL=		ENABLE_NLS
NLS_USES=		gettext

PERL_CMAKE_BOOL=	ENABLE_PERL
PERL_USES=		perl5

PYTHON_CMAKE_BOOL=	ENABLE_PYTHON
PYTHON_USES=		python

RUBY_CMAKE_BOOL=	ENABLE_RUBY
RUBY_USE=		ruby=yes

TCL_CMAKE_BOOL=		ENABLE_TCL
TCL_USES=		tcl:85+

.include <bsd.port.pre.mk>

.if defined(PORT_OPTIONS:MPYTHON) && ${PYTHON_MAJOR_VER} >= 3
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
