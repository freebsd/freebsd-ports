# New ports collection makefile for:	NetRexx
# Date created:		Feb 8, 1999
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	netrexx
PORTVERSION=	1.160
CATEGORIES=	java lang
MASTER_SITES=	http://www.ibm.com/technology/NetRexx/
DISTNAME=	NetRexx
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk

NO_BUILD=	yes
# pkg/PLIST depends on the JDK_VERSION
JDK_VERSION?=	1.1.8
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}

do-install:
	-${MV} ${WRKSRC}/nrtools.tar.Z ${WRKSRC}/.foo.Z
	uncompress -c ${WRKSRC}/.foo.Z | \
	    tar -xvf - -C ${PREFIX}/jdk${JDK_VERSION}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/NetRexx
	${CP} -R ${WRKSRC}/* ${PREFIX}/share/doc/NetRexx/
.endif

.include <bsd.port.mk>
