# New ports collection makefile for:	geos
# Date created:		19 December 2003
# Whom:		 	Leonardo Martins <lmartins@nepe.eee.ufg.br>
#
# $FreeBSD$
#

PORTNAME=	geos
PORTVERSION=	2.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://geos.refractions.net/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	lmartins@nepe.eee.ufg.br
COMMENT=	GEOS implements all the OpenGIS "Simple Features for SQL"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	YES
USE_LIBTOOL_VER=15
USE_BZIP2=	YES

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

INSTALLS_SHLIB=	YES

.include <bsd.port.mk>
