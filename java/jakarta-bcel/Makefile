# Ports collection makefile for:	jakarta-bcel
# Date created:				6 May 2002
# Whom:					des
# $FreeBSD$
#

PORTNAME=	jakarta-bcel
PORTVERSION=	5.0
CATEGORIES=	java devel
MASTER_SITES=	http://jakarta.apache.org/builds/${PORTNAME}/release/v${PORTVERSION}/
DISTNAME=	bcel-${PORTVERSION}

MAINTAINER=	des@FreeBSD.org

NO_BUILD=	yes
USE_JAVA=	1.2+

do-install:
	${INSTALL_DATA} ${WRKSRC}/bcel.jar ${PREFIX}/share/java/classes
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs && ${TAR} -cf - . | ${TAR} -xf - -C ${DOCSDIR})
.endif

.include <bsd.port.mk>
