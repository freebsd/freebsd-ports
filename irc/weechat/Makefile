# Created by: clement
# $FreeBSD$

PORTNAME=	weechat
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://weechat.org/files/src/ \
		http://perturb.me.uk/distfiles/weechat/:mandocs \
		${MASTER_SITE_LOCAL:S/$/:mandocs/}
MASTER_SITE_SUBDIR=	jase/weechat/:mandocs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Lightweight and user friendly ncurses based IRC client

LICENSE=	GPLv3

CONFLICTS=	weechat-devel-[0-9]*

USE_LDCONFIG=	yes
USES=			cmake iconv ncurses
CMAKE_ARGS+=	-DENABLE_GUILE=no
CFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib

LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl \
				libgcrypt.so:${PORTSDIR}/security/libgcrypt

OPTIONS_DEFINE=	RUBY PYTHON PERL TCL LUA CHARSET BACKTRACE ASPELL \
				GNUTLS CA_BUNDLE NLS ICON MANPAGES DOCS
OPTIONS_DEFAULT=RUBY PYTHON PERL TCL LUA CHARSET BACKTRACE ASPELL \
				GNUTLS CA_BUNDLE ICON MANPAGES

OPTIONS_SUB=	yes

BACKTRACE_DESC=	Provide crash backtraces
CA_BUNDLE_DESC=	Include CA bundle for certificate verification
CHARSET_DESC=	Charset conversion support
ICON_DESC=		Desktop icon
PYTHON_DESC=	Python scripting language support
RUBY_DESC=		Ruby scripting language support

ASPELL_CMAKE_OFF=	-DENABLE_ASPELL=no
ASPELL_LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell

BACKTRACE_LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

CA_BUNDLE_CMAKE_ON=		-DCA_FILE=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

CHARSET_CMAKE_OFF=	-DENABLE_CHARSET=no

GNUTLS_CMAKE_OFF=	-DENABLE_GNUTLS=no
GNUTLS_USES=		pkgconfig
GNUTLS_LIB_DEPENDS=	libgnutls.so.28:${PORTSDIR}/security/gnutls

LUA_CMAKE_OFF=		-DENABLE_LUA=no
LUA_CMAKE_ON=		-DBSD_LUA_LIBDIR=${LUA_LIBDIR} \
					-DBSD_LUA_INCDIR=${LUA_INCDIR}
LUA_USES=			lua:51

NLS_CMAKE_OFF=		-DENABLE_NLS=no
NLS_USES=			gettext

PERL_CMAKE_OFF=		-DENABLE_PERL=no
PERL_USES=			perl5

PYTHON_CMAKE_OFF=	-DENABLE_PYTHON=no
PYTHON_CMAKE_ON=	-DBSD_PYTHON_CMD=${PYTHON_CMD} \
					-DBSD_PYTHON_VER=${PYTHON_VERSION}
PYTHON_USES=		python

RUBY_CMAKE_OFF=		-DENABLE_RUBY=no
RUBY_CMAKE_ON=		-DBSD_RUBY_CMD=${RUBY} \
					-DBSD_RUBY_VER=${RUBY_NAME}
RUBY_USE=			ruby=yes

TCL_CMAKE_OFF=		-DENABLE_TCL=no
TCL_CMAKE_ON=		-DBSD_TCL_VER=${TCL_VER} \
					-DBSD_TCL_LIBDIR=${LOCALBASE}/lib \
					-DBSD_TCL_INCDIR=${TCL_INCLUDEDIR}
TCL_USES=			tcl:85+

.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
				docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl \
				asciidoc:${PORTSDIR}/textproc/asciidoc \
				source-highlight>=3.1.5:${PORTSDIR}/textproc/source-highlight
CMAKE_ARGS+=	-DENABLE_MAN=yes -DMANDIR=${MANPREFIX}/man -DENABLE_DOC=yes
.else
CMAKE_ARGS+=	-DENABLE_MAN=no -DENABLE_DOC=no
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} && !defined(MAINTAINER_MODE)
DISTFILES+=	${DISTNAME}-docs.txz:mandocs
.endif

.if ${PORT_OPTIONS:MMANPAGES} && !defined(MAINTAINER_MODE)
DISTFILES+=	${DISTNAME}-manpages.txz:mandocs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${LIBDIR}/../pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|INSTALL|#INSTALL|' ${WRKSRC}/doc/CMakeLists.txt
.for f in src/CMakeLists.txt src/core/CMakeLists.txt cmake/*.cmake
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${f}
.endfor
.if empty(PORT_OPTIONS:MBACKTRACE)
	@${REINPLACE_CMD} -e '/IF.*FreeBSD/,/ENDIF.*FreeBSD/d' ${WRKSRC}/src/core/CMakeLists.txt
.endif
.if empty(PORT_OPTIONS:MICON)
	@${REINPLACE_CMD} -e '/^# icon$$/,/^$$/d' ${WRKSRC}/CMakeLists.txt
.endif

post-install:
.if ${PORT_OPTIONS:MMANPAGES} && !defined(MAINTAINER_MODE)
	${INSTALL_MAN} ${WRKDIR}/manpages/man1/weechat.1.gz ${STAGEDIR}${PREFIX}/man/man1
.for f in de fr it ja pl
	@${MKDIR} ${STAGEDIR}${PREFIX}/man/${f}/man1
	${INSTALL_MAN} ${WRKDIR}/manpages/${f}/man1/weechat.1.gz ${STAGEDIR}${PREFIX}/man/${f}/man1
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS} && !defined(MAINTAINER_MODE)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/docs/* ${STAGEDIR}${DOCSDIR}/
.endif
	${LN} -sf ${PREFIX}/bin/weechat ${STAGEDIR}${PREFIX}/bin/weechat-curses

.include <bsd.port.mk>
