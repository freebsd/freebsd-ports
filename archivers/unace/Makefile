# New ports collection makefile for: unace
# URL: http://members.aol.com/mlemke6413/ace.html
# Date created:         23 February 1999
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

PORTNAME=	unace
PORTVERSION=	1.2b
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=	jonny@jonny.eng.br
COMMENT=	Extract, view & test ACE archives

USE_GMAKE=	yes
ALL_TARGET=	clean unace
PLIST_FILES=	bin/unace

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin

.include <bsd.port.mk>
