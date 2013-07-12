# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.31.0
CATEGORIES=	ftp ipv6 www
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
OPTIONS_DEFAULT=CA_BUNDLE GSSAPI IPV6 OPENSSL PROXY RESOLV THREADED_RESOLVER SSL TLS_SRP
CA_BUNDLE_DESC=	Install CA bundle for OpenSSL
COOKIES_DESC=	Cookies support
CURL_DEBUG_DESC=cURL debug memory tracking
LIBSSH2_DESC=	SCP/SFTP support via libssh2
RESOLV_DESC=	DNS resolving options
SPNEGO_DESC=	SPNEGO (RFC 4178) support
THREADED_RESOLVER_DESC=	Threaded DNS resolver
TLS_SRP_DESC=	TLS-SRP (Secure Remote Password) support

CONFIGURE_ARGS+=--disable-threaded-resolver --disable-werror \
		--enable-imap --enable-pop3 --enable-rtsp --enable-smtp \
		--without-axtls
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_PERL5_BUILD=yes
USE_XZ=		yes
USES=		pathfix

.if !defined(BUILDING_HIPHOP)
USE_LDCONFIG=	yes

DOCS=		BINDINGS BUGS CONTRIBUTE DISTRO-DILEMMA FAQ FEATURES HISTORY \
		INSTALL INSTALL.devcpp INTERNALS KNOWN_BUGS LICENSE-MIXING \
		MANUAL README.netware README.win32 RESOURCES SSLCERTS THANKS \
		TODO TheArtOfHttpScripting VERSIONS curl-config.html \
		curl-config.pdf curl.html curl.pdf index.html
MAN1=		curl.1 curl-config.1 mk-ca-bundle.1
MAN3=		curl_easy_cleanup.3 curl_easy_duphandle.3 curl_easy_escape.3 \
		curl_easy_getinfo.3 curl_easy_init.3 curl_easy_pause.3 \
		curl_easy_perform.3 curl_easy_recv.3 curl_easy_reset.3 \
		curl_easy_send.3 curl_easy_setopt.3 curl_easy_strerror.3 \
		curl_easy_unescape.3 curl_escape.3 curl_formadd.3 \
		curl_formfree.3 curl_formget.3 curl_free.3 curl_getdate.3 \
		curl_getenv.3 curl_global_cleanup.3 curl_global_init.3 \
		curl_global_init_mem.3 curl_mprintf.3 curl_multi_add_handle.3 \
		curl_multi_assign.3 curl_multi_cleanup.3 curl_multi_fdset.3 \
		curl_multi_info_read.3 curl_multi_init.3 curl_multi_perform.3 \
		curl_multi_remove_handle.3 curl_multi_setopt.3 \
		curl_multi_socket.3 curl_multi_socket_action.3 \
	 	curl_multi_strerror.3 curl_multi_timeout.3 curl_multi_wait.3 \
		curl_share_cleanup.3 curl_share_init.3 curl_share_setopt.3 \
		curl_share_strerror.3 curl_slist_append.3 \
		curl_slist_free_all.3 curl_strequal.3 curl_unescape.3 \
		curl_version.3 curl_version_info.3 libcurl.3 libcurl-easy.3 \
		libcurl-errors.3 libcurl-multi.3 libcurl-share.3 \
		libcurl-tutorial.3
.endif

SLAVEDIRS=	ftp/curl-hiphop

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

.if ${PORT_OPTIONS:MLDAPS} && !${PORT_OPTIONS:MSSL}
IGNORE=		only supports LDAPS with SSL
.endif

.if ${PORT_OPTIONS:MLIBSSH2} && !${PORT_OPTIONS:MOPENSSL}
IGNORE=		only supports LIBSSH2 with OpenSSL
.endif

.if ${PORT_OPTIONS:MNTLM} && !${PORT_OPTIONS:MCYASSL} && !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MNSS} && !${PORT_OPTIONS:MOPENSSL} && !${PORT_OPTIONS:MPOLARSSL}
IGNORE=		only supports NTLM with SSL
.endif

.if ${PORT_OPTIONS:MCA_BUNDLE}
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
CONFIGURE_ARGS+=--with-ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
.else
CONFIGURE_ARGS+=--without-ca-bundle
.endif

