# New ports collection makefile for:	geos
# Date created:		19 December 2003
# Whom:		 	Leonardo Martins <lmartins@nepe.eee.ufg.br>
#
# $FreeBSD$
#

PORTNAME=	geos
PORTVERSION=	3.2.2
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/geos/

MAINTAINER=	konstantin@saurbier.net
COMMENT=	GEOS implements all the OpenGIS "Simple Features for SQL"

LICENSE=	LGPL21

USE_AUTOTOOLS=	libtool
USE_BZIP2=	YES
USE_GMAKE=	YES
USE_LDCONFIG=	YES

post-patch:
	@${REINPLACE_CMD} -e '/-release/d' ${WRKSRC}/source/Makefile.in

.include <bsd.port.mk>
