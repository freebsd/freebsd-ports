# New ports collection makefile for:	flasm
# Date created:		22 January 2002
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flasm
PORTVERSION=	1.41
CATEGORIES=	graphics
#MASTER_SITES=	http://www.nowrap.de/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
DISTNAME=	flasm141src

MAINTAINER=	kuriyama@FreeBSD.org

USE_ZIP=	YES
USE_GMAKE=	YES
USE_BISON=	YES
NO_WRKSUBDIR=	YES
MAKE_ARGS=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flasm ${PREFIX}/bin

.include <bsd.port.mk>
