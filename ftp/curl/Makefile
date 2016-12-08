# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.51.0
PORTREVISION=	2
CATEGORIES=	ftp www
MASTER_SITES=	http://curl.haxx.se/download/ \
		LOCAL/sunpoet

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT?=	Non-interactive tool to get files from FTP, GOPHER, HTTP(S) servers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	CA_BUNDLE COOKIES CURL_DEBUG DEBUG DOCS EXAMPLES HTTP2 IDN IPV6 LDAP LDAPS LIBSSH2 METALINK PROXY PSL RTMP SMB TLS_SRP
OPTIONS_RADIO=	RESOLV SSL
OPTIONS_SINGLE=	GSSAPI
OPTIONS_RADIO_RESOLV=	CARES THREADED_RESOLVER
OPTIONS_RADIO_SSL=	GNUTLS NSS OPENSSL POLARSSL WOLFSSL
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=	CA_BUNDLE COOKIES OPENSSL PROXY RESOLV THREADED_RESOLVER TLS_SRP
CA_BUNDLE_DESC=		Install CA bundle for OpenSSL
CA_BUNDLE_IMPLIES=	OPENSSL
COOKIES_DESC=		Cookies support
CURL_DEBUG_DESC=	cURL debug memory tracking
LDAPS_IMPLIES=		LDAP
LIBSSH2_DESC=		SCP/SFTP support via libssh2
LIBSSH2_IMPLIES=	OPENSSL
RESOLV_DESC=		DNS resolving options
SMB_DESC=		SMB/CIFS support
THREADED_RESOLVER_DESC=	Threaded DNS resolver
TLS_SRP_DESC=		TLS-SRP (Secure Remote Password) support

.include <${.CURDIR}/../../Mk/bsd.default-versions.mk>

.if ${SSL_DEFAULT} != base
OPTIONS_DEFAULT+=	GSSAPI_NONE
.else
OPTIONS_DEFAULT+=	GSSAPI_BASE
.endif

CONFIGURE_ARGS+=--disable-werror \
		--enable-imap --enable-pop3 --enable-rtsp --enable-smtp \
		--with-zsh-functions-dir=${LOCALBASE}/share/zsh/site-functions \
		--without-axtls
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} \
		ac_cv_func_SSLv2_client_method=no
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_ENV=	${MAKE_ENV} LC_ALL=C
TEST_TARGET=	test
USE_PERL5=	build
USES=		gmake libtool localbase pathfix perl5 shebangfix tar:lzma

.if !defined(BUILDING_HIPHOP)
USE_LDCONFIG=	yes
USES+=		cpe

PORTDOCS=	*
PORTEXAMPLES=	*

CPE_VENDOR=	haxx

DOCS=		BUGS CODE_OF_CONDUCT.md CODE_STYLE.md CONTRIBUTE.md FAQ \
		FEATURES HISTORY.md HTTP-COOKIES.md HTTP2.md INSTALL \
		INTERNALS.md KNOWN_BUGS LICENSE-MIXING.md \
		MAIL-ETIQUETTE MANUAL RELEASE-PROCEDURE RESOURCES ROADMAP.md \
		SECURITY.md SSL-PROBLEMS.md SSLCERTS.md THANKS TODO \
		TheArtOfHttpScripting VERSIONS
.endif

