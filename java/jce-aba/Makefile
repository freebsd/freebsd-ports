# New ports collection makefile for:	Java Cryptograph Extension
# Date created:		2000/02/11
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	jce-aba
PORTVERSION=	1.1
CATEGORIES=	java
MASTER_SITES=	http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd

MAINTAINER=	greg@greg.rim.or.jp

USE_JAVA=	1.1+

RESTRICTED=	"Crypto; export-controlled"
NO_BUILD=	yes
JDKVERSION=	1.1

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib-${JDKVERSION}/jce.zip ${PREFIX}/share/java/classes/
	${MKDIR} ${PREFIX}/share/java/jce-aba
	(cd ${WRKSRC}/docs-${JDKVERSION}; tar cf - .) | (cd ${PREFIX}/share/java/jce-aba ; tar xvf -)

.include <bsd.port.mk>
