# New ports collection makefile for:	byacc
# Date created:				28 Jun 2002
# Whom:					David Xu
#
# $FreeBSD$
#

PORTNAME=	byaccj
PORTVERSION=	1.14
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${PORTVERSION}_src

MAINTAINER=	pauls@utdallas.edu
COMMENT=	A java extension of BSD YACC-compatible parser generator

PLIST_FILES=	bin/byaccj
WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-patch:
	@${REINPLACE_CMD} -e 's#<malloc.h>#<stdlib.h>#' ${WRKSRC}/defs.h ${WRKSRC}/*c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yacc ${PREFIX}/bin/byaccj

.include <bsd.port.mk>
