# New ports collection makefile for:	geos
# Date created:		19 December 2003
# Whom:		 	Leonardo Martins <lmartins@nepe.eee.ufg.br>
#
# $FreeBSD$
#

PORTNAME=	geos
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://geos.refractions.net/
DISTNAME=	${PORTNAME}-${PORTVERSION}.0

MAINTAINER=	lmartins@nepe.eee.ufg.br
COMMENT=	GEOS implements all the OpenGIS "Simple Features for SQL"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

INSTALLS_SHLIB=	YES

.include <bsd.port.mk>
