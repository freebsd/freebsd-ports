# New ports collection makefile for:	g2
# Version required:	0.30
# Date created:	16 July 1998
# Whom:		Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.1.1.1 1998/08/10 00:12:43 steve Exp $
#

DISTNAME=	g2-0.30
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	billf@chc-chimes.com

BUILD_DEPENDS=  ${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

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
