# New ports collection makefile for:	BitchX ircII client
# Date created:		26 Jan 1998
# Whom:			griffin
#
# $FreeBSD$
#

PORTNAME=	BitchX
PORTVERSION=	1.1
CATEGORIES+=	irc
MASTER_SITES=	ftp://ftp.bitchx.org/pub/BitchX/source/ \
		ftp://ftp.cyberpunkz.org/pub/BitchX/source/ \
		ftp://ftp.cyberpunkz.org/pub/BitchX/tcl-o/:tcl
DISTFILES=	ircii-pana-${PORTVERSION}-final${EXTRACT_SUFX}
EXTRACT_ONLY=	ircii-pana-${PORTVERSION}-final${EXTRACT_SUFX}

MAINTAINER?=	arved@FreeBSD.org
COMMENT?=	"An alternative ircII color client with optional GTK/GNOME support"

WRKSRC=		${WRKDIR}/BitchX
USE_PERL5=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--exec-prefix="${PREFIX}/share" \
		--bindir="${PREFIX}/bin" \
		--datadir="${PREFIX}/share" \
		--libdir="${PREFIX}/share" \
		--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		BitchX.1

#OPTIONS=	ESOND "With ESOUND support" off \
#		GNOME "With GTK/GNOME1 Frontend" off \
#		IPV6 "With IPV6 support" off \
#		LATIN "Recommended if you are using an ISO-8859-1 display" off \
#		PLUGINS "With BitchX Plugins" off \
#		SOCKS5 "With SOCKS5 support" off \
#		SSL "With SSL" off \
#		TCL "With TCL support" off \
#		XMMS "With XMMS plugin" off

.if defined(WITH_GNOME)
USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs
CONFIGURE_ARGS+=--with-gtk
CFLAGS+=	-I${X11BASE}/include/gnome-1.0/
PLIST_SUB+=	NOGNOME:="@comment " GNOME:=""
.else
CONFIGURE_ARGS+=--without-gtk
PLIST_SUB+=	GNOME:="@comment " NOGNOME:=""
.endif
.if (defined(WITH_ESOUND) && defined(WITH_GNOME))
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-sound
.endif

.if defined(WITH_SSL)
USE_OPENSSL=		yes
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_TCL)
DISTFILES+=	freebsd4-tcl83-bx1.0c19-tcl.o:tcl
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
.endif

.if defined(WITH_IPV6)
USE_AUTOCONF_VER=253
.endif

.if ${ARCH} == "alpha" || ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN="Dumps core on startup"
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=--enable-ipv6
.endif

.if defined(WITH_TCL)
BUILD_DEPENDS+=	${LOCALBASE}/include/tcl8.3/tcl.h:${PORTSDIR}/lang/tcl83
CONFIGURE_ARGS+=--with-tcl \
		--with-tcl-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3"
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3
ONLY_FOR_ARCHS=	i386
.if ${OSVERSION} > 500017
BROKEN=	"WITH_TCL is not available on 5.X, try to install without TCL"
.endif
.endif

.if defined(WITH_SOCKS5)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--with-socks5=${LOCALBASE}
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"
.endif

.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--with-ssl
.endif

.if defined(WITH_PLUGINS)
PLUGINS=	abot,acro,aim,arcfour,autocycle,blowfish,cavlink,encrypt,fserv,hint,identd,nap,pkga,possum,qbx,qmail,scan,wavplay
PLIST_SUB+=	PLUGINS:=""
.else
CONFIGURE_ARGS+=--without-plugins
PLIST_SUB+=	PLUGINS:="@comment "
.endif

.if defined(WITH_XMMS)
PLUGINS=	xmms
PLIST_SUB+=	XMMS:=""
.else
PLIST_SUB+=	XMMS:="@comment "
.endif
.if (defined(WITH_XMMS) && defined(WITH_PLUGINS))
PLUGINS=	abot,acro,aim,arcfour,autocycle,blowfish,cavlink,encrypt,fserv,hint,identd,nap,pkga,possum,qbx,qmail,scan,wavplay,xmms
.endif

.if (defined(WITH_PLUGINS) || defined(WITH_XMMS))
INSTALLS_SHLIB=		yes
CONFIGURE_ARGS+=	--with-plugins=${PLUGINS}
.endif
CONFIGURE_ENV+=		CFLAGS="${CFLAGS}"

.if defined(WITH_TCL)

pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	${DIALOG} --yesno "SECURITY NOTICE: TCL support is only \
	available by linking a precompiled binary object into the Application. \
	Do you really want to proceed building BitchX with TCL support?" 7 70 || ${FALSE}
.endif # BATCH

.endif # WITH_TCL

pre-extract:
	@${ECHO_CMD} "Available switches:"
	@${ECHO_CMD} "-------------------"
.if !defined (WITH_XMMS)
	@${ECHO_CMD} "WITH_XMMS    - Building BitchX with XMMS-Plugin"
.endif
.if !defined(WITH_PLUGINS)
	@${ECHO_CMD} "WITH_PLUGINS - Building BitchX with some other plugins"
.endif
.if !defined(WITH_LATIN)
	@${ECHO_CMD} "WITH_LATIN   - Recommended if you are using an ISO-8859-1 display"
.endif
.if !defined(WITH_TCL)
	@${ECHO_CMD} "WITH_TCL     - Build BitchX with TCL scripting"
.endif
.if !defined(WITH_SOCKS5)
	@${ECHO_CMD} "WITH_SOCKS5  - Build BitchX with SOCKS5 support"
.endif
.if !defined(WITH_SSL)
	@${ECHO_CMD} "WITH_SSL	   - Build BitchX with SSL support"
.endif
.if !defined(WITH_IPV6)
	@${ECHO_CMD} "WITH_IPV6    - Build BitchX with IPV6 support"
	@${ECHO_CMD} "               (Please Note: /detach crashes BitchX with IPv6)"
.endif
.if !defined(WITH_GNOME)
	@${ECHO_CMD} "WITH_GNOME   - Build BitchX with Gtk-Frontend"
.endif

.if defined(WITH_TCL)

post-extract:
	@${CP} ${DISTDIR}/freebsd4-tcl83-bx1.0c19-tcl.o ${WRKSRC}/source/tcl.o

.endif

pre-patch:
.if defined(WITH_LATIN)
	${REINPLACE_CMD} -e 's|#undef LATIN1|#define LATIN1|g' ${WRKSRC}/include/config.h
.endif
	${REINPLACE_CMD} -e 's|bzip2|true|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/bx/help
	${MKDIR} ${PREFIX}/share/doc/bitchx
	${TAR} --directory ${WRKSRC}/bitchx-docs -cf - . --exclude CVS | \
	${TAR} --directory ${PREFIX}/share/bx/help -xf -
.else
	${RMDIR} ${PREFIX}/share/bx/help
.endif
.if defined(WITH_GNOME)
	${STRIP_CMD} ${PREFIX}/bin/gtkBitchX-${PORTVERSION}-final
.else
	${STRIP_CMD} ${PREFIX}/bin/BitchX-${PORTVERSION}-final
	${STRIP_CMD} ${PREFIX}/bin/scr-bx
.endif

.include <bsd.port.post.mk>
