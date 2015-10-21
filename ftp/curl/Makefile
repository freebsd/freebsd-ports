# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.45.0
CATEGORIES=	ftp www
MASTER_SITES=	http://curl.haxx.se/download/ \
		LOCAL/sunpoet

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT?=	Non-interactive tool to get files from FTP, GOPHER, HTTP(S) servers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	CA_BUNDLE COOKIES CURL_DEBUG DEBUG DOCS EXAMPLES HTTP2 IDN IPV6 LDAP LDAPS LIBSSH2 PROXY RTMP TLS_SRP
OPTIONS_RADIO=	RESOLV SSL
OPTIONS_SINGLE=	GSSAPI
OPTIONS_RADIO_RESOLV=	CARES THREADED_RESOLVER
OPTIONS_RADIO_SSL=	GNUTLS NSS OPENSSL POLARSSL WOLFSSL
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=	CA_BUNDLE COOKIES IPV6 OPENSSL PROXY RESOLV THREADED_RESOLVER TLS_SRP
CA_BUNDLE_DESC=		Install CA bundle for OpenSSL
CA_BUNDLE_IMPLIES=	OPENSSL
COOKIES_DESC=		Cookies support
CURL_DEBUG_DESC=	cURL debug memory tracking
GSSAPI_BASE_DESC=	GSSAPI support via base system (Kerberos required)
GSSAPI_HEIMDAL_DESC=	GSSAPI support via security/heimdal
GSSAPI_MIT_DESC=	GSSAPI support via security/krb5
GSSAPI_NONE_DESC=	Disable GSSAPI support
LDAPS_IMPLIES=		LDAP
LIBSSH2_DESC=		SCP/SFTP support via libssh2
LIBSSH2_IMPLIES=	OPENSSL
RESOLV_DESC=		DNS resolving options
THREADED_RESOLVER_DESC=	Threaded DNS resolver
TLS_SRP_DESC=		TLS-SRP (Secure Remote Password) support

LOCALBASE?=	/usr/local
.if defined(WITH_OPENSSL_PORT) || (!defined(WITH_OPENSSL_BASE) && exists(${LOCALBASE}/lib/libcrypto.so))
OPTIONS_DEFAULT+=	GSSAPI_NONE
.else
OPTIONS_DEFAULT+=	GSSAPI_BASE
.endif

CONFIGURE_ARGS+=--disable-werror \
		--enable-imap --enable-pop3 --enable-rtsp --enable-smtp \
		--without-axtls
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} \
		ac_cv_func_SSLv2_client_method=no
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_ENV=	${MAKE_ENV} LC_ALL=C
TEST_TARGET=	test
USE_PERL5=	build
USES=		libtool pathfix perl5 tar:lzma

.if !defined(BUILDING_HIPHOP)
USE_LDCONFIG=	yes
USES+=		cpe

PORTDOCS=	*
PORTEXAMPLES=	*

CPE_VENDOR=	haxx

DOCS=		BINDINGS BUGS CONTRIBUTE DISTRO-DILEMMA FAQ FEATURES HISTORY \
		HTTP-COOKIES HTTP2.md INSTALL INSTALL.devcpp INTERNALS \
		KNOWN_BUGS LICENSE-MIXING MAIL-ETIQUETTE MANUAL \
		RELEASE-PROCEDURE RESOURCES ROADMAP.md SECURITY SSL-PROBLEMS \
		SSLCERTS THANKS TODO TheArtOfHttpScripting VERSIONS \
		curl-config.html curl-config.pdf curl.html curl.pdf index.html \
		mk-ca-bundle.html mk-ca-bundle.pdf
.endif

SLAVEDIRS=	ftp/curl-hiphop

