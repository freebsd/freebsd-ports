# $FreeBSD$

PORTNAME=	re
PORTVERSION=	0.4.2
CATEGORIES=	audio devel
MASTER_SITES=	http://www.creytiv.com/pub/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Library for real-time comms with async IO support

USE_LDCONFIG=	yes
USE_GMAKE=	yes

PORTDATA=	re.mk

do-install:
	${MKDIR} ${PREFIX}/include/${PORTNAME} ${DATADIR}
	(cd ${WRKSRC}/include && \
	    ${COPYTREE_SHARE} \*.h ${PREFIX}/include/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/mk/${PORTNAME}.mk ${DATADIR}
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.[sa]* ${PREFIX}/lib

.include <bsd.port.mk>
