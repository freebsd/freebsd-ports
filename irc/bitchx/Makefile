# New ports collection makefile for:	BitchX ircII client
# Date created:		26 Jan 1998
# Whom:			griffin
#
# $FreeBSD$
#

PORTNAME=       BitchX
PORTVERSION=	1.0c18
CATEGORIES=	irc gnome
MASTER_SITES=	ftp://ftp.bitchx.com/pub/BitchX/source/ \
		ftp://ftp.bitchx.org/pub/BitchX/source/
DISTNAME=	ircii-pana-1.0c18

MAINTAINER=	LoRd_CJ@dalusers.com

WRKSRC=		${WRKDIR}/BitchX

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_ESOUND=	yes
WANT_GNOME=	yes
CONFIGURE_ARGS=	--exec-prefix="${PREFIX}/share" \
		--bindir="${PREFIX}/bin" \
		--datadir="${PREFIX}/share" \
		--libdir="${PREFIX}/share"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		BitchX.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
CONFIGURE_ARGS+=--with-gtk
.else
CONFIGURE_ARGS+=--without-gtk
.endif
.if (defined(HAVE_ESOUND) && defined(HAVE_GNOME))
USE_ESOUND=	yes
CONFIGURE_ARGS+=--enable-sound
.endif
.if defined(WITH_IPV6)
USE_IPV6=	yes
CONFIGURE_ARGS+=--enable-ipv6
.endif
.if defined(WITH_TCL)
BUILD_DEPENDS+=	${LOCALBASE}/include/tcl8.3/tcl.h:${PORTSDIR}/lang/tcl83
CONFIGURE_ARGS+=--with-tcl \
		--with-tcl-includes=${LOCALBASE}/include/tcl8.3 \
		--with-tcl-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3"
post-extract:
	@uudecode -p ${FILESDIR}/tcl-freebsd.o.uu > ${WRKSRC}/source/tcl.o
.endif

.if defined(WITH_SOCKS5)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--with-socks5=${LOCALBASE}
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"
.endif

.if defined(WITH_PLUGINS)
CONFIGURE_ARGS+=--with-plugins
PLIST_SUB+=	PLUGINS:=""
.else
CONFIGURE_ARGS+=--without-plugins
PLIST_SUB+=	PLUGINS:="@comment "
.endif

pre-patch:
.if defined(WITH_LATIN)
	@${PERL} -pi -e "s!#undef LATIN1!#define LATIN1!" ${WRKSRC}/include/config.h
.endif
	@${PERL} -pi -e "s!bzip2!true!g" ${WRKSRC}/Makefile.in

pre-extract:
	@${ECHO} "Available switches:"
	@${ECHO} "-------------------"
.if !defined(WITH_PLUGINS)
	@${ECHO} "WITH_PLUGINS - Build the plugins"
.endif
.if !defined(WITH_LATIN)
	@${ECHO} "WITH_LATIN - Recommended if you are using an ISO-8859-1 display"
.endif
.if !defined(WITH_TCL)
	@${ECHO} "WITH_TCL - Build BitchX with TCL scripting"
.endif
.if !defined(WITH_SOCKS5)
	@${ECHO} "WITH_SOCKS5 - Build BitchX with SOCKS5 support"
.endif
.if !defined(WITH_IPV6)
	@${ECHO} "WITH_IPV6 - Build BitchX with IPV6 support"
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/bx/help
	${MKDIR} ${PREFIX}/share/doc/bitchx
	${TAR} --directory ${WRKSRC}/bitchx-docs -cf - . --exclude CVS | \
	${TAR} --directory ${PREFIX}/share/bx/help -xf -
	${INSTALL_DATA} ${WRKSRC}/doc/bxfaq.html ${PREFIX}/share/doc/bitchx
.endif

.include <bsd.port.post.mk>
