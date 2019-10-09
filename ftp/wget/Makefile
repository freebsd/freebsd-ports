# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wget
DISTVERSION=	1.20.3
CATEGORIES=	ftp www
MASTER_SITES=	GNU

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP(S) and FTP

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	p5-HTTP-Daemon>=0:www/p5-HTTP-Daemon \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

USES=		charsetfix cpe iconv tar:lz
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
OPTIONS_SUB=	yes

OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=GNUTLS OPENSSL
OPTIONS_DEFINE=	DOCS IDN IPV6 MANPAGES METALINK NLS PCRE PSL
OPTIONS_DEFAULT=IDN MANPAGES OPENSSL

DOCS_DESC=	Install info page
DOCS_CONFIGURE_ENV=	MAKEINFO="${MAKEINFO}"
DOCS_INFO=	wget
DOCS_USES=	makeinfo

IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2 \
			libunistring.so:devel/libunistring
IDN_CPPFLAGS=		-I${LOCALBASE}/include
IDN_LDFLAGS=		-L${LOCALBASE}/lib
IDN_CONFIGURE_ENABLE=	iri
IDN_CONFIGURE_ON=	--with-libidn=${LOCALBASE} \
			--with-libunistring-prefix=${LOCALBASE}
IDN_CONFIGURE_OFF=	--with-included-libunistring

IPV6_CONFIGURE_ENABLE=	ipv6

MANPAGES_CONFIGURE_ENV_OFF=	ac_cv_path_POD2MAN=no
MANPAGES_USE=		PERL5=build
MANPAGES_USES=		perl5

METALINK_CONFIGURE_WITH=metalink
METALINK_LIB_DEPENDS=	libmetalink.so:misc/libmetalink

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LDFLAGS=		-L${LOCALBASE}/lib

PCRE_DESC=		Support Perl regular expressions in addition to POSIX
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CPPFLAGS=		-I${LOCALBASE}/include
PCRE_LDFLAGS=		-L${LOCALBASE}/lib
PCRE_CONFIGURE_ENABLE=	pcre

PSL_CONFIGURE_WITH=	libpsl
PSL_LIB_DEPENDS=	libpsl.so:dns/libpsl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USES+=		ssl
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

TEST_TARGET=	check

# Executed regardless of whether DOCS is ON or OFF.
post-patch:
	${REINPLACE_CMD} -e 's,WGETRC = $$(sysconfdir)/wgetrc,&.sample,' \
		${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's,/usr/local/etc/wgetrc,${PREFIX}/etc/wgetrc,' \
		${WRKSRC}/doc/sample.wgetrc* \
		${WRKSRC}/doc/wget.texi

post-patch-DOCS-off:
	${REINPLACE_CMD} \
		-e '/^all: wget.info/ s,wget.info,,' \
		-e '/^all-am:/ s, $$(INFO_DEPS),,' \
		-e '/^install-data-am:/ s, install-info-am,,' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
