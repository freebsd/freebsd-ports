# New ports collection makefile for:   bouncycastle
# Date created:        27 December 2001
# Whom:                rasputin
#
# $FreeBSD$
#

PORTNAME=	bouncycastle
PORTVERSION=	1.30
CATEGORIES=	java security
MASTER_SITES=	http://www.bouncycastle.org/download/ \
		http://polydistortion.net/bc/download/ \
		http://bouncycastle.gva.es/download/
DISTNAME=	crypto-${DISTVERSION}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Cleanroom build of Java Cryptography Extensions

USE_JAVA=	yes
JAVA_VERSION=	1.1+
NO_BUILD=	yes
DISTVERSION=	${PORTVERSION:S/.//}
PLIST_SUB+=	DISTVERSION=${DISTVERSION}

do-install:
	${INSTALL_DATA} ${WRKSRC}/jars/*.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
