# New ports collection makefile for:	glass
# Date created:				Thu Aug 23 09:10:22 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	glass
PORTVERSION=	1.1.5
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org

USE_MESA=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/*.c

do-install:
	@${INSTALL_DATA} ${WRKSRC}/libglass.so.1 ${PREFIX}/lib
	@${LN} -sf ${PREFIX}/lib/libglass.so.1 ${PREFIX}/lib/libglass.so
	@${INSTALL_DATA} ${WRKSRC}/glass.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/glass_types.h ${PREFIX}/include

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../docs/*.html \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
