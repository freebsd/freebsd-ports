# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wget
DISTVERSION=	1.18
PORTREVISION=	2
CATEGORIES=	ftp www ipv6
MASTER_SITES=	GNU

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP(S) and FTP

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix cpe gmake iconv makeinfo perl5 tar:xz
USE_PERL5=	build
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
OPTIONS_SUB=	yes

OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=GNUTLS OPENSSL
OPTIONS_DEFINE=	IPV6 NLS IDN METALINK PCRE PSL
OPTIONS_DEFAULT=OPENSSL IDN

PCRE_DESC=	Support Perl regular expressions in addition to POSIX

IPV6_CONFIGURE_ENABLE=	ipv6

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LDFLAGS=		-L${LOCALBASE}/lib

IDN_USES=		iconv
IDN_LIB_DEPENDS=	libidn.so:dns/libidn
IDN_CONFIGURE_ENABLE=	iri
IDN_CONFIGURE_ON=	--with-libidn=${LOCALBASE}

METALINK_CONFIGURE_WITH=metalink
METALINK_LIB_DEPENDS=	libmetalink.so:misc/libmetalink

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CPPFLAGS=		-I${LOCALBASE}/include
PCRE_LDFLAGS=		-L${LOCALBASE}/lib
PCRE_CONFIGURE_ENV_OFF=	ac_cv_header_pcre_h=no

PSL_CONFIGURE_WITH=	libpsl
PSL_LIB_DEPENDS=	libpsl.so:dns/libpsl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ssl=openssl --with-libssl-prefix=${OPENSSLBASE}
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.elif ${PORT_OPTIONS:MGNUTLS}
USES+=		pkgconfig
LIB_DEPENDS+=	libgnutls.so:security/gnutls
CONFIGURE_ARGS+=--with-ssl=gnutls
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--without-ssl
.endif

INFO=		wget

# eliminate gmakism
post-patch:
	${REINPLACE_CMD} -e 's,$$<,$$(srcdir)/wget.texi,' \
			 -e 's,WGETRC = $$(sysconfdir)/wgetrc,&.sample,' \
		${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's,/usr/local/etc/wgetrc,${PREFIX}/etc/wgetrc,' \
			 -e 's,@file{},@file{${PREFIX}},' \
		${WRKSRC}/doc/sample.wgetrc* ${WRKSRC}/doc/wget.texi
	${REINPLACE_CMD} -e '/ac_fn_c_check_header_mongrel.*uuid\/uuid.h/ d' \
		${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENSSL} && ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
