# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.38.0
CATEGORIES=	ftp www
MASTER_SITES=	http://curl.haxx.se/download/ \
		LOCAL/sunpoet

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT?=	Non-interactive tool to get files from FTP, GOPHER, HTTP(S) servers

LICENSE=	MIT

OPTIONS_DEFINE=	CA_BUNDLE COOKIES CURL_DEBUG DEBUG DOCS EXAMPLES HTTP2 IDN IPV6 LDAP LDAPS LIBSSH2 PROXY RTMP TLS_SRP
OPTIONS_RADIO=	GSSAPI RESOLV SSL
OPTIONS_RADIO_GSSAPI=	GSSAPI_BASE HEIMDAL_PORT KRB5_PORT
OPTIONS_RADIO_RESOLV=	CARES THREADED_RESOLVER
OPTIONS_RADIO_SSL=	CYASSL GNUTLS NSS OPENSSL POLARSSL
OPTIONS_DEFAULT=CA_BUNDLE COOKIES GSSAPI_BASE IPV6 OPENSSL PROXY RESOLV THREADED_RESOLVER SSL TLS_SRP
CA_BUNDLE_DESC=	Install CA bundle for OpenSSL
COOKIES_DESC=	Cookies support
CURL_DEBUG_DESC=cURL debug memory tracking
GSSAPI_BASE_DESC=	GSSAPI support via base system
HEIMDAL_PORT_DESC=	GSSAPI support via security/heimdal
KRB5_PORT_DESC=	GSSAPI support via security/krb5
LIBSSH2_DESC=	SCP/SFTP support via libssh2
RESOLV_DESC=	DNS resolving options
THREADED_RESOLVER_DESC=	Threaded DNS resolver
TLS_SRP_DESC=	TLS-SRP (Secure Remote Password) support

CONFIGURE_ARGS+=--disable-werror \
		--enable-imap --enable-pop3 --enable-rtsp --enable-smtp \
		--without-axtls
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
GNU_CONFIGURE=	yes
MAKE_ENV+=	INSTALL_STRIP_FLAG=${STRIP}
USE_PERL5=	build
USES=		libtool:oldver pathfix perl5 tar:lzma

.if !defined(BUILDING_HIPHOP)
USE_LDCONFIG=	yes
USES+=		cpe

PORTDOCS=	*
PORTEXAMPLES=	*

CPE_VENDOR=	haxx

DOCS=		BINDINGS BUGS CONTRIBUTE DISTRO-DILEMMA FAQ FEATURES HISTORY \
		HTTP-COOKIES INSTALL INSTALL.devcpp INTERNALS KNOWN_BUGS \
		LIBCURL-STRUCTS LICENSE-MIXING MAIL-ETIQUETTE MANUAL \
		README.netware README.win32 RELEASE-PROCEDURE RESOURCES \
		SECURITY SSL-PROBLEMS SSLCERTS THANKS TODO \
		TheArtOfHttpScripting VERSIONS curl-config.html \
		curl-config.pdf curl.html curl.pdf index.html \
		mk-ca-bundle.html mk-ca-bundle.pdf
.endif

SLAVEDIRS=	ftp/curl-hiphop

