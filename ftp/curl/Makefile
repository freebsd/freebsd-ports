# New ports collection makefile for:	curl
# Date created:		12 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.19.5
CATEGORIES=	ftp ipv6 www
MASTER_SITES=	http://curl.haxx.se/download/ \
		${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.sunet.se/pub/www/utilities/curl/ \
		ftp://ftp.fu-berlin.de/pub/unix/network/curl/ \
		ftp://crydee.sai.msu.ru/zeus/unix/WWW/tools/mirror/
MASTER_SITE_SUBDIR=	curl

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Non-interactive tool to get files from FTP, GOPHER, HTTP(S) servers

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

PATCH_STRIP=	-p1

MAN1=		curl.1 curl-config.1
MAN3=		curl_easy_cleanup.3 curl_easy_duphandle.3 \
		curl_easy_escape.3 curl_easy_getinfo.3 \
		curl_easy_init.3 curl_easy_pause.3 \
		curl_easy_perform.3 curl_easy_reset.3 curl_easy_recv.3 \
		curl_easy_send.3 \
		curl_easy_setopt.3 curl_easy_strerror.3 curl_easy_unescape.3 \
		curl_escape.3 \
		curl_unescape.3 curl_formadd.3 curl_formget.3 curl_formfree.3 curl_free.3 \
		curl_getdate.3 curl_getenv.3 curl_global_init.3 \
		curl_global_init_mem.3 curl_global_cleanup.3 curl_mprintf.3 \
		curl_multi_add_handle.3 curl_multi_assign.3 curl_multi_cleanup.3 \
		curl_multi_fdset.3 curl_multi_info_read.3 curl_multi_init.3 \
		curl_multi_perform.3 curl_multi_remove_handle.3 \
		curl_multi_setopt.3 curl_multi_socket.3 \
		curl_multi_socket_action.3 \
		curl_multi_strerror.3 curl_multi_timeout.3 \
		curl_share_cleanup.3 curl_share_init.3 \
		curl_share_setopt.3 curl_share_strerror.3 curl_slist_append.3 \
		curl_slist_free_all.3 curl_strequal.3 curl_version.3 \
		curl_version_info.3 libcurl.3 libcurl-easy.3 libcurl-errors.3 \
		libcurl-multi.3 libcurl-share.3 libcurl-tutorial.3

USE_LDCONFIG=	yes
SHLIB_VER=	5

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

USE_PERL5_BUILD=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	CARES "Asynchronous DNS resolution via c-ares" off \
		CURL_DEBUG "Enable curl diagnostic output" off \
		GNUTLS "Use GNU TLS if OPENSSL is OFF" off \
		IPV6 "IPv6 support" on \
		KERBEROS4 "Kerberos 4 authentication" off \
		LDAP "LDAP support" off \
		LDAPS "LDAPS support (requires LDAP and SSL)" off \
		LIBIDN "Internationalized Domain Names via libidn" off \
		LIBSSH2 "SCP/SFTP support via libssh2" off \
		NTLM "NTLM authentication" off \
		OPENSSL "OpenSSL support" on \
		PROXY "Proxy support" on

.include <bsd.port.pre.mk>

.if defined(WITH_GNUTLS) && defined(WITH_OPENSSL)
IGNORE=		may only use GNU TLS if OpenSSL support is disabled
.endif

.if defined(WITH_LIBSSH2) && !defined(WITH_OPENSSL)
IGNORE=		only supports LIBSSH2 with OpenSSL
.endif

.if defined(WITH_NTLM) && !defined(WITH_OPENSSL)
IGNORE=		only supports NTLM with OpenSSL
.endif

.if defined(WITH_CARES) && defined(WITH_IPV6)
IGNORE=		does not support both c-ares and IPv6 - disable one of them
.endif

.if defined(WITH_LDAPS)
.if !defined(WITH_LDAP)
IGNORE=			only supports LDAPS with LDAP
.else
.if !defined(WITH_OPENSSL) && !defined(WITH_GNUTLS)
IGNORE=			only supports LDAPS with SSL (OpenSSL or GNUTLS)
.endif
.endif
.endif

.if !defined(WITHOUT_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE} \
			--with-ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(WITH_CARES)
LIB_DEPENDS+=	cares.1:${PORTSDIR}/dns/c-ares
CONFIGURE_ARGS+=	--enable-ares=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-ares
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-gnutls=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-gnutls
.endif

.if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
PLIST_SUB+=	SSL=""
.else
PLIST_SUB+=	SSL="@comment "
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if exists(/usr/lib/libkrb.a) && defined(WITH_KERBEROS4)
CONFIGURE_ARGS += --with-krb4=/usr
.else
CONFIGURE_ARGS += --without-krb4
.endif

.if defined(WITH_LDAP)
CONFIGURE_ARGS+=	--enable-ldap
USE_OPENLDAP=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
ADDFLAGS=	true
.if defined(WITH_LDAPS)
CONFIGURE_ARGS+=	--enable-ldaps
.else
CONFIGURE_ARGS+=	--disable-ldaps
.endif
.else
CONFIGURE_ARGS+=	--disable-ldap --disable-ldaps
.endif

.if defined(WITH_LIBIDN)
LIB_DEPENDS+=	idn.16:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-libidn=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

.if defined(WITH_LIBSSH2)
LIB_DEPENDS+=	ssh2.1:${PORTSDIR}/security/libssh2
CONFIGURE_ARGS+=	--with-libssh2=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libssh2
.endif

.if defined(WITH_CURL_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_NTLM)
CONFIGURE_ARGS+=	--enable-ntlm
.else
CONFIGURE_ARGS+=	--disable-ntlm
.endif

.if !defined(WITHOUT_PROXY)
CONFIGURE_ARGS+=	--enable-proxy
.else
CONFIGURE_ARGS+=	--disable-proxy
.endif

.if defined(ADDFLAGS)
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
.endif

DOCS=		BINDINGS BUGS CONTRIBUTE DISTRO-DILEMMA FAQ FEATURES \
		HISTORY INSTALL INSTALL.devcpp INTERNALS KNOWN_BUGS \
		LICENSE-MIXING MANUAL README.netware README.win32 RESOURCES \
		SSLCERTS THANKS TODO TheArtOfHttpScripting VERSIONS \
		curl-config.html curl-config.pdf curl.html curl.pdf \
		index.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S@^@${WRKSRC}/docs/@} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/libcurl
	(cd ${WRKSRC}/docs/libcurl && exec ${INSTALL_DATA} ABI *.html *.pdf *.m4 ${DOCSDIR}/libcurl/)
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/examples/README ${WRKSRC}/docs/examples/Makefile.example ${WRKSRC}/docs/examples/makefile* ${WRKSRC}/docs/examples/*.c ${WRKSRC}/docs/examples/*.cc ${EXAMPLESDIR}/
.endif

# Setting LC_ALL=C is a kludge; maybe curl/libcurl shouldn't actually use
# the user's locale when dates are sent to the server.
test:	build
.if defined(WITHOUT_PROXY)
	@${ECHO_MSG} "******************************************"
	@${ECHO_MSG} "* You have disabled curl proxy support.  *"
	@${ECHO_MSG} "* Some tests SHALL FAIL!                 *"
	@${ECHO_MSG} "* This is being addressed.               *"
	@${ECHO_MSG} "******************************************"
.endif
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} LC_ALL=C ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
