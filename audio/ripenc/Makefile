# New ports collection makefile for: ripenc
# URL: http://www.asde.com/~mjparme/index.htm
# Version required:     0.7
# Date created:         28 February 1999
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $Id: Makefile,v 1.1.1.1 1999/04/27 12:57:55 taoka Exp $
#

DISTNAME=	ripenc0.7
PKGNAME=	ripenc-0.7
CATEGORIES=	audio
MASTER_SITES=	http://www.asde.com/~mjparme/

MAINTAINER=	jonny@jonny.eng.br

WRKSRC=		${WRKDIR}/ripenc

NO_BUILD=	Shell Script

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ripenc ${PREFIX}/bin

.include <bsd.port.mk>