HEIMDAL_HOME?=	${PREFIX}
KRB5_HOME?=	${PREFIX}

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
CYASSL_CONFIGURE_OFF=	--without-cyassl
CYASSL_CONFIGURE_ON=	--with-cyassl=${LOCALBASE}
CYASSL_LIB_DEPENDS=	libcyassl.so:${PORTSDIR}/security/yassl
DEBUG_CONFIGURE_OFF=	--disable-debug
DEBUG_CONFIGURE_ON=	--enable-debug
GNUTLS_CONFIGURE_OFF=	--without-gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls=${LOCALBASE}
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GSSAPI_BASE_CONFIGURE_ON=	--with-gssapi=/usr
GSSAPI_BASE_CPPFLAGS=	-I${INCLUDEDIR}
HEIMDAL_PORT_CONFIGURE_ON=	--with-gssapi=${HEIMDAL_HOME}
HEIMDAL_PORT_CPPFLAGS=	-I${HEIMDAL_HOME}/include
HEIMDAL_PORT_LDFLAGS=	-L${HEIMDAL_HOME}/lib
HEIMDAL_PORT_LIB_DEPENDS=	libgssapi.so.3:${PORTSDIR}/security/heimdal
HTTP2_BUILD_DEPENDS=	nghttp2>=0.4.0:${PORTSDIR}/www/nghttp2
HTTP2_CONFIGURE_OFF=	--without-nghttp2
HTTP2_CONFIGURE_ON=	--with-nghttp2=${LOCALBASE}
HTTP2_LIB_DEPENDS=	libnghttp2.so:${PORTSDIR}/www/nghttp2
HTTP2_RUN_DEPENDS=	nghttp2>=0.4.0:${PORTSDIR}/www/nghttp2
HTTP2_USES=		pkgconfig
IDN_CONFIGURE_OFF=	--without-libidn
IDN_CONFIGURE_ON=	--with-libidn=${LOCALBASE}
IDN_LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn
IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_OFF=	--disable-ipv6
IPV6_CONFIGURE_ON=	--enable-ipv6
KRB5_PORT_CONFIGURE_ON=	--with-gssapi=${KRB5_HOME}
KRB5_PORT_CPPFLAGS=	-I${KRB5_HOME}/include
KRB5_PORT_LDFLAGS=	-L${KRB5_HOME}/lib
KRB5_PORT_LIB_DEPENDS=	libgssapi_krb5.so.2:${PORTSDIR}/security/krb5
LDAP_CONFIGURE_OFF=	--disable-ldap
LDAP_CONFIGURE_ON=	--enable-ldap
LDAP_CPPFLAGS=		-I${LOCALBASE}/include
LDAP_LDFLAGS=		-L${LOCALBASE}/lib
LDAP_USE=		OPENLDAP=yes
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
POLARSSL_LIB_DEPENDS=	libpolarssl.so:${PORTSDIR}/security/polarssl
PROXY_CONFIGURE_OFF=	--disable-proxy
PROXY_CONFIGURE_ON=	--enable-proxy
RTMP_CONFIGURE_OFF=	--without-librtmp
RTMP_CONFIGURE_ON=	--with-librtmp=${LOCALBASE}
RTMP_LIB_DEPENDS=	librtmp.so:${PORTSDIR}/multimedia/librtmp
THREADED_RESOLVER_CONFIGURE_OFF=--disable-threaded-resolver
THREADED_RESOLVER_CONFIGURE_ON=	--enable-threaded-resolver
TLS_SRP_CONFIGURE_OFF=	--disable-tls-srp
TLS_SRP_CONFIGURE_ON=	--enable-tls-srp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCA_BUNDLE} && !${PORT_OPTIONS:MOPENSSL}
IGNORE=		only supports CA bundle with OpenSSL
.endif

.if !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MOPENSSL} && ${PORT_OPTIONS:MTLS_SRP}
IGNORE=		only supports TLS-SRP with either OpenSSL or GnuTLS
.endif

.if !${PORT_OPTIONS:MLDAP} && ${PORT_OPTIONS:MLDAPS}
IGNORE=		only supports LDAPS with LDAP
.endif

.if ${PORT_OPTIONS:MLDAPS} && !${PORT_OPTIONS:MCYASSL} && !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MNSS} && !${PORT_OPTIONS:MOPENSSL} && !${PORT_OPTIONS:MPOLARSSL}
IGNORE=		only supports LDAPS with SSL
.endif

.if ${PORT_OPTIONS:MLIBSSH2} && !${PORT_OPTIONS:MOPENSSL}
IGNORE=		only supports LIBSSH2 with OpenSSL
.endif

.if !${PORT_OPTIONS:MGSSAPI_BASE} && !${PORT_OPTIONS:MHEIMDAL_PORT} && !${PORT_OPTIONS:MKRB5_PORT}
CONFIGURE_ARGS+=--without-gssapi
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s|$$| docs|; /^DIST_SUBDIRS = / s| docs||; /cd docs &&/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\(flags_dbg_off=\)".*"|\1""|; s|\(flags_opt_off=\)".*"|\1""|; s|lib/pkgconfig|libdata/pkgconfig|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|include <gssapi.h>|include <gssapi/gssapi.h>|' ${WRKSRC}/lib/curl_gssapi.h ${WRKSRC}/lib/urldata.h

post-install:
.if !defined(BUILDING_HIPHOP)
	${INSTALL_DATA} ${WRKSRC}/docs/libcurl/libcurl.m4 ${STAGEDIR}${PREFIX}/share/aclocal/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${DOCSDIR}/libcurl/
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/libcurl/ && ${INSTALL_DATA} ABI *.html *.pdf *.m4 ${STAGEDIR}${DOCSDIR}/libcurl/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/docs/examples/ && ${INSTALL_DATA} README Makefile.example makefile* *.c *.cpp ${STAGEDIR}${EXAMPLESDIR}/
.endif

x-regression-test test: build
.if !${PORT_OPTIONS:MPROXY}
	@${ECHO_MSG} "******************************************"
	@${ECHO_MSG} "* You have disabled curl proxy support.  *"
	@${ECHO_MSG} "* Some tests SHALL FAIL!                 *"
	@${ECHO_MSG} "* This is being addressed.               *"
	@${ECHO_MSG} "******************************************"
.endif
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} LC_ALL=C ${MAKE_CMD} test

.include <bsd.port.mk>
