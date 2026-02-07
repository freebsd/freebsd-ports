PORTNAME=	xtl
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for R/W structured data to/from an external representation
WWW=		https://xtl.sourceforge.net/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

NO_BUILD=	yes

do-install:
	${CP} -R ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
