# New ports collection makefile for:	jad
# Date created:				27 September 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	jad
PORTVERSION=	1.5.7f
CATEGORIES=	java
MASTER_SITES=	http://www.geocities.com/SiliconValley/Bridge/8617/jad/freebsd/
DISTNAME=	jadfb157

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jad ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/doc/jad
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/jad/

.include <bsd.port.mk>
