# ex:ts=8
# New ports collection makefile for:	Kisomandel
# Date created:			Jun 10, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	kisomandel
PORTVERSION=	0.66
CATEGORIES=	graphics
MASTER_SITES=	http://helsteger.supereva.it/kisomandel/

MAINTAINER=	kde@freebsd.org

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_QT_VER=	2
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-lqt,-lqt2,g" ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e "s,-lqt,-lqt2,g"
	@${REINPLACE_CMD} -e "s,malloc.h,stdlib.h,g" ${WRKSRC}/kisomandel/fractal.cpp

.include <bsd.port.mk>
