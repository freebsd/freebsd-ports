# New ports collection makefile for:	g2
# Version required:	0.30
# Date created:	16 July 1998
# Whom:		Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.3 1998/11/29 12:43:05 asami Exp $
#

DISTNAME=	g2-0.30
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	billf@FreeBSD.org

BUILD_DEPENDS=  ${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CFLAGS="${CFLAGS} -I${PREFIX}/include/gd"

post-patch:

	${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.pre_sed
	${CAT} ${WRKSRC}/Makefile.in.pre_sed | \
	${SED} -e 's#DIR = /usr#DIR = ${PREFIX}#g' \
	>> ${WRKSRC}/Makefile.in

do-build:
	cd ${WRKSRC} ; make depend ; make

.include <bsd.port.mk>
