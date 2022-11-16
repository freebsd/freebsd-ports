PORTNAME=	curl
DISTVERSION=	7.86.0
CATEGORIES=	ftp net www
MASTER_SITES=	https://curl.se/download/ \
		https://github.com/curl/curl/releases/download/curl-${PORTVERSION:S|.|_|g}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line tool and library for transferring data with URLs
WWW=		https://curl.se/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool localbase pathfix perl5 shebangfix tar:xz
CPE_VENDOR=	haxx
USE_LDCONFIG=	yes
USE_PERL5=	build

SHEBANG_FILES=	*/*.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror \
		--with-fish-functions-dir=${LOCALBASE}/share/fish/completions \
		--with-zsh-functions-dir=${LOCALBASE}/share/zsh/site-functions
CONFIGURE_ENV=	ac_cv_func_SSLv2_client_method=no \
		LOCALBASE=${LOCALBASE}

INSTALL_TARGET=	install-strip
TEST_TARGET=	test

OPTIONS_DEFINE=		ALTSVC BROTLI CA_BUNDLE COOKIES CURL_DEBUG DEBUG DOCS \
			EXAMPLES IDN IPV6 NTLM PROXY PSL STATIC TLS_SRP ZSTD
OPTIONS_DEFAULT=	ALTSVC CA_BUNDLE COOKIES DICT FTP GOPHER \
			GSSAPI_${${SSL_DEFAULT} == base :?BASE :NONE} HTTP \
			HTTP2 IMAP LIBSSH2 NTLM OPENSSL POP3 PROXY PSL RTSP \
			SMTP STATIC TELNET TFTP THREADED_RESOLVER TLS_SRP
OPTIONS_GROUP=		PROTOCOL
OPTIONS_GROUP_PROTOCOL=	DICT FTP GOPHER HTTP HTTP2 IMAP LDAP LDAPS LIBSSH2 MQTT \
			POP3 RTMP RTSP SMB SMTP TELNET TFTP
OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL WOLFSSL
OPTIONS_SINGLE=		GSSAPI RESOLV
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_SINGLE_RESOLV=	CARES THREADED_RESOLVER
OPTIONS_SUB=		yes

ALTSVC_DESC=		HTTP Alternative Services support
CA_BUNDLE_DESC=		Enable CA bundle for OpenSSL/GnuTLS
COOKIES_DESC=		Cookies support
CURL_DEBUG_DESC=	cURL debug memory tracking
DICT_DESC=		DICT (RFC 2229) support
HTTP2_DESC=		HTTP/2 support (requires HTTP)
HTTP_DESC=		HTTP/HTTPS support
IMAP_DESC=		IMAP/IMAPS support
LIBSSH2_DESC=		SCP/SFTP support via libssh2 (requires OPENSSL)
MQTT_DESC=		MQTT support
POP3_DESC=		POP3/POP3S support
RESOLV_DESC=		DNS resolving options
SMB_DESC=		SMB/CIFS support
SMTP_DESC=		SMTP/SMTPS support
THREADED_RESOLVER_DESC=	Threaded DNS resolver
TLS_SRP_DESC=		TLS-SRP (Secure Remote Password) support

ALTSVC_CONFIGURE_ENABLE=		alt-svc
BROTLI_LIB_DEPENDS=			libbrotlidec.so:archivers/brotli
BROTLI_CONFIGURE_WITH=			brotli
CARES_LIB_DEPENDS=			libcares.so:dns/c-ares
CARES_USES=				pkgconfig
CARES_CONFIGURE_ENABLE=			ares
CA_BUNDLE_RUN_DEPENDS=			${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
CA_BUNDLE_CONFIGURE_WITH=		ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
COOKIES_CONFIGURE_ENABLE=		cookies
CURL_DEBUG_CONFIGURE_ENABLE=		curldebug
DEBUG_CONFIGURE_ENABLE=			debug
DICT_CONFIGURE_ENABLE=			dict
FTP_CONFIGURE_ENABLE=			ftp
GNUTLS_LIB_DEPENDS=			libgnutls.so:security/gnutls \
					libnettle.so:security/nettle
GNUTLS_CONFIGURE_WITH=			gnutls
GOPHER_CONFIGURE_ENABLE=		gopher
GSSAPI_BASE_USES=			gssapi
GSSAPI_BASE_CONFIGURE_ON=		${GSSAPI_CONFIGURE_ARGS} \
					--with-gssapi=${GSSAPIBASEDIR}
GSSAPI_BASE_CPPFLAGS=			${GSSAPICPPFLAGS}
GSSAPI_BASE_LDFLAGS=			${GSSAPILDFLAGS}
GSSAPI_BASE_LIBS=			${GSSAPILIBS}
GSSAPI_HEIMDAL_USES=			gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=		${GSSAPI_CONFIGURE_ARGS} \
					--with-gssapi=${GSSAPIBASEDIR}
GSSAPI_HEIMDAL_CPPFLAGS=		${GSSAPICPPFLAGS}
GSSAPI_HEIMDAL_LDFLAGS=			${GSSAPILDFLAGS}
GSSAPI_HEIMDAL_LIBS=			${GSSAPILIBS}
GSSAPI_MIT_USES=			gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=		${GSSAPI_CONFIGURE_ARGS} \
					--with-gssapi=${GSSAPIBASEDIR}
GSSAPI_MIT_CPPFLAGS=			${GSSAPICPPFLAGS}
GSSAPI_MIT_LDFLAGS=			${GSSAPILDFLAGS}
GSSAPI_MIT_LIBS=			${GSSAPILIBS}
GSSAPI_NONE_CONFIGURE_ON=		--without-gssapi
HTTP2_LIB_DEPENDS=			libnghttp2.so:www/libnghttp2
HTTP2_USES=				pkgconfig
HTTP2_CONFIGURE_WITH=			nghttp2
HTTP_CONFIGURE_ENABLE=			http
IDN_LIB_DEPENDS=			libidn2.so:dns/libidn2
IDN_CONFIGURE_WITH=			libidn2
IMAP_CONFIGURE_ENABLE=			imap
IPV6_CONFIGURE_ENABLE=			ipv6
LDAPS_IMPLIES=				LDAP
LDAPS_CONFIGURE_ENABLE=			ldaps
LDAP_USE=				OPENLDAP=yes
LDAP_CONFIGURE_ENABLE=			ldap
LIBSSH2_IMPLIES=			OPENSSL
LIBSSH2_LIB_DEPENDS=			libssh2.so:security/libssh2
LIBSSH2_CONFIGURE_WITH=			libssh2
MQTT_CONFIGURE_ENABLE=			mqtt
NTLM_CONFIGURE_ENABLE=			ntlm
OPENSSL_USES=				ssl
OPENSSL_CONFIGURE_WITH=			openssl=${OPENSSLBASE}
OPENSSL_CPPFLAGS=			-I${OPENSSLINC}
OPENSSL_LDFLAGS=			-L${OPENSSLLIB}
POP3_CONFIGURE_ENABLE=			pop3
PROXY_IMPLIES=				HTTP
PROXY_CONFIGURE_ENABLE=			proxy
PSL_LIB_DEPENDS=			libpsl.so:dns/libpsl
PSL_CONFIGURE_WITH=			libpsl
RTMP_LIB_DEPENDS=			librtmp.so:multimedia/librtmp
RTMP_USES=				pkgconfig
RTMP_CONFIGURE_WITH=			librtmp
RTSP_IMPLIES=				HTTP
RTSP_CONFIGURE_ENABLE=			rtsp
SMB_CONFIGURE_ENABLE=			smb
SMTP_CONFIGURE_ENABLE=			smtp
STATIC_CONFIGURE_ENABLE=		static
TELNET_CONFIGURE_ENABLE=		telnet
TFTP_CONFIGURE_ENABLE=			tftp
THREADED_RESOLVER_CONFIGURE_ENABLE=	pthreads threaded-resolver
TLS_SRP_CONFIGURE_ENABLE=		tls-srp
WOLFSSL_LIB_DEPENDS=			libwolfssl.so:security/wolfssl
WOLFSSL_CONFIGURE_WITH=			wolfssl
ZSTD_LIB_DEPENDS=			libzstd.so:archivers/zstd
ZSTD_CONFIGURE_WITH=			zstd

.include <bsd.port.pre.mk>

.if !${PORT_OPTIONS:MCA_BUNDLE} && (${PORT_OPTIONS:MGNUTLS} || \
	${PORT_OPTIONS:MOPENSSL})
CONFIGURE_ARGS+=	--with-ca-fallback
.endif

.if ((!${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MOPENSSL}) || \
	(${PORT_OPTIONS:MOPENSSL} && ${SSL_DEFAULT:Mlibressl*})) && \
	${PORT_OPTIONS:MTLS_SRP}
IGNORE=		only supports TLS-SRP with either OpenSSL or GnuTLS
.endif

.if ${PORT_OPTIONS:MLDAPS} && !${PORT_OPTIONS:MGNUTLS} && \
	!${PORT_OPTIONS:MOPENSSL} && !${PORT_OPTIONS:MWOLFSSL}
IGNORE=		only supports LDAPS with SSL
.endif

.if ${PORT_OPTIONS:MGSSAPI_BASE} && exists(${LOCALBASE}/lib/libkrb5support.so)
BROKEN=		the GSSAPI_BASE option is selected, but you have krb5 installed. This is incompatible. In order to build, either select GSSAPI_MIT, or temporarily deinstall krb5 to build curl, or build in poudriere
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s|$$| docs scripts|; /^DIST_SUBDIRS = / s| docs scripts||; /cd docs &&/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\(flags_dbg_off=\)".*"|\1""|; s|\(flags_opt_off=\)".*"|\1""|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|include <gssapi.h>|include <gssapi/gssapi.h>|' ${WRKSRC}/lib/urldata.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/libcurl/libcurl.m4 ${STAGEDIR}${PREFIX}/share/aclocal/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${DOCSDIR}/libcurl/
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} FAQ INSTALL KNOWN_BUGS MAIL-ETIQUETTE THANKS TODO options-in-versions *.md ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/libcurl/ && ${INSTALL_DATA} ABI.md libcurl.m4 *.pl symbols-in-versions ${STAGEDIR}${DOCSDIR}/libcurl/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/docs/examples/ && ${INSTALL_DATA} README.md Makefile.example makefile* *.c *.cpp ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.post.mk>
