# New ports collection makefile for:	curl
# Version required:     6.1
# Date created:		12 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$

DISTNAME=	curl-6.1
CATEGORIES=	ftp www
MASTER_SITES=	http://www.fts.frontec.se/~dast/stuff/ \
		ftp://ftp.rhrz.uni-bonn.de/pub-koeln/net/inet/ \
		ftp://ftp.win.or.jp/pub/network/www/misc/ \
		ftp://crydee.sai.msu.ru/zeus/unix/WWW/tools/mirror/

MAINTAINER=	kris@FreeBSD.org

.if defined(USE_SSL)
LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl \
		ssl.1:${PORTSDIR}/security/openssl
.endif

.if defined(USE_SSL)
CONFIGURE_ENV+=	CPPFLAGS='-I${PREFIX}/include -I${PREFIX}/include/openssl' \
		LDFLAGS='-L${PREFIX}/lib'
.endif

GNU_CONFIGURE=	yes
MAKEFILES=	Makefile src/Makefile

post-configure:

.for x in ${MAKEFILES}
	@ ${MV} ${WRKSRC}/${x} ${WRKSRC}/${x}.pre_sed
	@ ${SED} -e 's#@SHELL@#${SH}#' \
	${WRKSRC}/${x}.pre_sed > ${WRKSRC}/${x}
.endfor

.include <bsd.port.mk>
