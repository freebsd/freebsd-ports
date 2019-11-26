# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	tinylaf
DISTVERSION=	1_4_0
CATEGORIES=	devel java
MASTER_SITES=	http://www.muntjak.de/hans/java/tinylaf/

MAINTAINER=	ayu@commun.jp
COMMENT=	Pluggable Look and Feel for Java

OPTIONS_DEFINE=	DOCS

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes

JARFILE=	${PORTNAME}.jar tinycp.jar
PORTDOCS=	readme.html gpl.txt lgpl.txt
PLIST_FILES=	${JARFILE:S|^|%%JAVAJARDIR%%/|}

do-install:
	${INSTALL_DATA} ${JARFILE:S|^|${WRKSRC}/|} ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in readme.html license/gpl.txt license/lgpl.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
