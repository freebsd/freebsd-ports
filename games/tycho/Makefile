# New ports collection makefile for:	tycho
# Date created:				2008-01-16
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	tycho
PORTVERSION=	0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver
DISTNAME=	redcoder

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to gather data (statistics) on Core War warriors

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/tycho \
		bin/tycho-exstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/exstat ${PREFIX}/bin/${PORTNAME}-exstat

.include <bsd.port.mk>
