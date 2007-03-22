# New ports collection makefile for:	tinylaf
# Date created:		22 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	tinylaf
PORTVERSION=	1.3.05
CATEGORIES=	devel java
MASTER_SITES=	http://www.muntjak.de/hans/java/tinylaf/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}

MAINTAINER=	nemoliu@gmail.com
COMMENT=	A pluggable Look and Feel for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

JARFILE=	${PORTNAME}.jar

PORTDOCS=	readme.txt
THEMES=		99\ Earth.theme 99\ Lego.theme 99\ Light.theme 99\ Pool.theme	\
		YQ\ Forest.theme YQ\ Golden.theme YQ\ Nightly.theme YQ\ Plastic.theme	\
		YQ\ Silver.theme

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
PLIST_FILES+=	${THEMES:S|^|%%DATADIR%%/|}
PLIST_DIRS+=	%%DATADIR%%

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${JARFILE:S|^|${WRKSRC}/|} ${JAVAJARDIR}
	${INSTALL_DATA} ${THEMES:S|^|${WRKSRC}/|} ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