CA_BUNDLE_CONFIGURE_OFF=--without-ca-bundle
CA_BUNDLE_CONFIGURE_ON=	--with-ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
CARES_CONFIGURE_OFF=	--disable-ares
CARES_CONFIGURE_ON=	--enable-ares=${LOCALBASE}
CARES_LIB_DEPENDS=	libcares.so:${PORTSDIR}/dns/c-ares
COOKIES_CONFIGURE_OFF=	--disable-cookies
COOKIES_CONFIGURE_ON=	--enable-cookies
CURL_DEBUG_CONFIGURE_OFF=	--disable-curldebug
CURL_DEBUG_CONFIGURE_ON=--enable-curldebug
DEBUG_CONFIGURE_OFF=	--disable-debug
DEBUG_CONFIGURE_ON=	--enable-debug
GNUTLS_CONFIGURE_OFF=	--without-gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls=${LOCALBASE}
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GSSAPI_BASE_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_BASE_CPPFLAGS=	${GSSAPICPPFLAGS}
GSSAPI_BASE_LDFLAGS=	${GSSAPILDFLAGS}
GSSAPI_BASE_LIBS=	${GSSAPILIBS}
GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_HEIMDAL_CPPFLAGS=${GSSAPICPPFLAGS}
GSSAPI_HEIMDAL_LDFLAGS=	${GSSAPILDFLAGS}
GSSAPI_HEIMDAL_LIBS=	${GSSAPILIBS}
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_CPPFLAGS=	${GSSAPICPPFLAGS}
GSSAPI_MIT_LDFLAGS=	${GSSAPILDFLAGS}
GSSAPI_MIT_LIBS=	${GSSAPILIBS}
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi
HTTP2_BUILD_DEPENDS=	nghttp2>=1.0.0:${PORTSDIR}/www/nghttp2
HTTP2_CONFIGURE_OFF=	--without-nghttp2
HTTP2_CONFIGURE_ON=	--with-nghttp2=${LOCALBASE}
HTTP2_LIB_DEPENDS=	libnghttp2.so:${PORTSDIR}/www/nghttp2
HTTP2_RUN_DEPENDS=	nghttp2>=1.0.0:${PORTSDIR}/www/nghttp2
HTTP2_USES=		pkgconfig
IDN_CONFIGURE_OFF=	--without-libidn
IDN_CONFIGURE_ON=	--with-libidn=${LOCALBASE}
IDN_LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn
IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_OFF=	--disable-ipv6
IPV6_CONFIGURE_ON=	--enable-ipv6
LDAP_CONFIGURE_OFF=	--disable-ldap
LDAP_CONFIGURE_ON=	--enable-ldap
LDAP_USE=		OPENLDAP=yes
LDAP_USES=		localbase
LDAPS_CONFIGURE_OFF=	--disable-ldaps
LDAPS_CONFIGURE_ON=	--enable-ldaps
LIBSSH2_CONFIGURE_OFF=	--without-libssh2
LIBSSH2_CONFIGURE_ON=	--with-libssh2=${LOCALBASE}
LIBSSH2_LIB_DEPENDS=	libssh2.so:${PORTSDIR}/security/libssh2
NSS_CONFIGURE_OFF=	--without-nss
NSS_CONFIGURE_ON=	--with-nss=yes
NSS_LIB_DEPENDS=	libnss3.so:${PORTSDIR}/security/nss
NSS_USES=		pkgconfig
OPENSSL_CONFIGURE_OFF=	--without-ssl
OPENSSL_CONFIGURE_ON=	--with-ssl=${OPENSSLBASE}
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}
OPENSSL_USE=		OPENSSL=yes
POLARSSL_CONFIGURE_OFF=	--without-polarssl
POLARSSL_CONFIGURE_ON=	--with-polarssl=${LOCALBASE}
POLARSSL_LIB_DEPENDS=	libmbedtls.so.9:${PORTSDIR}/security/polarssl13
PROXY_CONFIGURE_OFF=	--disable-proxy
PROXY_CONFIGURE_ON=	--enable-proxy
RTMP_CONFIGURE_OFF=	--without-librtmp
RTMP_CONFIGURE_ON=	--with-librtmp=${LOCALBASE}
RTMP_LIB_DEPENDS=	librtmp.so:${PORTSDIR}/multimedia/librtmp
THREADED_RESOLVER_CONFIGURE_OFF=--disable-threaded-resolver
THREADED_RESOLVER_CONFIGURE_ON=	--enable-threaded-resolver
TLS_SRP_CONFIGURE_OFF=	--disable-tls-srp
TLS_SRP_CONFIGURE_ON=	--enable-tls-srp
WOLFSSL_CONFIGURE_OFF=	--without-cyassl
WOLFSSL_CONFIGURE_ON=	--with-cyassl=${LOCALBASE}
WOLFSSL_LIB_DEPENDS=	libwolfssl.so:${PORTSDIR}/security/wolfssl

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MOPENSSL} && ${PORT_OPTIONS:MTLS_SRP}
IGNORE=		only supports TLS-SRP with either OpenSSL or GnuTLS
.endif

