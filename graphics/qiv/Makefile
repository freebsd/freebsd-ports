# New ports collection makefile for:   qiv
# Version required:    1.0
# Date created:        25 December 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

DISTNAME=	qiv-1.1
CATEGORIES=	graphics
MASTER_SITES=   http://www.klografx.de/software/files/ \
		ftp://ftp.klografx.de/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=	gdk_imlib.5:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAN1=		qiv.1

post-patch:
	@ ${MV} ${WRKSRC}/qiv.1 ${WRKSRC}/qiv.1.pre_sed
	@ ${SED} -e 's#\/usr\/bin#${PREFIX}/bin#g' \
	${WRKSRC}/qiv.1.pre_sed > ${WRKSRC}/qiv.1
	@ ${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.pre_sed
	@ ${SED} -e 's#RANDOM GETOPT_LONG#RANDOM#' \
	${WRKSRC}/Makefile.pre_sed > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qiv ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/qiv.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
