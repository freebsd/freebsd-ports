# New ports collection makefile for: accrete
# Date created:        2003-6-2
# Whom:                chuck@pkix.net
#
# $FreeBSD$

PORTNAME=	accrete
PORTVERSION=	1.0
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	chuck@pkix.net
COMMENT=	Accrete is a physical simulation of solar system planet formation

PLIST_FILES=	bin/accrete
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
	s|%%CC%%|${CC}|g ; \
	s|%%CFLAGS%%|${CFLAGS}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
