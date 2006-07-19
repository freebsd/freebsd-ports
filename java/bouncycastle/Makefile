# New ports collection makefile for:   bouncycastle
# Date created:        27 December 2001
# Whom:                rasputin
#
# $FreeBSD$
#

PORTNAME=	bouncycastle
PORTVERSION=	1.33
CATEGORIES=	java security
MASTER_SITES=	http://www.bouncycastle.org/download/ \
		http://polydistortion.net/bc/download/ \
		http://bouncycastle.gva.es/download/
DISTNAME=	crypto-${DISTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Cleanroom build of Java Cryptography Extensions

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JDKMVERSION=	${JAVA_PORT_VERSION:C/^([0-9])\.([0-9])(.*)$/\1\2/}
DISTVERSION=	${PORTVERSION:S/.//}

JARS=		bcprov bcmail bctsp bcpg bctest

PORTDOCS=	*

do-install:
.for jar in ${JARS}
	${INSTALL_DATA} ${WRKSRC}/jars/${jar}-jdk${JDKMVERSION}-${DISTVERSION}.jar \
	      ${JAVAJARDIR}/${jar}.jar
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
