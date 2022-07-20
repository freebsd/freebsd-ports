PORTNAME=	scala
DISTVERSION=	3.1.0
CATEGORIES=	lang java
MASTER_SITES=	https://github.com/lampepfl/dotty/releases/download/${DISTVERSION}/
DISTNAME=	scala3-${DISTVERSION}

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Scala Programming Language

LICENSE=	APACHE20

RUN_DEPENDS=	bash:shells/bash

USES=		cpe
CPE_VENDOR=	${PORTNAME}-lang
USE_JAVA=	yes
JAVA_VERSION=	1.8+

NO_ARCH=	yes
NO_BUILD=	yes

SCALA_HOME=	${DATADIR}
SCALA_SHRDIRS=	lib
SCALA_BINS=	common scala scalac scaladoc

PLIST_FILES=	${SCALA_BINS:S,^,bin/,}

PORTDATA=	*

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   SCALA_HOME:    ${SCALA_HOME}"

do-install:
	@${MKDIR} ${STAGEDIR}${SCALA_HOME}/bin
.for f in ${SCALA_BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${SCALA_HOME}/bin/${f}
	${RLN} ${STAGEDIR}${SCALA_HOME}/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
.for d in ${SCALA_SHRDIRS}
	(cd ${WRKSRC}/${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${SCALA_HOME}/${d})
.endfor

.include <bsd.port.mk>
