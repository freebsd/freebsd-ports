# New ports collection makefile for:	geos
# Date created:		19 December 2003
# Whom:		 	Leonardo Martins <lmartins@nepe.eee.ufg.br>
#
# $FreeBSD$
#

PORTNAME=	geos
PORTVERSION=	2.2.3
CATEGORIES=	graphics
MASTER_SITES=	http://geos.refractions.net/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	saurbier@math.uni-bielefeld.de
COMMENT=	GEOS implements all the OpenGIS "Simple Features for SQL"

USE_AUTOTOOLS=	libtool:15
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_BZIP2=	YES
USE_GCC=	3.4+

USE_LDCONFIG=	YES

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
