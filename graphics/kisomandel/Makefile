# ex:ts=8
# New ports collection makefile for:	Kisomandel
# Date created:			Jun 10, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	kisomandel
PORTVERSION=	0.66
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fractal rendering program with nice 3d-display in realtime

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

PLIST_FILES=	bin/kisomandel
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_QT_VER=	3
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,-lqt,-lqt-mt ${PTHREAD_LIBS},g" ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e "s,-lqt,-lqt-mt ${PTHREAD_LIBS},g"
	@${REINPLACE_CMD} -e "s,malloc.h,stdlib.h,g" ${WRKSRC}/kisomandel/fractal.cpp

.include <bsd.port.post.mk>
