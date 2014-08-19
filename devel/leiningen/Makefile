# $FreeBSD$

PORTNAME=	leiningen
PORTVERSION=	2.4.3
CATEGORIES=	devel lisp java
MASTER_SITES=	GITHUB:source1 \
		https://github.com/technomancy/leiningen/releases/download/${PORTVERSION}/:source2
DISTFILES=	leiningen-${PORTVERSION}.tar.gz:source1 \
		leiningen-${PORTVERSION}-standalone.jar:source2
EXTRACT_ONLY=	leiningen-${PORTVERSION}.tar.gz

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Automate Clojure projects

LICENSE=	EPL

USE_GITHUB=	yes
GH_ACCOUNT=	technomancy
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	0ae3b55

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
	${INSTALL_DATA} ${DISTDIR}/leiningen-${PORTVERSION}-standalone.jar ${STAGEDIR}${JAVAJARDIR}/leiningen.jar

.include <bsd.port.mk>
