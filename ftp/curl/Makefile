# New ports collection makefile for:	curl
# Version required:     6.5.2
# Date created:		12 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$

DISTNAME=	curl-6.5.2
CATEGORIES=	ftp www
MASTER_SITES=	http://curl.haxx.nu/stuff/ \
		ftp://ftp.rhrz.uni-bonn.de/pub-koeln/net/inet/ \
		ftp://ftp.win.or.jp/pub/network/www/misc/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/ \
		ftp://ftp.fu-berlin.de/pub/unix/network/curl/ \
		ftp://crydee.sai.msu.ru/zeus/unix/WWW/tools/mirror/

MAINTAINER=	kris@FreeBSD.org

.if defined(USE_SSL)
USE_OPENSSL=   RSA
.endif
 
.include <bsd.port.pre.mk>

.if defined(USE_OPENSSL)
CONFIGURE_ENV+=	CPPFLAGS='-I${OPENSSLINC} -I${OPENSSLINC}/openssl' \
		LDFLAGS='-L${OPENSSLLIB}'
.endif

.if defined(OPENSSL_RSAREF)
CONFIGURE_ENV+= LIBS="-L${OPENSSLLIB} -lcrypto -lRSAglue -L${LOCALBASE}/lib -lrsaref"
.endif

GNU_CONFIGURE=	yes
MAKEFILES=	Makefile src/Makefile

post-configure:

.for x in ${MAKEFILES}
	@ ${MV} ${WRKSRC}/${x} ${WRKSRC}/${x}.pre_sed
	@ ${SED} -e 's#@SHELL@#${SH}#' \
	${WRKSRC}/${x}.pre_sed > ${WRKSRC}/${x}
.endfor

.include <bsd.port.post.mk>
