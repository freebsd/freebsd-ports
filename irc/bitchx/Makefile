# New ports collection makefile for:	BitchX ircII client
# Date created:		26 Jan 1998
# Whom:			griffin
#
# $FreeBSD$
#

PORTNAME=	BitchX
PORTVERSION=	1.1.0.1
PORTREVISION=	4
CATEGORIES+=	irc
MASTER_SITES=	SF/bitchx/ircii-pana/ircii-pana-1.1
DISTNAME=	ircii-pana-1.1-final

MAINTAINER?=	beech@FreeBSD.org
COMMENT?=	ircII color client with GTK/GNOME support

WRKSRC=		${WRKDIR}/BitchX
USE_PERL5=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--exec-prefix="${PREFIX}/share" \
		--bindir="${PREFIX}/bin" \
		--datadir="${PREFIX}/share" \
		--libdir="${PREFIX}/share"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS}"

MAN1=		BitchX.1

OPTIONS=	ESOUND "With ESOUND support" off \
		GNOME "With GTK/GNOME1 Frontend" off \
		IPV6 "With IPV6 support" off \
		LATIN "Recommended if you are using an ISO-8859-1 display" off \
		PLUGINS "With BitchX Plugins" off \
		SOCKS5 "With SOCKS5 support" off \
		SSL "With SSL" off \
		XMMS "With XMMS plugin" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.if defined(WITH_SSL)
CONFIGURE_ARGS+=--with-ssl
.endif

.if defined(WITH_GNOME)
USE_GNOME=	gnomelibs
CONFIGURE_ARGS+=--with-gtk
CFLAGS+=	-I${LOCALBASE}/include/gnome-1.0/
PLIST_SUB+=	NOGNOME="@comment " GNOME=""
.else
CONFIGURE_ARGS+=--without-gtk
PLIST_SUB+=	GNOME="@comment " NOGNOME=""
.endif

.if (defined(WITH_ESOUND) && defined(WITH_GNOME))
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-sound
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=--enable-ipv6
.endif

.if defined(WITH_SOCKS5)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--with-socks5=${LOCALBASE}
.endif

.if defined(WITH_PLUGINS)
PLUGINS=\
abot,acro,arcfour,autocycle,blowfish,encrypt,fserv,hint,pkga,possum,qbx,qmail,scan,wavplay
CONFIGURE_ARGS+=	--with-plugins=${PLUGINS}
PLIST_SUB+=	PLUGINS=""
.else
CONFIGURE_ARGS+=--without-plugins
PLIST_SUB+=	PLUGINS="@comment "
.endif

.if defined(WITH_XMMS)
PLUGINS=	xmms
PLIST_SUB+=	XMMS=""
.else
PLIST_SUB+=	XMMS="@comment "
.endif
.if (defined(WITH_XMMS) && defined(WITH_PLUGINS))
PLUGINS=\
abot,acro,arcfour,autocycle,blowfish,encrypt,fserv,hint,pkga,possum,qbx,qmail,scan,wavplay,xmms
.endif

.if (defined(WITH_PLUGINS) || defined(WITH_XMMS))
CONFIGURE_ARGS+=	--with-plugins=${PLUGINS}
.endif

pre-patch:
.if defined(WITH_LATIN)
	${REINPLACE_CMD} -e 's|#undef LATIN1|#define LATIN1|g' ${WRKSRC}/include/config.h
.endif
	${REINPLACE_CMD} -e 's|bzip2|true|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/bx/help
	${TAR} --directory ${WRKSRC}/bitchx-docs -cf - . | \
	${TAR} --directory ${PREFIX}/share/bx/help -xf -
.else
	${RMDIR} ${PREFIX}/share/bx/help
.endif
.if defined(WITH_GNOME)
	${STRIP_CMD} ${PREFIX}/bin/gtkBitchX-1.1-final
.else
	${STRIP_CMD} ${PREFIX}/bin/BitchX-1.1-final
	${STRIP_CMD} ${PREFIX}/bin/scr-bx
.endif
	${TOUCH} ${PREFIX}/share/bx/plugins/.placeholder

.include <bsd.port.post.mk>
