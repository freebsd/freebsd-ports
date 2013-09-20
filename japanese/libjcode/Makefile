# Created by: Shuichi Tanaka
# $FreeBSD$

PORTNAME=	libjcode
PORTVERSION=	1.00
CATEGORIES=	japanese net
MASTER_SITES=	http://keemun.soraneko.com/gtkicq/archives/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese charset conversion library

MAKE_ARGS=	CC=${CC}
WRKSRC=		${WRKDIR}/${DISTNAME}-${PORTVERSION}

NO_STAGE=	yes
do-install:
	${INSTALL_DATA}	${WRKSRC}/libjcode.a	${PREFIX}/lib/libjcode.a
	${INSTALL_DATA}	${WRKSRC}/jlib.h	${PREFIX}/include/jlib.h

.include <bsd.port.mk>
