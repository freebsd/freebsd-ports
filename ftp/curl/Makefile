# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.68.0
CATEGORIES=	ftp net www
MASTER_SITES=	https://curl.haxx.se/download/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line tool and library for transferring data with URLs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	ALTSVC BROTLI CA_BUNDLE COOKIES CURL_DEBUG DEBUG DOCS EXAMPLES IDN IPV6 METALINK NTLM PROXY PSL TLS_SRP
OPTIONS_GROUP=	PROTOCOL
OPTIONS_RADIO=	SSL
OPTIONS_SINGLE=	GSSAPI RESOLV
OPTIONS_GROUP_PROTOCOL=	DICT FTP GOPHER HTTP HTTP2 IMAP LDAP LDAPS LIBSSH2 POP3 RTMP RTSP SMB SMTP TELNET TFTP
OPTIONS_RADIO_SSL=	GNUTLS NSS OPENSSL WOLFSSL
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_SINGLE_RESOLV=	CARES THREADED_RESOLVER
OPTIONS_DEFAULT=	ALTSVC CA_BUNDLE COOKIES GSSAPI_${${SSL_DEFAULT} == base :?BASE :NONE} DICT FTP GOPHER HTTP HTTP2 IMAP NTLM OPENSSL POP3 PROXY RESOLV RTSP SMTP TELNET TFTP THREADED_RESOLVER TLS_SRP
ALTSVC_DESC=		HTTP Alternative Services support
CA_BUNDLE_DESC=		Enable CA bundle for OpenSSL/GnuTLS/mbedTLS
COOKIES_DESC=		Cookies support
CURL_DEBUG_DESC=	cURL debug memory tracking
DICT_DESC=		DICT (RFC 2229) support
HTTP_DESC=		HTTP/HTTPS support
HTTP2_DESC=		HTTP/2 support (requires HTTP)
HTTP2_IMPLIES=		HTTP
IMAP_DESC=		IMAP/IMAPS support
LDAPS_IMPLIES=		LDAP
LIBSSH2_DESC=		SCP/SFTP support via libssh2
LIBSSH2_IMPLIES=	OPENSSL
POP3_DESC=		POP3/POP3S support
PROXY_IMPLIES=		HTTP
RESOLV_DESC=		DNS resolving options
RTSP_IMPLIES=		HTTP
SMB_DESC=		SMB/CIFS support
SMTP_DESC=		SMTP/SMTPS support
THREADED_RESOLVER_DESC=	Threaded DNS resolver
TLS_SRP_DESC=		TLS-SRP (Secure Remote Password) support

USES=		cpe libtool localbase pathfix perl5 shebangfix tar:xz
USE_PERL5=	build

CONFIGURE_ARGS=	--disable-werror \
		--with-fish-functions-dir=${LOCALBASE}/share/fish/completions \
		--with-zsh-functions-dir=${LOCALBASE}/share/zsh/site-functions
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE} \
		ac_cv_func_SSLv2_client_method=no
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	test
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

CPE_VENDOR=	haxx

DOCS=		BUGS FAQ FEATURES INSTALL KNOWN_BUGS MAIL-ETIQUETTE RESOURCES \
		THANKS TODO TheArtOfHttpScripting VERSIONS

SHEBANG_FILES=	*/*.pl

ALTSVC_CONFIGURE_ENABLE=alt-svc
BROTLI_CONFIGURE_WITH=	brotli
BROTLI_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli
CA_BUNDLE_CONFIGURE_WITH=	ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
CARES_CONFIGURE_ENABLE=	ares
CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
CARES_USES=		pkgconfig
COOKIES_CONFIGURE_ENABLE=	cookies
CURL_DEBUG_CONFIGURE_ENABLE=	curldebug
DEBUG_CONFIGURE_ENABLE=	debug
DICT_CONFIGURE_ENABLE=	dict
FTP_CONFIGURE_ENABLE=	ftp
GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libnettle.so:security/nettle
GOPHER_CONFIGURE_ENABLE=gopher
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
HTTP_CONFIGURE_ENABLE=	http
HTTP2_CONFIGURE_WITH=	nghttp2
HTTP2_LIB_DEPENDS=	libnghttp2.so:www/libnghttp2
HTTP2_USES=		pkgconfig
IDN_CONFIGURE_WITH=	libidn2
IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
IMAP_CONFIGURE_ENABLE=	imap
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
NSS_LIB_DEPENDS=	libnss3.so:security/nss \
			libnspr4.so:devel/nspr
NSS_USES=		pkgconfig
NTLM_CPPFLAGS_OFF=	-DCURL_DISABLE_NTLM
OPENSSL_CONFIGURE_WITH=	ssl=${OPENSSLBASE}
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}
OPENSSL_USES=		ssl
POP3_CONFIGURE_ENABLE=	pop3
PROXY_CONFIGURE_ENABLE=	proxy
PSL_CONFIGURE_WITH=	libpsl
PSL_LIB_DEPENDS=	libpsl.so:dns/libpsl
RTMP_CONFIGURE_WITH=	librtmp
RTMP_LIB_DEPENDS=	librtmp.so:multimedia/librtmp
RTMP_USES=		pkgconfig
RTSP_CONFIGURE_ENABLE=	rtsp
SMB_CONFIGURE_ENABLE=	smb
SMTP_CONFIGURE_ENABLE=	smtp
TELNET_CONFIGURE_ENABLE=telnet
TFTP_CONFIGURE_ENABLE=	tftp
THREADED_RESOLVER_CONFIGURE_ENABLE=	pthreads threaded-resolver
TLS_SRP_CONFIGURE_ENABLE=	tls-srp
WOLFSSL_CONFIGURE_WITH=	wolfssl
WOLFSSL_LIB_DEPENDS=	libwolfssl.so:security/wolfssl

.include <bsd.port.pre.mk>

.if ((!${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MOPENSSL}) || (${PORT_OPTIONS:MOPENSSL} && ${SSL_DEFAULT:Mlibressl*})) && ${PORT_OPTIONS:MTLS_SRP}
IGNORE=		only supports TLS-SRP with either OpenSSL or GnuTLS
.endif

.if ${PORT_OPTIONS:MLDAPS} && !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MNSS} && !${PORT_OPTIONS:MOPENSSL} && !${PORT_OPTIONS:MWOLFSSL}
IGNORE=		only supports LDAPS with SSL
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s|$$| docs scripts|; /^DIST_SUBDIRS = / s| docs scripts||; /cd docs &&/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\(flags_dbg_off=\)".*"|\1""|; s|\(flags_opt_off=\)".*"|\1""|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|include <gssapi.h>|include <gssapi/gssapi.h>|' ${WRKSRC}/lib/urldata.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/libcurl/libcurl.m4 ${STAGEDIR}${PREFIX}/share/aclocal/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${DOCSDIR}/libcurl/
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${DOCS} *.md ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/libcurl/ && ${INSTALL_DATA} ABI *.m4 ${STAGEDIR}${DOCSDIR}/libcurl/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/docs/examples/ && ${INSTALL_DATA} README Makefile.example makefile* *.c *.cpp ${STAGEDIR}${EXAMPLESDIR}/

pre-test-PROXY-off:
	@${ECHO_MSG} "******************************************"
	@${ECHO_MSG} "* You have disabled curl proxy support.  *"
	@${ECHO_MSG} "* Some tests SHALL FAIL!                 *"
	@${ECHO_MSG} "* This is being addressed.               *"
	@${ECHO_MSG} "******************************************"

.include <bsd.port.post.mk>
