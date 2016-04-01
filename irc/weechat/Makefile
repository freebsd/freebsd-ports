# Created by: clement
# $FreeBSD$

PORTNAME=	weechat
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://weechat.org/files/src/

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Lightweight and user friendly ncurses based IRC client

LICENSE=	GPLv3

CONFLICTS=	weechat-devel-[0-9]*

USE_LDCONFIG=	yes
USES=		cmake iconv localbase ncurses tar:bzip2
CMAKE_ARGS+=	-DENABLE_GUILE=no \
		-DICONV_INCLUDE_PATH=${ICONV_INCLUDE_PATH}

LIB_DEPENDS+=	libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt

OPTIONS_DEFINE=	RUBY PYTHON PERL TCL LUA JAVASCRIPT CHARSET BACKTRACE ASPELL \
		GNUTLS CA_BUNDLE NLS ICON MANPAGES DOCS
OPTIONS_DEFAULT=RUBY PYTHON PERL TCL LUA CHARSET BACKTRACE ASPELL \
		GNUTLS CA_BUNDLE ICON MANPAGES

OPTIONS_SUB=	yes

BACKTRACE_DESC=	Provide crash backtraces
CA_BUNDLE_DESC=	Include CA bundle for certificate verification
CHARSET_DESC=	Charset conversion support
ICON_DESC=	Desktop icon
JAVASCRIPT_DESC=Javascript support
PYTHON_DESC=	Python scripting language support
RUBY_DESC=	Ruby scripting language support

ASPELL_CMAKE_OFF=	-DENABLE_ASPELL=no
ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell

BACKTRACE_USES=		execinfo

CA_BUNDLE_CMAKE_ON=	-DCA_FILE=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

CHARSET_CMAKE_OFF=	-DENABLE_CHARSET=no

DOCS_CMAKE_ON=		-DENABLE_DOC=yes

JAVASCRIPT_CMAKE_OFF=	-DENABLE_JAVASCRIPT=no
JAVASCRIPT_CMAKE_ON=	-DENABLE_JAVASCRIPT=yes
JAVASCRIPT_LIB_DEPENDS=	libv8.so:lang/v8

GNUTLS_CMAKE_OFF=	-DENABLE_GNUTLS=no
GNUTLS_USES=		pkgconfig
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

LUA_CMAKE_OFF=		-DENABLE_LUA=no
LUA_CMAKE_ON=		-DBSD_LUA_LIBDIR=${LUA_LIBDIR} \
			-DBSD_LUA_INCDIR=${LUA_INCDIR} \
			-DBSD_LUA_VER=${LUA_VER}
LUA_USES=		lua:51

MANPAGES_CMAKE_ON=	-DENABLE_MAN=yes -DMANDIR=${MANPREFIX}/man

NLS_CMAKE_OFF=		-DENABLE_NLS=no
NLS_USES=		gettext

PERL_CMAKE_OFF=		-DENABLE_PERL=no
PERL_USES=		perl5

PYTHON_CMAKE_OFF=	-DENABLE_PYTHON=no
PYTHON_CMAKE_ON=	-DBSD_PYTHON_CMD=${PYTHON_CMD} \
			-DBSD_PYTHON_VER=${PYTHON_VERSION}
PYTHON_USES=		python

RUBY_CMAKE_OFF=		-DENABLE_RUBY=no
RUBY_CMAKE_ON=		-DBSD_RUBY_CMD=${RUBY} \
			-DBSD_RUBY_VER=${RUBY_NAME}
RUBY_USE=		ruby=yes

TCL_CMAKE_OFF=		-DENABLE_TCL=no
TCL_CMAKE_ON=		-DBSD_TCL_VER=${TCL_VER} \
			-DBSD_TCL_LIBDIR=${LOCALBASE}/lib \
			-DBSD_TCL_INCDIR=${TCL_INCLUDEDIR}
TCL_USES=		tcl:85+

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	xsltproc:textproc/libxslt \
		docbook-xsl>=0:textproc/docbook-xsl \
		asciidoc:textproc/asciidoc \
		source-highlight>=3.1.5:textproc/source-highlight
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${LIBDIR}/../pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt
.for f in src/CMakeLists.txt src/core/CMakeLists.txt cmake/*.cmake
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/${f}
.endfor
.if empty(PORT_OPTIONS:MBACKTRACE)
	@${REINPLACE_CMD} -e '/IF.*FreeBSD/,/ENDIF.*FreeBSD/d' \
		${WRKSRC}/src/core/CMakeLists.txt
.endif
.if empty(PORT_OPTIONS:MICON)
	@${REINPLACE_CMD} -e '/^# icon$$/,/^$$/d' \
		${WRKSRC}/CMakeLists.txt
.endif

post-install:
	${LN} -sf ${PREFIX}/bin/weechat ${STAGEDIR}${PREFIX}/bin/weechat-curses

.include <bsd.port.mk>