.if ${PORT_OPTIONS:MLDAPS} && !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MNSS} && !${PORT_OPTIONS:MOPENSSL} && !${PORT_OPTIONS:MPOLARSSL} && !${PORT_OPTIONS:MWOLFSSL}
IGNORE=		only supports LDAPS with SSL
.endif

.if ${PORT_OPTIONS:MGSSAPI_BASE} && ${PORT_OPTIONS:MOPENSSL} && (defined(WITH_OPENSSL_PORT) || (!defined(WITH_OPENSSL_BASE) && exists(${LOCALBASE}/lib/libcrypto.so)))
IGNORE=		GSSAPI_BASE is not compatible with OpenSSL from ports. Use other GSSAPI options or OpenSSL from base system
.endif

.if defined(OPENSSL_PORT) && ${OPENSSL_PORT} == "security/libressl"
.if ${PORT_OPTIONS:MGSSAPI_BASE} && ${PORT_OPTIONS:MOPENSSL}
IGNORE=		GSSAPI_BASE is not compatible with LibreSSL. Use other GSSAPI options
.endif
.if ${PORT_OPTIONS:MTLS_SRP}
IGNORE=		unsupported TLS-SRP in LibreSSL
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s|$$| docs|; /^DIST_SUBDIRS = / s| docs||; /cd docs &&/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\(flags_dbg_off=\)".*"|\1""|; s|\(flags_opt_off=\)".*"|\1""|; s|lib/pkgconfig|libdata/pkgconfig|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|include <gssapi.h>|include <gssapi/gssapi.h>|' ${WRKSRC}/lib/curl_gssapi.h ${WRKSRC}/lib/urldata.h
	@${REINPLACE_CMD} -e 's|gss_nt_service_name|GSS_C_NT_HOSTBASED_SERVICE|' ${WRKSRC}/lib/curl_sasl_gssapi.c

.if !defined(BUILDING_HIPHOP)
post-install:
	${LN} -s libcurl.so.4 ${STAGEDIR}${PREFIX}/lib/libcurl.so.7
	${INSTALL_DATA} ${WRKSRC}/docs/libcurl/libcurl.m4 ${STAGEDIR}${PREFIX}/share/aclocal/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${DOCSDIR}/libcurl/
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/libcurl/ && ${INSTALL_DATA} ABI *.html *.m4 *.pdf ${STAGEDIR}${DOCSDIR}/libcurl/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/docs/examples/ && ${INSTALL_DATA} README Makefile.example makefile* *.c *.cpp ${STAGEDIR}${EXAMPLESDIR}/
.endif

pre-test-PROXY-off:
	@${ECHO_MSG} "******************************************"
	@${ECHO_MSG} "* You have disabled curl proxy support.  *"
	@${ECHO_MSG} "* Some tests SHALL FAIL!                 *"
	@${ECHO_MSG} "* This is being addressed.               *"
	@${ECHO_MSG} "******************************************"

.include <bsd.port.mk>
