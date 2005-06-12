# New ports collection makefile for:	tinylaf
# Date created:		22 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	tinylaf
PORTVERSION=	1.2.1
CATEGORIES=	devel java
MASTER_SITES=	http://www.muntjak.de/hans/java/tinylaf/
DISTNAME=	${PORTNAME}-beta-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A pluggable Look and Feel for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

JARFILE=	${PORTNAME}.jar

PORTDOCS=	readme.txt
THEMES=		98\ Earth.theme 98\ Lego.theme 98\ Light.theme 98\ Pool.theme	\
		XP\ Forest.theme XP\ Golden.theme XP\ Plastic.theme Xp\ Silver.theme

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
