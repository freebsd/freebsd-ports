# New ports collection makefile for:	xchat-ja
# Date created:		30 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xchat
PORTVERSION=	1.8.2
CATEGORIES+=	irc gnome ipv6
MASTER_SITES=	http://xchat.org/files/source/1.8/ \
		http://xchat.linuxpower.org/files/source/1.8/

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	msgfmt-new:${PORTSDIR}/devel/gettext-devel
LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv

# <ja-specific>
CATEGORIES:=	japanese ${CATEGORIES}

#EXTRA_PATCHES=	${.CURDIR}/files/patch-aa

CONFIGURE_ARGS=	--enable-japanese-conv

COMMENT=	${.CURDIR}/../../irc/xchat/pkg-comment
DESCR=		${.CURDIR}/../../irc/xchat/pkg-descr
# </ja-specific>

USE_X_PREFIX=		yes
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_PERL5=		yes
USE_IMLIB=		yes
WANT_GNOME=		yes
GNU_CONFIGURE=		yes
# Assign with `+=' for slave ports
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib -lintl -lgiconv" \
			MSGFMT=${LOCALBASE}/bin/msgfmt-new
CONFIGURE_ARGS+=	--disable-python \
			--without-included-gettext \
			--enable-nls \
			--enable-ipv6

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
	@${PERL} -pi \
		-e 's|-lpthread|${PTHREAD_LIBS}|g;' \
		-e 's|DATADIRNAME=lib|DATADIRNAME=share|g;' \
		-e 's|iconv|giconv|;' \
		${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi \
		-e 's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g;' \
		-e 's|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g;'
	@${PERL} -pi -e 's|iconv\.h|giconv.h|;' \
		${WRKSRC}/src/common/jcode.c

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing xchat docs in ${PREFIX}/share/doc/xchat"
	@${MKDIR} ${PREFIX}/share/doc/xchat && ${CHMOD} a+rx ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xchat
.endif

.include <bsd.port.post.mk>
