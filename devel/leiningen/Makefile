# $FreeBSD$

PORTNAME=	leiningen
PORTVERSION=	2.5.1
CATEGORIES=	devel lisp java
MASTER_SITES=	GH:source1 \
		https://github.com/technomancy/leiningen/releases/download/${PORTVERSION}/:source2
DISTFILES=	${DISTNAME}.tar.gz:source1 \
		leiningen-${PORTVERSION}-standalone.zip:source2
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Automate Clojure projects

LICENSE=	EPL

USE_GITHUB=	yes
GH_ACCOUNT=	technomancy

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

PLIST_FILES=	bin/lein \
		%%JAVAJARDIR%%/leiningen.jar

post-patch:
	${REINPLACE_CMD} -e "s|/bin/bash|${PREFIX}/bin/bash|" \
		-e "s|LEIN_JAR=.*|LEIN_JAR=${JAVAJARDIR}/leiningen.jar|" \
		${WRKSRC}/bin/lein-pkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lein-pkg ${STAGEDIR}${PREFIX}/bin/lein
	${INSTALL_DATA} ${DISTDIR}/leiningen-${PORTVERSION}-standalone.zip ${STAGEDIR}${JAVAJARDIR}/leiningen.jar

.include <bsd.port.mk>
