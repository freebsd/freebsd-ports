# New ports collection makefile for:	curl
# Date created:		12 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.2.1
CATEGORIES=	ftp www
MASTER_SITES=	http://curl.haxx.nu/stuff/ \
		ftp://ftp.rhrz.uni-bonn.de/pub-koeln/net/inet/ \
		ftp://ftp.win.or.jp/pub/network/www/misc/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/ \
		ftp://ftp.fu-berlin.de/pub/unix/network/curl/ \
		ftp://crydee.sai.msu.ru/zeus/unix/WWW/tools/mirror/

MAINTAINER=	kris@FreeBSD.org

MAN1=		curl.1
MAN3=		curl_easy_cleanup.3 curl_easy_init.3 curl_easy_perform.3 curl_easy_setopt.3 curl_formparse.3 curl_getdate.3 curl_getenv.3 curl_slist_append.3 curl_slist_free_all.3 curl_version.3

INSTALLS_SHLIB=	yes
SHLIB_VER=	0

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
USE_OPENSSL=	YES
CONFIGURE_ENV+=	CPPFLAGS='-I${OPENSSLINC} -I${OPENSSLINC}/openssl' \
		LDFLAGS='-L${OPENSSLLIB}'
.endif

GNU_CONFIGURE=	yes
USE_AUTOMAKE=	yes
MAKEFILES=	Makefile src/Makefile

post-configure:

.for x in ${MAKEFILES}
	@ ${MV} ${WRKSRC}/${x} ${WRKSRC}/${x}.pre_sed
	@ ${SED} -e 's#@SHELL@#${SH}#' \
	${WRKSRC}/${x}.pre_sed > ${WRKSRC}/${x}
.endfor

.include <bsd.port.post.mk>
