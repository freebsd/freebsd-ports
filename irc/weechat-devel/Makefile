# $FreeBSD$

PORTNAME=	weechat
PORTVERSION=	20140110
CATEGORIES=	irc
MASTER_SITES=	http://perturb.me.uk/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jase/weechat-devel
PKGNAMESUFFIX=	-devel
DISTNAME=	weechat-devel-${GITREV}

MAINTAINER=	jase@FreeBSD.org
COMMENT=	A lightweight and user friendly ncurses based IRC client

LICENSE=	GPLv3

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

CONFLICTS=	weechat-0.3*

USE_LDCONFIG=	yes
USES=		cmake iconv
CMAKE_ARGS+=	-DENABLE_GUILE=no
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

GITDESC=	v0.4.2-211-g3bba891
GITREV!=	echo "${GITDESC}" | sed -E 's/^.*-g(.{7})$$/\1/'
WRKSRC=		${WRKDIR}/${PORTNAME}-${GITREV}

# Please note: the DEBUG option is *NOT* empty, it is utilised by
# bsd.cmake.mk to set the cmake build type to Debug instead of
# Release.

OPTIONS_DEFINE=	RUBY PYTHON PERL TCL LUA CHARSET BACKTRACE DEBUG ASPELL \
		GNUTLS NLS DOCUMENTATION COLOR256 ICON MANPAGES
OPTIONS_DEFAULT=CHARSET BACKTRACE DEBUG MANPAGES

BACKTRACE_DESC=	Provide crash backtraces
CHARSET_DESC=	Charset conversion support
DOCUMENTATION_DESC=	Build and install documentation
LUA_DESC=	Lua scripting support
PERL_DESC=	Perl scripting support
PYTHON_DESC=	Python scripting support
RUBY_DESC=	Ruby scripting support
TCL_DESC=	Tcl scripting support
COLOR256_DESC=	Use ncurses port for 256 color support
ICON_DESC=	Desktop icon

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHARSET}
PLIST_SUB+=	CHARSET=""
.else
CMAKE_ARGS+=	-DENABLE_CHARSET=no
PLIST_SUB+=	CHARSET="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DENABLE_NLS=no
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MASPELL}
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	ASPELL=""
.else
CMAKE_ARGS+=	-DENABLE_ASPELL=no
PLIST_SUB+=	ASPELL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2
CMAKE_ARGS+=	-DBSD_PYTHON_CMD=${PYTHON_CMD} \
		-DBSD_PYTHON_VER=${PYTHON_VERSION}
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DENABLE_PYTHON=no
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
CMAKE_ARGS+=	-DBSD_RUBY_CMD=${RUBY} \
		-DBSD_RUBY_VER=${RUBY_NAME}
PLIST_SUB+=	RUBY=""
.else
CMAKE_ARGS+=	-DENABLE_RUBY=no
PLIST_SUB+=	RUBY="@comment "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
USES+=		pkgconfig
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.else
CMAKE_ARGS+=	-DENABLE_GNUTLS=no
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
PLIST_SUB+=	PERL=""
.else
CMAKE_ARGS+=	-DENABLE_PERL=no
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MTCL}
USE_TCL=	84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CMAKE_ARGS+=	-DBSD_TCL_VER=${TCL_VER} \
		-DBSD_TCL_LIBDIR=${LOCALBASE}/lib \
		-DBSD_TCL_INCDIR=${TCL_INCLUDEDIR}
PLIST_SUB+=	TCL=""
.else
CMAKE_ARGS+=	-DENABLE_TCL=no
PLIST_SUB+=	TCL="@comment "
.endif

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.1+
CMAKE_ARGS+=	-DBSD_LUA_LIBDIR=${LUA_LIBDIR} \
		-DBSD_LUA_INCDIR=${LUA_INCDIR}
PLIST_SUB+=	LUA=""
.else
CMAKE_ARGS+=	-DENABLE_LUA=no
PLIST_SUB+=	LUA="@comment "
.endif

