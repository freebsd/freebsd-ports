# New ports collection makefile for:	curl
# Date created:		12 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.11.0
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
MAN3=		curl_easy_cleanup.3 curl_easy_duphandle.3 curl_easy_getinfo.3 \
		curl_easy_init.3 curl_easy_perform.3 curl_easy_setopt.3 \
		curl_escape.3 curl_unescape.3 \
		curl_formadd.3 curl_formparse.3 curl_formfree.3 \
		curl_free.3 \
		curl_getdate.3 curl_getenv.3 \
		curl_global_init.3 curl_global_cleanup.3 \
		curl_mprintf.3 \
		curl_multi_add_handle.3 curl_multi_cleanup.3 \
		curl_multi_fdset.3 curl_multi_info_read.3 curl_multi_init.3 \
		curl_multi_perform.3 curl_multi_remove_handle.3 \
		curl_share_cleanup.3 curl_share_init.3 curl_share_setopt.3 \
		curl_slist_append.3 curl_slist_free_all.3 \
		curl_strequal.3 curl_strnequal.3 \
		curl_version.3 curl_version_info.3 \
		libcurl.3 libcurl-easy.3 libcurl-errors.3 libcurl-multi.3 \
		libcurl-share.3

INSTALLS_SHLIB=	yes
SHLIB_VER=	2

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS=	--without-ssl
.endif

.if exists(/usr/lib/libkrb.a) && defined(WITH_KERBEROS4)
CONFIGURE_ARGS += --with-krb4=/usr
.endif

# Note: some of these tests seem to intermittently fail on my system.
# I don't know why they would do that, yet.
test:	build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${DOCSDIR}/ 
.endif

.include <bsd.port.post.mk>