.if ${PORT_OPTIONS:MCARES}
LIB_DEPENDS+=	cares:${PORTSDIR}/dns/c-ares
CONFIGURE_ARGS+=--enable-ares=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-ares
.endif

.if ${PORT_OPTIONS:MCOOKIES}
CONFIGURE_ARGS+=--enable-cookies
.else
CONFIGURE_ARGS+=--disable-cookies
.endif

.if ${PORT_OPTIONS:MCURL_DEBUG}
CONFIGURE_ARGS+=--enable-curldebug
.else
CONFIGURE_ARGS+=--disable-curldebug
.endif

.if ${PORT_OPTIONS:MCYASSL}
LIB_DEPENDS+=	cyassl:${PORTSDIR}/security/yassl
CONFIGURE_ARGS+=--with-cyassl=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-cyassl
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-gnutls=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-gnutls
.endif

.if ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=--with-gssapi \
		--with-gssapi-includes=${INCLUDEDIR} \
		--with-gssapi-libs=${LIBDIR}
.else
CONFIGURE_ARGS+=--without-gssapi
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=--with-libidn=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-libidn
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=--enable-ldap
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if ${PORT_OPTIONS:MLDAPS}
CONFIGURE_ARGS+=--enable-ldaps
.else
CONFIGURE_ARGS+=--disable-ldaps
.endif

.if ${PORT_OPTIONS:MLIBSSH2}
LIB_DEPENDS+=	ssh2:${PORTSDIR}/security/libssh2
CONFIGURE_ARGS+=--with-libssh2=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-libssh2
.endif

.if ${PORT_OPTIONS:MNSS}
LIB_DEPENDS+=	nss3:${PORTSDIR}/security/nss
CONFIGURE_ARGS+=--with-nss=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-nss
.endif

.if ${PORT_OPTIONS:MNTLM}
CONFIGURE_ARGS+=--enable-ntlm
.else
CONFIGURE_ARGS+=--disable-ntlm
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=--without-ssl
.endif

.if ${PORT_OPTIONS:MPOLARSSL}
LIB_DEPENDS+=	polarssl:${PORTSDIR}/security/polarssl
CONFIGURE_ARGS+=--with-polarssl=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-polarssl
.endif

.if ${PORT_OPTIONS:MPROXY}
CONFIGURE_ARGS+=--enable-proxy
.else
CONFIGURE_ARGS+=--disable-proxy
.endif

.if ${PORT_OPTIONS:MRTMP}
LIB_DEPENDS+=	rtmp:${PORTSDIR}/multimedia/rtmpdump
CONFIGURE_ARGS+=--with-librtmp=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-librtmp
.endif

.if ${PORT_OPTIONS:MSPNEGO}
LIB_DEPENDS+=	fbopenssl:${PORTSDIR}/security/fbopenssl
CPPFLAGS+=	-I${LOCALBASE}/include/fbopenssl
CONFIGURE_ARGS+=--with-spnego=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--without-spnego
.endif

.if ${PORT_OPTIONS:MTHREADED_RESOLVER}
CONFIGURE_ARGS+=--enable-threaded-resolver
.else
CONFIGURE_ARGS+=--disable-threaded-resolver
.endif

.if ${PORT_OPTIONS:MTLS_SRP}
CONFIGURE_ARGS+= --enable-tls-srp
.else
CONFIGURE_ARGS+= --disable-tls-srp
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(flags_dbg_off=\)".*"|\1""|; s|\(flags_opt_off=\)".*"|\1""|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s|$$| docs|; /^DIST_SUBDIRS = / s| docs||; /cd docs &&/d' ${WRKSRC}/Makefile.in

post-install:
.if !defined(BUILDING_HIPHOP)
	${INSTALL_DATA} ${WRKSRC}/docs/libcurl/libcurl.m4 ${PREFIX}/share/aclocal/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/ ${DOCSDIR}/libcurl/
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
	cd ${WRKSRC}/docs/libcurl/ && ${INSTALL_DATA} ABI *.html *.pdf *.m4 ${DOCSDIR}/libcurl/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/docs/examples/ && ${INSTALL_DATA} README Makefile.example makefile* *.c *.cpp ${EXAMPLESDIR}/
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
