# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.24.0
PORTREVISION=	4
CATEGORIES=	ftp ipv6 www
MASTER_SITES=	http://curl.haxx.se/download/ \
		LOCAL/sunpoet
EXTRACT_SUFX=	.tar.lzma

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT?=	Non-interactive tool to get files from FTP, GOPHER, HTTP(S) servers

LICENSE=	MIT

OPTIONS_DEFINE=	CARES CURL_DEBUG IPV6 KERBEROS4 LDAP LDAPS LIBIDN LIBSSH2 \
		NTLM CA_BUNDLE PROXY RTMP TRACKMEMORY DOCS EXAMPLES
OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	OPENSSL GNUTLS
OPTIONS_DEFAULT=	CA_BUNDLE PROXY OPENSSL
CURL_DEBUG_DESC=	curl diagnostic output
LIBIDN_DESC=		Internationalized Domain Names via libidn
LIBSSH2_DESC=		SCP/SFTP support via libssh2
NTLM_DESC=		NTLM authentication
CA_BUNDLE_DESC=		Install CA bundle for OpenSSL
TRACKMEMORY_DESC=	curl memory diagnostic output

CONFIGURE_ARGS+=--disable-threaded-resolver --disable-werror \
		--enable-imap --enable-pop3 --enable-rtsp --enable-smtp
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"
GNU_CONFIGURE=	yes
MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
MAKE_JOBS_SAFE=	yes
USES=	pathfix
USE_PERL5_BUILD=	yes
USE_XZ=		yes

.if !defined(BUILDING_HIPHOP)
USE_LDCONFIG=	yes

DOCS=		BINDINGS BUGS CONTRIBUTE DISTRO-DILEMMA FAQ FEATURES HISTORY \
		INSTALL INSTALL.devcpp INTERNALS KNOWN_BUGS LICENSE-MIXING \
		MANUAL README.netware README.win32 RESOURCES SSLCERTS THANKS \
		TODO TheArtOfHttpScripting VERSIONS curl-config.html \
		curl-config.pdf curl.html curl.pdf index.html
MAN1=		curl.1 curl-config.1
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
	       	curl_multi_strerror.3 curl_multi_timeout.3 \
		curl_share_cleanup.3 curl_share_init.3 curl_share_setopt.3 \
		curl_share_strerror.3 curl_slist_append.3 \
		curl_slist_free_all.3 curl_strequal.3 curl_unescape.3 \
		curl_version.3 curl_version_info.3 libcurl.3 libcurl-easy.3 \
		libcurl-errors.3 libcurl-multi.3 libcurl-share.3 \
		libcurl-tutorial.3
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

SHLIB_VER=	6
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBSSH2} && ! ${PORT_OPTIONS:MOPENSSL}
IGNORE=		only supports LIBSSH2 with OpenSSL
.endif

.if ${PORT_OPTIONS:MNTLM} && ! ${PORT_OPTIONS:MOPENSSL}
IGNORE=		only supports NTLM with OpenSSL
.endif

.if ${PORT_OPTIONS:MLDAPS}
.if ! ${PORT_OPTIONS:MLDAP}
IGNORE=		only supports LDAPS with LDAP
.else
.if ! ${PORT_OPTIONS:MOPENSSL} && ! ${PORT_OPTIONS:MGNUTLS}
IGNORE=		only supports LDAPS with SSL (OpenSSL or GNUTLS)
.endif
.endif
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.if ${PORT_OPTIONS:MCA_BUNDLE}
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
CONFIGURE_ARGS+=	--with-ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
.else
CONFIGURE_ARGS+=	--without-ca-bundle
.endif
.else
CONFIGURE_ARGS+=	--without-ssl
.if ${PORT_OPTIONS:MCA_BUNDLE}
IGNORE=			only supports CA bundle with OpenSSL
.endif
.endif

.if ${PORT_OPTIONS:MCARES}
LIB_DEPENDS+=	cares:${PORTSDIR}/dns/c-ares
CONFIGURE_ARGS+=	--enable-ares=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-ares
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-gnutls=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-gnutls
.endif

.if ${PORT_OPTIONS:MOPENSSL} || ${PORT_OPTIONS:MGNUTLS}
PLIST_SUB+=	SSL=""
.else
PLIST_SUB+=	SSL="@comment "
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if exists(/usr/lib/libkrb.a) && ${PORT_OPTIONS:MKERBEROS4}
CONFIGURE_ARGS += --with-krb4=/usr
.else
CONFIGURE_ARGS += --without-krb4
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=	--enable-ldap
USE_OPENLDAP=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.if ${PORT_OPTIONS:MLDAPS}
CONFIGURE_ARGS+=	--enable-ldaps
.else
CONFIGURE_ARGS+=	--disable-ldaps
.endif
.else
CONFIGURE_ARGS+=	--disable-ldap --disable-ldaps
.endif

.if ${PORT_OPTIONS:MLIBIDN}
LIB_DEPENDS+=	idn.17:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-libidn=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

.if ${PORT_OPTIONS:MLIBSSH2}
LIB_DEPENDS+=	ssh2.1:${PORTSDIR}/security/libssh2
CONFIGURE_ARGS+=	--with-libssh2=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libssh2
.endif

.if ${PORT_OPTIONS:MCURL_DEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MRTMP}
LIB_DEPENDS+=	rtmp.0:${PORTSDIR}/multimedia/rtmpdump
CONFIGURE_ARGS+=	--with-librtmp=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-librtmp
.endif

.if ${PORT_OPTIONS:MTRACKMEMORY}
CONFIGURE_ARGS+=	--enable-curldebug
.else
CONFIGURE_ARGS+=	--disable-curldebug
.endif

.if ${PORT_OPTIONS:MNTLM}
CONFIGURE_ARGS+=	--enable-ntlm
.else
CONFIGURE_ARGS+=	--disable-ntlm
.endif

.if ${PORT_OPTIONS:MPROXY}
CONFIGURE_ARGS+=	--enable-proxy
.else
CONFIGURE_ARGS+=	--disable-proxy
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s|$$| docs|; /^DIST_SUBDIRS = / s| docs||; /cd docs &&/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/require "valgrind.pm";/d' ${WRKSRC}/tests/runtests.pl

post-install:
.if !defined(BUILDING_HIPHOP)
	${INSTALL_DATA} ${WRKSRC}/docs/libcurl/libcurl.m4 ${PREFIX}/share/aclocal
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/ ${DOCSDIR}/libcurl/
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
	cd ${WRKSRC}/docs/libcurl/ && ${INSTALL_DATA} ABI *.html *.pdf *.m4 ${DOCSDIR}/libcurl/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/docs/examples/ && ${INSTALL_DATA} README Makefile.example makefile* *.c *.cc ${EXAMPLESDIR}/
.endif
.endif

# Setting LC_ALL=C is a kludge; maybe curl/libcurl shouldn't actually use
# the user's locale when dates are sent to the server.
test:	build
.if ! ${PORT_OPTIONS:MPROXY}
	@${ECHO_MSG} "******************************************"
	@${ECHO_MSG} "* You have disabled curl proxy support.  *"
	@${ECHO_MSG} "* Some tests SHALL FAIL!                 *"
	@${ECHO_MSG} "* This is being addressed.               *"
	@${ECHO_MSG} "******************************************"
.endif
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} LC_ALL=C ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.mk>
