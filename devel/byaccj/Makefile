# New ports collection makefile for:	byacc
# Date created:				28 Jun 2002
# Whom:					David Xu
#
# $FreeBSD$
#

PORTNAME=	byaccj
PORTVERSION=	1.1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	byaccj
DISTNAME=	byaccj1.1

MAINTAINER=	davidxu@viatech.com.cn
COMMENT=	A java extension of BSD YACC-compatible parser generator

PLIST_FILES=	bin/byaccj
WRKSRC=		$(WRKDIR)/byaccj1.1/src

post-patch:
	@${REINPLACE_CMD} -e 's#<malloc.h>#<stdlib.h>#' ${WRKSRC}/defs.h ${WRKSRC}/*c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yacc ${PREFIX}/bin/byaccj

.include <bsd.port.mk>
