# New ports collection makefile for:	stamp
# Version required:	0.610
# Date created:	11 August 1998
# Whom:		Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.1.1.1 1998/08/24 01:59:56 steve Exp $
#

DISTNAME=	stamp
PKGNAME=	stamp-0.61
CATEGORIES=	graphics
MASTER_SITES=	http://www.telepath.com/booger/

MAINTAINER=	billf@chc-chimes.com

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

ALL_TARGET=

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	${SED} -e 's#/usr/local#${PREFIX}#' ${WRKSRC}/Makefile.old >> ${WRKSRC}/Makefile

post-install:
	strip ${PREFIX}/bin/stamp

.include <bsd.port.mk>
