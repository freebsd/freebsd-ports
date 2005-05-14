# New ports collection makefile for:	xchat
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		xchat
PORTVERSION=		1.8.11
PORTREVISION=		5
CATEGORIES+=		irc gnome ipv6
MASTER_SITES=		http://xchat.org/files/source/1.8/ \
			http://xchat.linuxpower.org/files/source/1.8/

MAINTAINER?=		ports@FreeBSD.org
COMMENT=	An X11 IRC client using the GTK+ toolkit, and optionally, GNOME

# This port has a slave port japanese/xchat.  Do not carelessly overwrite
# the variables or the targets defined in it.  When you need to, please
# contact its maintainer.

USE_X_PREFIX=		yes
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_ICONV=		yes
USE_PERL5=		yes
USE_GNOME=		gtk12
WANT_GNOME=		yes
GNU_CONFIGURE=		yes
# Assign with `+=' for slave ports
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib -lintl -liconv"
CONFIGURE_ARGS+=	--without-included-gettext \
			--enable-nls \
			--enable-ipv6 \
			--datadir="${PREFIX}/share" \
			--enable-perl

.if defined(WITH_SSL)
USE_OPENSSL=		YES
CONFIGURE_ARGS+=	--enable-openssl
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--enable-python
.else
CONFIGURE_ARGS+=	--disable-python
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_SOCKS)
# Assign with `+=' for slave ports
BUILD_DEPENDS+=		${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--enable-socks
.endif

.if defined(WITH_TRANSPARENCY)
BUILD_DEPENDS+=		${X11BASE}/bin/gdk-pixbuf-config:${PORTSDIR}/graphics/gdk-pixbuf
CONFIGURE_ARGS+=	--enable-gdk-pixbuf
.endif

.if ${HAVE_GNOME:Mimlib}!=""
USE_GNOME=		imlib
CONFIGURE_ARGS+=	--enable-gnome --enable-panel --enable-gdk-pixbuf \
			--enable-zvt
MAKE_ARGS=		icondir="${PREFIX}/share/gnome/pixmaps" \
			utildir="${PREFIX}/share/gnome/apps/Internet"
.else
CONFIGURE_ARGS+=	--disable-gnome --disable-zvt
.endif

post-patch:
	@${PERL} -pi \
		-e 's|-lpthread|${PTHREAD_LIBS}|g;' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing xchat docs in ${PREFIX}/share/doc/xchat"
	@${MKDIR} ${PREFIX}/share/doc/xchat && ${CHMOD} a+rx ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xchat
.endif

.include <bsd.port.post.mk>
