# ex:ts=8
# Ports collection makefile for:	gnucap
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnucap
PORTVERSION=	0.30
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modelgen/O/modelgen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/O/gnucap ${PREFIX}/bin

.include <bsd.port.mk>
