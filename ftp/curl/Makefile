# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.33.0
CATEGORIES=	ftp www
MASTER_SITES=	http://curl.haxx.se/download/ \
		LOCAL/sunpoet
EXTRACT_SUFX=	.tar.lzma

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT?=	Non-interactive tool to get files from FTP, GOPHER, HTTP(S) servers

LICENSE=	MIT

OPTIONS_DEFINE=	CA_BUNDLE COOKIES CURL_DEBUG DEBUG DOCS EXAMPLES GSSAPI IDN IPV6 LDAP LDAPS LIBSSH2 NTLM PROXY RTMP SPNEGO TLS_SRP
OPTIONS_RADIO=	RESOLV SSL
OPTIONS_RADIO_RESOLV=	CARES THREADED_RESOLVER
OPTIONS_RADIO_SSL=	CYASSL GNUTLS NSS OPENSSL POLARSSL
OPTIONS_DEFAULT=CA_BUNDLE COOKIES GSSAPI IPV6 OPENSSL PROXY RESOLV THREADED_RESOLVER SSL TLS_SRP
CA_BUNDLE_DESC=	Install CA bundle for OpenSSL
COOKIES_DESC=	Cookies support
CURL_DEBUG_DESC=cURL debug memory tracking
LIBSSH2_DESC=	SCP/SFTP support via libssh2
RESOLV_DESC=	DNS resolving options
SPNEGO_DESC=	SPNEGO (RFC 4178) support
THREADED_RESOLVER_DESC=	Threaded DNS resolver
TLS_SRP_DESC=	TLS-SRP (Secure Remote Password) support

CONFIGURE_ARGS+=--disable-werror \
		--enable-imap --enable-pop3 --enable-rtsp --enable-smtp \
		--without-axtls
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"
GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_XZ=		yes
USES=		pathfix perl5

.if !defined(BUILDING_HIPHOP)
USE_LDCONFIG=	yes

DOCS=		BINDINGS BUGS CONTRIBUTE DISTRO-DILEMMA FAQ FEATURES HISTORY \
		INSTALL INSTALL.devcpp INTERNALS KNOWN_BUGS LICENSE-MIXING \
		MANUAL README.netware README.win32 RESOURCES SSLCERTS THANKS \
		TODO TheArtOfHttpScripting VERSIONS curl-config.html \
		curl-config.pdf curl.html curl.pdf index.html
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
CYASSL_CONFIGURE_OFF=	--without-cyassl
CYASSL_CONFIGURE_ON=	--with-cyassl=${LOCALBASE}
CYASSL_LIB_DEPENDS=	libcyassl.so:${PORTSDIR}/security/yassl
DEBUG_CONFIGURE_OFF=	--disable-debug
DEBUG_CONFIGURE_ON=	--enable-debug
GNUTLS_CONFIGURE_OFF=	--without-gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls=${LOCALBASE}
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GSSAPI_CONFIGURE_OFF=	--without-gssapi
GSSAPI_CONFIGURE_ON=	--with-gssapi \
			--with-gssapi-includes=${INCLUDEDIR} \
			--with-gssapi-libs=${LIBDIR}
IDN_CONFIGURE_OFF=	--without-libidn
IDN_CONFIGURE_ON=	--with-libidn=${LOCALBASE}
IDN_LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn
IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_OFF=	--disable-ipv6
IPV6_CONFIGURE_ON=	--enable-ipv6
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
NSS_CONFIGURE_ON=	--with-nss=${LOCALBASE}
NSS_LIB_DEPENDS=	libnss3.so:${PORTSDIR}/security/nss
NTLM_CONFIGURE_OFF=	--disable-ntlm
NTLM_CONFIGURE_ON=	--enable-ntlm
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
SPNEGO_CONFIGURE_OFF=	--without-spnego
SPNEGO_CONFIGURE_ON=	--with-spnego=${LOCALBASE}/lib
SPNEGO_CPPFLAGS=	-I${LOCALBASE}/include/fbopenssl
SPNEGO_LIB_DEPENDS=	libfbopenssl.so:${PORTSDIR}/security/fbopenssl
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

.if ${PORT_OPTIONS:MNTLM} && !${PORT_OPTIONS:MCYASSL} && !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MNSS} && !${PORT_OPTIONS:MOPENSSL} && !${PORT_OPTIONS:MPOLARSSL}
IGNORE=		only supports NTLM with SSL
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(flags_dbg_off=\)".*"|\1""|; s|\(flags_opt_off=\)".*"|\1""|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s|$$| docs|; /^DIST_SUBDIRS = / s| docs||; /cd docs &&/d' ${WRKSRC}/Makefile.in

post-install:
.if !defined(BUILDING_HIPHOP)
	${INSTALL_DATA} ${WRKSRC}/docs/libcurl/libcurl.m4 ${STAGEDIR}${PREFIX}/share/aclocal/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${DOCSDIR}/libcurl/
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/libcurl/ && ${INSTALL_DATA} ABI *.html *.pdf *.m4 ${STAGEDIR}${DOCSDIR}/libcurl/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/docs/examples/ && ${INSTALL_DATA} README Makefile.example makefile* *.c *.cpp ${STAGEDIR}${EXAMPLESDIR}/
.endif
.endif

# Setting LC_ALL=C is a kludge; maybe curl/libcurl shouldn't actually use
# the user's locale when dates are sent to the server.
regression-test test: build
.if !${PORT_OPTIONS:MPROXY}
	@${ECHO_MSG} "******************************************"
	@${ECHO_MSG} "* You have disabled curl proxy support.  *"
	@${ECHO_MSG} "* Some tests SHALL FAIL!                 *"
	@${ECHO_MSG} "* This is being addressed.               *"
	@${ECHO_MSG} "******************************************"
.endif
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} LC_ALL=C ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.mk>
