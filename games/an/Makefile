# New ports collection makefile for:	an
# Date created:		28 Feb 1997
# Whom:			proff
#
# $FreeBSD$
#

PORTNAME=	an
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast anagram generator

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
MAN6=		an.6

post-patch:
	@${REINPLACE_CMD} -e '/<stdint.h>/d' ${WRKSRC}/an.c

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} an.c gan_qsort.c \
		-o ${PORTNAME} ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/an ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/an.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
