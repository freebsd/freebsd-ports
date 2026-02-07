PORTNAME=	wget
DISTVERSION=	1.25.0
CATEGORIES=	ftp www
MASTER_SITES=	GNU

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP(S) and FTP
WWW=		https://www.gnu.org/s/wget/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	p5-HTTP-Daemon>=0:www/p5-HTTP-Daemon \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

USES=		charsetfix cpe iconv localbase pkgconfig tar:lz
CPE_VENDOR=	gnu
USE_CSTD=	c99

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=			--disable-pcre

OPTIONS_DEFINE=		DOCS IDN IPV6 MANPAGES METALINK NLS NTLM PCRE2 PSL
OPTIONS_DEFAULT=	IDN MANPAGES NLS OPENSSL
OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_SUB=		yes

DOCS_DESC=	Install info page
NTLM_DESC=	Support NTLM authorization
PCRE2_DESC=	Support PCRE2 style regular expressions

DOCS_USES=		makeinfo
DOCS_CONFIGURE_ENV=	MAKEINFO="${MAKEINFO}"
DOCS_INFO=		wget

IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2 \
			libunistring.so:devel/libunistring
IDN_CONFIGURE_ON=	--with-libidn=${LOCALBASE} \
			--with-libunistring-prefix=${LOCALBASE}
IDN_CONFIGURE_OFF=	--with-included-libunistring
IDN_CONFIGURE_ENABLE=	iri

IPV6_CONFIGURE_ENABLE=	ipv6

MANPAGES_USES=			perl5
MANPAGES_USE=			PERL5=build
MANPAGES_CONFIGURE_ENV_OFF=	ac_cv_path_POD2MAN=no

METALINK_LIB_DEPENDS=		libmetalink.so:misc/libmetalink
METALINK_CONFIGURE_WITH=	metalink

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

NTLM_CONFIGURE_ENABLE=	ntlm

PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE2_CONFIGURE_ENABLE=	pcre2

PSL_LIB_DEPENDS=	libpsl.so:dns/libpsl
PSL_CONFIGURE_WITH=	libpsl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USES+=			ssl
CONFIGURE_ARGS+=	--with-libssl-prefix=${OPENSSLBASE} \
			--with-ssl=openssl
CPPFLAGS+=		-I${OPENSSLINC}
LDFLAGS+=		-L${OPENSSLLIB}
.elif ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=		libgnutls.so:security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
. if ${PORT_OPTIONS:MNTLM}
LIB_DEPENDS+=		libnettle.so:security/nettle
. endif
.else
CONFIGURE_ARGS+=	--without-ssl
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
