# New ports collection makefile for:   qiv
# Version required:    1.0
# Date created:        25 December 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: $
#

DISTNAME=	qiv-1.0
CATEGORIES=	graphics
MASTER_SITES=   http://www.klografx.de/software/files/ \
		ftp://ftp.klografx.de/pub/ \
		http://www.idnet.de/~AdamK/
EXTRACT_SUFX=	.tgz

MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk11
BUILD_DEPENDS=	imlib-config:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
MAN1=		qiv.1

post-patch:

	@ ${MV} ${WRKSRC}/qiv.1 ${WRKSRC}/qiv.1.pre_sed
	@ ${SED} -e 's#\/usr\/bin#${PREFIX}/bin#g' \
	${WRKSRC}/qiv.1.pre_sed > ${WRKSRC}/qiv.1

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/qiv ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/qiv.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
