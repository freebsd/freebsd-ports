# New ports collection makefile for:   nttcp
# Version required:    1.3
# Date created:        11 Nov 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: $
#

DISTNAME=	nttcp-1.4
CATEGORIES=	net benchmarks
MASTER_SITES=	http://users.leo.org/~bartel/nttcp/ \
		http://www.FreeBSD.org/~billf/

MAINTAINER=	billf@FreeBSD.org

ALL_TARGET=	nttcp
MAN1=		nttcp.1
USE_GMAKE=	yes
MAKE_ENV+=	CFLG="${CFLAGS}"

post-patch:

	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.pre_sed
	@${SED} -e 's#-O2#${CFLAGS}#' \
	${WRKSRC}/Makefile.pre_sed > ${WRKSRC}/Makefile

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/nttcp ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/nttcp.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
