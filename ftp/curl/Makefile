# New ports collection makefile for:	curl
# Version required:     5.5
# Date created:		12 December 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $Id: Makefile,v 1.1.1.1 1999/02/09 15:31:34 billf Exp $

DISTNAME=       curl-5.5
CATEGORIES=	net www
MASTER_SITES=	http://www.fts.frontec.se/~dast/stuff/ \
		ftp://ftp.rhrz.uni-bonn.de/pub-koeln/net/inet/ \
		ftp://ftp.win.or.jp/pub/network/www/misc/ \
		ftp://ftp.all.de/pub2/unix/network/www/curl/ \
		ftp://crydee.sai.msu.ru/zeus/unix/WWW/tools/mirror/

MAINTAINER=	kkennawa@physics.adelaide.edu.au

.if defined(USE_SSL)
BUILD_DEPENDS=  ssleay:${PORTSDIR}/security/SSLeay
.endif

.if defined(USE_SSL)
CONFIGURE_ENV+=	CPPFLAGS='-I${PREFIX}/include' LDFLAGS='-L${PREFIX}/lib'
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
