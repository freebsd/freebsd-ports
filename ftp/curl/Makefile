# New ports collection makefile for:	curl
# Date created:		12 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.7.1
CATEGORIES=	ftp www
MASTER_SITES=	http://curl.haxx.se/download/ \
		http://download.sourceforge.net/curl/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/ \
		ftp://ftp.fu-berlin.de/pub/unix/network/curl/ \
		ftp://crydee.sai.msu.ru/zeus/unix/WWW/tools/mirror/

MAINTAINER=	roam@FreeBSD.org

MAN1=		curl.1
MAN3=		curl_easy_cleanup.3 curl_easy_getinfo.3 curl_easy_init.3 \
		curl_easy_perform.3 curl_easy_setopt.3 \
		curl_escape.3 curl_unescape.3 \
		curl_formparse.3 curl_formfree.3 \
		curl_getdate.3 curl_getenv.3 \
		curl_slist_append.3 curl_slist_free_all.3 \
		curl_version.3

INSTALLS_SHLIB=	yes
SHLIB_VER=	2

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

.if defined(WITH_SSL)
USE_OPENSSL=	YES
.endif

.if exists(/usr/lib/libkrb.a) && defined(WITH_KERBEROS4)
CONFIGURE_ARGS += --with-krb4=/usr
.endif

GNU_CONFIGURE=	yes
USE_AUTOMAKE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILES=	Makefile src/Makefile

post-configure:

.for x in ${MAKEFILES}
	@ ${MV} ${WRKSRC}/${x} ${WRKSRC}/${x}.pre_sed
	@ ${SED} -e 's#@SHELL@#${SH}#' \
	${WRKSRC}/${x}.pre_sed > ${WRKSRC}/${x}
.endfor

.include <bsd.port.mk>