.if ${PORT_OPTIONS:MDOCUMENTATION}
BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		source-highlight>=3.1.5:${PORTSDIR}/textproc/source-highlight
CMAKE_ARGS+=	-DENABLE_DOC=yes
PLIST_SUB+=	DOCUMENTATION=""
.else
CMAKE_ARGS+=	-DENABLE_DOC=no
PLIST_SUB+=	DOCUMENTATION="@comment "
.endif

.if ${PORT_OPTIONS:MMANPAGES}
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
.if empty(PORT_OPTIONS:MDOCUMENTATION)
BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		source-highlight>=3.1.5:${PORTSDIR}/textproc/source-highlight
.endif
CMAKE_ARGS+=	-DENABLE_MAN=yes -DMANDIR=${MANPREFIX}/man
.else
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:man/}
MASTER_SITE_SUBDIR+=	jase/weechat-devel/:man
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		weechat-devel-20131015-manpages.tar.gz:man
CMAKE_ARGS+=	-DENABLE_MAN=no
.endif
PLIST_SUB+=	MANPAGES=""
.else
CMAKE_ARGS+=	-DENABLE_MAN=no
PLIST_SUB+=	MANPAGES="@comment"
.endif

.if ${PORT_OPTIONS:MBACKTRACE}
LIB_DEPENDS+=	execinfo:${PORTSDIR}/devel/libexecinfo
.endif

.if ${PORT_OPTIONS:MCOLOR256}
USES+=		ncurses:port
CMAKE_ARGS+=	-DNCURSES_INCLUDE_PATH=${LOCALBASE}/include/ncurses
.else
USES+=		ncurses
.endif

.if ${PORT_OPTIONS:MICON}
PLIST_SUB+=	ICON=""
.else
PLIST_SUB+=	ICON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${LIBDIR}/../pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|INSTALL|#INSTALL|' ${WRKSRC}/doc/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|GIT_VERSION=""|GIT_VERSION="${GITDESC}"|' ${WRKSRC}/git-version.sh
	@${REINPLACE_CMD} -e 's|<sys/termios.h>|<termios.h>|' ${WRKSRC}/src/gui/curses/gui-curses-window.c
.for f in src/CMakeLists.txt src/core/CMakeLists.txt cmake/*.cmake
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${f}
.endfor
.if empty(PORT_OPTIONS:MBACKTRACE)
	@${REINPLACE_CMD} -e '/IF.*FreeBSD/,/ENDIF.*FreeBSD/d' ${WRKSRC}/src/core/CMakeLists.txt
.endif
.if empty(PORT_OPTIONS:MICON)
	@${REINPLACE_CMD} -e '/^# icon$$/,/^$$/d' ${WRKSRC}/CMakeLists.txt
.endif

pre-configure:
.if ${PORT_OPTIONS:MCOLOR256}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "==> You have selected the ncurses 256 color option. Please ensure that"
	@${ECHO_MSG} "==> the devel/ncurses port is built with the EXTCOLORS option enabled."
	@${ECHO_MSG} "==>"
	@${ECHO_MSG} "==> Press Ctrl-C now if you want to re-configure."
	@${ECHO_MSG} ""
	@sleep 5
.endif

post-install:
.if ${PORT_OPTIONS:MMANPAGES} && !defined(MAINTAINER_MODE)
	${INSTALL_MAN} ${WRKDIR}/manpages/weechat.1 ${STAGEDIR}${PREFIX}/man/man1
.for f in de fr it ja
	@${MKDIR} ${STAGEDIR}${PREFIX}/man/${f}/man1
	${INSTALL_MAN} ${WRKDIR}/manpages/${f}/weechat.1 ${STAGEDIR}${PREFIX}/man/${f}/man1
.endfor
.endif
	${LN} -sf ${PREFIX}/bin/weechat ${STAGEDIR}${PREFIX}/bin/weechat-curses

.include <bsd.port.mk>
