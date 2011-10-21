# New ports collection makefile for:	weechat-devel
# Date created:			2010-01-06
# Whom:				Jase Thew <freebsd@beardz.net>
#
# $FreeBSD$
#

PORTNAME=	weechat
PORTVERSION=	20111020
CATEGORIES=	irc
MASTER_SITES=	http://perturb.me.uk/distfiles/
PKGNAMESUFFIX=	-devel
DISTNAME=	weechat-devel-661f651048bb87fc660ecd10af5e332728a5b762

MAINTAINER=	freebsd@beardz.net
COMMENT=	A lightweight and user friendly ncurse based IRC client

LICENSE=	GPLv3

CONFLICTS=	weechat-0.3*

USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_NCURSES=	yes
WITH_NCURSES_BASE=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
WANT_PERL=	yes

OPTIONS=	RUBY		"Ruby scripting support"	Off	\
		PYTHON		"Python scripting support"	Off	\
		PERL		"Perl scripting support"	Off	\
		TCL		"TCL scripting support"		Off	\
		LUA		"Lua scripting support"		Off	\
		CHARSET		"Charset support"		On	\
		BACKTRACE	"Backtraces"			On	\
		DEBUG		"Debugging"			On	\
		ASPELL		"Spell checking"		Off	\
		GNUTLS		"GNU TLS"			Off	\
		NLS		"NLS support"			On	\
		DOCUMENTATION	"Build documentation"		Off

WRKSRC=	${WRKDIR}/${PORTNAME}-661f651

.include <bsd.port.options.mk>

.if defined(WITHOUT_CHARSET)
CMAKE_ARGS+=	-DENABLE_CHARSET=no
PLIST_SUB+=	CHARSET="@comment "
.else
PLIST_SUB+=	CHARSET=""
.endif

.if defined(WITHOUT_NLS)
CMAKE_ARGS+=	-DENABLE_NLS=no
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_ASPELL)
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	ASPELL=""
.else
CMAKE_ARGS+=	-DENABLE_ASPELL=no
PLIST_SUB+=	ASPELL="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	-2.7
CMAKE_ARGS+=	-DBSD_PYTHON_CMD=${PYTHON_CMD} \
		-DBSD_PYTHON_VER=${PYTHON_VERSION}
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DENABLE_PYTHON=no
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_RUBY)
USE_RUBY=	yes
CMAKE_ARGS+=	-DBSD_RUBY_CMD=${RUBY} \
		-DBSD_RUBY_VER=${RUBY_NAME}
PLIST_SUB+=	RUBY=""
.else
CMAKE_ARGS+=	-DENABLE_RUBY=no
PLIST_SUB+=	RUBY="@comment "
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls
.else
CMAKE_ARGS+=	-DENABLE_GNUTLS=no
.endif

.if defined(WITH_PERL)
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
.else
CMAKE_ARGS+=	-DENABLE_PERL=no
PLIST_SUB+=	PERL="@comment "
.endif

.if defined(WITH_TCL)
USE_TCL=	83+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CMAKE_ARGS+=	-DBSD_TCL_VER=${TCL_VER} \
		-DBSD_TCL_LIBDIR=${LOCALBASE}/lib \
		-DBSD_TCL_INCDIR=${TCL_INCLUDEDIR}
PLIST_SUB+=	TCL=""
.else
CMAKE_ARGS+=	-DENABLE_TCL=no
PLIST_SUB+=	TCL="@comment "
.endif

.if defined(WITH_LUA)
USE_LUA=	5.0+
CMAKE_ARGS+=	-DBSD_LUA_VER=${LUA_VER} \
		-DBSD_LUA_LIBDIR=${LUA_LIBDIR} \
		-DBSD_LUA_INCDIR=${LUA_INCDIR}
PLIST_SUB+=	LUA=""
.else
CMAKE_ARGS+=	-DENABLE_LUA=no
PLIST_SUB+=	LUA="@comment "
.endif

.if defined(WITH_DOCUMENTATION)
BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc
BUILD_DEPENDS+=	source-highlight:${PORTSDIR}/textproc/source-highlight
PLIST_SUB+=	DOCUMENTATION=""
.else
CMAKE_ARGS+=	-DENABLE_DOC=no
PLIST_SUB+=	DOCUMENTATION="@comment "
.endif

.if defined(WITH_BACKTRACE)
LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo
.endif

MAN1=	weechat-curses.1

post-patch:
	@${REINPLACE_CMD} -e 's|$${LIBDIR}/../pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|INSTALL|#INSTALL|' ${WRKSRC}/doc/CMakeLists.txt
.for f in src/CMakeLists.txt src/core/CMakeLists.txt cmake/*.cmake
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${f}
.endfor
.if defined(WITHOUT_BACKTRACE)
	@${REINPLACE_CMD} -e '/IF.*FreeBSD/,/ENDIF.*FreeBSD/d' ${WRKSRC}/src/core/CMakeLists.txt
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/weechat-curses.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
