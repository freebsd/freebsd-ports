# New ports collection makefile for:	curl
# Date created:		12 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.15.4
CATEGORIES=	ftp ipv6 www
MASTER_SITES=	http://curl.haxx.se/download/ \
		${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.sunet.se/pub/www/utilities/curl/ \
		ftp://ftp.fu-berlin.de/pub/unix/network/curl/ \
		ftp://crydee.sai.msu.ru/zeus/unix/WWW/tools/mirror/
MASTER_SITE_SUBDIR=	curl

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Non-interactive tool to get files from FTP, GOPHER, HTTP(S) servers

MAN1=		curl.1 curl-config.1
MAN3=		curl_easy_cleanup.3 curl_easy_duphandle.3 \
		curl_easy_escape.3 curl_easy_getinfo.3 \
		curl_easy_init.3 curl_easy_perform.3 curl_easy_reset.3 \
		curl_easy_setopt.3 curl_easy_strerror.3 curl_easy_unescape.3 \
		curl_escape.3 \
		curl_unescape.3 curl_formadd.3 curl_formfree.3 curl_free.3 \
		curl_getdate.3 curl_getenv.3 curl_global_init.3 \
		curl_global_init_mem.3 curl_global_cleanup.3 curl_mprintf.3 \
		curl_multi_add_handle.3 curl_multi_cleanup.3 \
		curl_multi_fdset.3 curl_multi_info_read.3 curl_multi_init.3 \
		curl_multi_perform.3 curl_multi_remove_handle.3 \
		curl_multi_setopt.3 curl_multi_socket.3 \
		curl_multi_strerror.3 curl_multi_timeout.3 \
		curl_share_cleanup.3 curl_share_init.3 \
		curl_share_setopt.3 curl_share_strerror.3 curl_slist_append.3 \
		curl_slist_free_all.3 curl_strequal.3 curl_version.3 \
		curl_version_info.3 libcurl.3 libcurl-easy.3 libcurl-errors.3 \
		libcurl-multi.3 libcurl-share.3 libcurl-tutorial.3

INSTALLS_SHLIB=	yes
SHLIB_VER=	3

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--mandir=${PREFIX}/man

OPTIONS=	CURL_DEBUG "Enable curl diagnostic output" off \
		GNUTLS "Use GNU TLS if WITHOUT_SSL is specified" off \
		KERBEROS4 "Kerberos 4 authentication" off \
		LIBIDN "Internationalized Domain Names via libidn" off \
		NTLM "NTLM authentication" off

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_GNUTLS) && !defined(WITHOUT_SSL)
IGNORE=		may only use GNU TLS if WITHOUT_SSL is defined
.endif

.if defined(WITH_NTLM) && defined(WITHOUT_SSL)
IGNORE=		only supports NTLM with OpenSSL
.endif

.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-gnutls=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-gnutls
.endif

.if !defined(WITHOUT_SSL) || defined(WITH_GNUTLS)
PLIST_SUB+=	SSL=""
.else
PLIST_SUB+=	SSL="@comment "
.endif

.if exists(/usr/lib/libkrb.a) && defined(WITH_KERBEROS4)
CONFIGURE_ARGS += --with-krb4=/usr
.else
CONFIGURE_ARGS += --without-krb4
.endif

.if defined(WITH_LIBIDN)
LIB_DEPENDS+=	idn.16:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-libidn=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

.if defined(WITH_CURL_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_NTLM)
CONFIGURE_ARGS+=	--enable-ntlm
.else
CONFIGURE_ARGS+=	--disable-ntlm
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\$$(libdir)/pkgconfig|\$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${DOCSDIR}/
.endif

# Setting LC_ALL=C is a kludge; maybe curl/libcurl shouldn't actually use
# the user's locale when dates are sent to the server.
test:	build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} LC_ALL=C ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
