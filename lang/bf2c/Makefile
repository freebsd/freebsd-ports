# New ports collection makefile for:    bf2c
# Date created:        4 Sep 2003
# Whom:                r.c.ladan@student.tue.nl
#
# $FreeBSD$
#

PORTNAME=	bf2c
PORTVERSION=	1.2.4
CATEGORIES=	lang
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Optimizing BrainF*ck to C compiler

LICENSE=	BSD

USE_XZ=		yes
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bf2c ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