SHEBANG_FILES=	*/*.pl

SLAVEDIRS=	ftp/curl-hiphop

CA_BUNDLE_CONFIGURE_OFF=--without-ca-bundle
CA_BUNDLE_CONFIGURE_ON=	--with-ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
CARES_CONFIGURE_ENABLE=	ares
CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
COOKIES_CONFIGURE_ENABLE=	cookies
CURL_DEBUG_CONFIGURE_ENABLE=	curldebug
DEBUG_CONFIGURE_ENABLE=	debug
GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
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
GSSAPI_MIT_CONFIGURE_ON=--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_CPPFLAGS=	${GSSAPICPPFLAGS}
GSSAPI_MIT_LDFLAGS=	${GSSAPILDFLAGS}
GSSAPI_MIT_LIBS=	${GSSAPILIBS}
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi
HTTP2_BUILD_DEPENDS=	nghttp2>=1.0.0:www/nghttp2
HTTP2_CONFIGURE_WITH=	nghttp2
HTTP2_LIB_DEPENDS=	libnghttp2.so:www/nghttp2
HTTP2_RUN_DEPENDS=	nghttp2>=1.0.0:www/nghttp2
HTTP2_USES=		pkgconfig
IDN_CONFIGURE_WITH=	libidn2
IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_ENABLE=	ipv6
LDAP_CONFIGURE_ENABLE=	ldap
LDAP_USE=		OPENLDAP=yes
LDAPS_CONFIGURE_ENABLE=	ldaps
LIBSSH2_CONFIGURE_WITH=	libssh2
LIBSSH2_LIB_DEPENDS=	libssh2.so:security/libssh2
METALINK_CONFIGURE_WITH=libmetalink
METALINK_LIB_DEPENDS=	libmetalink.so:misc/libmetalink
METALINK_LIBS=		-lcrypto
NSS_CONFIGURE_WITH=	nss
NSS_LIB_DEPENDS=	libnss3.so:security/nss
NSS_USES=		pkgconfig
OPENSSL_CONFIGURE_OFF=	--without-ssl
OPENSSL_CONFIGURE_ON=	--with-ssl=${OPENSSLBASE}
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}
OPENSSL_USES=		ssl
POLARSSL_CONFIGURE_WITH=polarssl
POLARSSL_LIB_DEPENDS=	libmbedtls.so.9:security/polarssl13
PROXY_CONFIGURE_ENABLE=	proxy
PSL_CONFIGURE_WITH=	libpsl
PSL_LIB_DEPENDS=	libpsl.so:dns/libpsl
RTMP_CONFIGURE_WITH=	librtmp
RTMP_LIB_DEPENDS=	librtmp.so:multimedia/librtmp
RTMP_USES=		pkgconfig
SMB_CONFIGURE_ENABLE=	smb
THREADED_RESOLVER_CONFIGURE_ENABLE=	threaded-resolver
TLS_SRP_CONFIGURE_ENABLE=	tls-srp
WOLFSSL_CONFIGURE_WITH=	cyassl
WOLFSSL_LIB_DEPENDS=	libwolfssl.so:security/wolfssl

.include <bsd.port.pre.mk>

.if !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MOPENSSL} && ${PORT_OPTIONS:MTLS_SRP}
IGNORE=		only supports TLS-SRP with either OpenSSL or GnuTLS
.endif

.if ${PORT_OPTIONS:MLDAPS} && !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MNSS} && !${PORT_OPTIONS:MOPENSSL} && !${PORT_OPTIONS:MPOLARSSL} && !${PORT_OPTIONS:MWOLFSSL}
IGNORE=		only supports LDAPS with SSL
.endif

.if ${SSL_DEFAULT:Mlibressl*}
.if ${PORT_OPTIONS:MTLS_SRP}
IGNORE=		unsupported TLS-SRP in LibreSSL
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s|$$| docs scripts|; /^DIST_SUBDIRS = / s| docs scripts||; /cd docs &&/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\(flags_dbg_off=\)".*"|\1""|; s|\(flags_opt_off=\)".*"|\1""|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|include <gssapi.h>|include <gssapi/gssapi.h>|' ${WRKSRC}/lib/curl_gssapi.h ${WRKSRC}/lib/urldata.h

.if !defined(BUILDING_HIPHOP)
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/libcurl/libcurl.m4 ${STAGEDIR}${PREFIX}/share/aclocal/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${DOCSDIR}/libcurl/
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/libcurl/ && ${INSTALL_DATA} ABI *.html *.m4 ${STAGEDIR}${DOCSDIR}/libcurl/

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

.include <bsd.port.post.mk>
