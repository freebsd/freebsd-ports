# New ports collection makefile for:	mp
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mp
PORTVERSION=	3.2.9
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://triptico.dhis.org/download/

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A programming text editor

USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKE_ARGS+=	PREFIX="${PREFIX}"
MAKEFILE=	makefile

post-patch:
	${REINPLACE_CMD} "s/gcc -g -Wall/${CC} ${CFLAGS} -Wall/g; \
		s/mp gmp/mp/g" ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
