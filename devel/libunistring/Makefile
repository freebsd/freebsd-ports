# New ports collection makefile for:	libunistring
# Date created:				2011-05-17
# Whom:					Takefu
#
# $FreeBSD$
#

PORTNAME=	libunistring
PORTVERSION=	0.9.3
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	takefu@airport.fm
COMMENT=	Unicode string library

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LIB

USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INFO=		${PORTNAME}

pre-patch:
.if defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && ${REINPLACE_CMD}\
	-e 's!install-data-local:!#install-data-local:!' Makefile.in
.endif

.include <bsd.port.mk>
