PORTNAME=	bined
PORTVERSION=	0.2.3
CATEGORIES=	editors java
MASTER_SITES=	SF/${PORTNAME}/editor/${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Binary/hexadecimal editor written in Java
WWW=		https://bined.exbin.org/editor/

LICENSE=	APACHE20

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} "help lib" \
		${STAGEDIR}${JAVAJARDIR}
	${PRINTF} '#!/bin/sh\n\ncd ${JAVAJARDIR} && exec ${JAVA}\
		-jar ${JAVAJARDIR}/${PORTNAME}.jar "$$@"\n' \
		> ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TR} -d \\r < ${WRKSRC}/changes.txt \
		> ${STAGEDIR}${DOCSDIR}/changes.txt

.include <bsd.port.mk>
