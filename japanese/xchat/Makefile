# New ports collection makefile for:	xchat-ja
# Date created:		30 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xchat
PORTVERSION=	1.4.3
PORTREVISION=	2
CATEGORIES=	japanese irc gnome
MASTER_SITES=	http://xchat.org/files/source/1.4/ \
		http://xchat.linuxpower.org/files/source/1.4/

PATCH_SITES=	http://northeye.org/~takuo/xchat-ja/
PATCHFILES=	${PORTNAME}-${PORTVERSION}.ja.3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv
RUN_DEPENDS=	${LOCALBASE}/libexec/iconv/iso-2022-jp.so:${PORTSDIR}/converters/iconv-extra

MASTERDIR=	${.CURDIR}/../../irc/xchat
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-japanese-conv
MAKE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv -lintl"

# begin master part
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_IMLIB=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
# Assign with `+=' for slave ports
CONFIGURE_ARGS+=--disable-python

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CATEGORIES+=	ipv6
CONFIGURE_ARGS+=--enable-ipv6
.endif

.if defined(WITH_SOCKS)
# Assign with `+=' for slave ports
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=--enable-socks
.endif

.if defined(HAVE_GNOME)
USE_GNOME=	yes
CONFIGURE_ARGS+=--enable-gnome --enable-panel --enable-gdk-pixbuf
.else
CONFIGURE_ARGS+=--disable-gnome --disable-gdk-pixbuf
.endif
# end master part

pre-patch:
	${PERL} -i -pe 's/-b&h-lucidatypewriter-medium-r-normal-\*-\*-120-\*-\*-m-\*-\*-\*/$$&,-default-*ng-medium-r-normal--14-*,*/' ${WRKSRC}/src/common/cfgfiles.c

# begin master part
post-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g'
# end master part

pre-build:
	${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in ${WRKSRC}/configure ${WRKSRC}/config.status

# begin master part
post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing xchat docs in ${PREFIX}/share/doc/xchat"
	@${MKDIR} ${PREFIX}/share/doc/xchat && ${CHMOD} a+rx ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xchat
.endif
# end master part

.include <bsd.port.post.mk>
#.include "${MASTERDIR}/Makefile"
