# New ports collection makefile for:	xchat
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		xchat
PORTVERSION=		1.6.4
CATEGORIES+=		irc gnome
MASTER_SITES=		http://xchat.org/files/source/1.6/ \
			http://xchat.linuxpower.org/files/source/1.6/

MAINTAINER=		jim@FreeBSD.org
# This port has a slave port japanese/xchat.  Do not carelessly overwrite
# the variables or the targets defined in it.  When you need to, please
# contact its maintainer.

USE_X_PREFIX=		yes
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_PERL5=		yes
USE_IMLIB=		yes
WANT_GNOME=		yes
GNU_CONFIGURE=		yes
# Assign with `+=' for slave ports
CONFIGURE_ARGS+=	--disable-python

.include <bsd.port.pre.mk>

.if defined(WITH_SOCKS)
# Assign with `+=' for slave ports
BUILD_DEPENDS+=		${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--enable-socks
.endif

.if defined(WITH_SSL)
USE_OPENSSL=		YES
CONFIGURE_ARGS+=	--enable-openssl
.endif

.if defined(HAVE_GNOME)
USE_GNOME=		yes
CONFIGURE_ARGS+=	--enable-gnome --enable-panel --enable-gdk-pixbuf
.else
CONFIGURE_ARGS+=	--disable-gnome --disable-gdk-pixbuf
.endif

post-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g'

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing xchat docs in ${PREFIX}/share/doc/xchat"
	@${MKDIR} ${PREFIX}/share/doc/xchat && ${CHMOD} a+rx ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xchat
.endif

.include <bsd.port.post.mk>
