# Created by: ijliao
# $FreeBSD$

PORTNAME=	clojure
PORTVERSION=	1.10.0.411
CATEGORIES=	lang lisp java
MASTER_SITES=	https://download.clojure.org/install/
DISTNAME=	clojure-tools-${PORTVERSION}

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Dynamic programming language for the JVM

LICENSE=	EPL

RUN_DEPENDS=	bash:shells/bash \
		rlwrap:devel/rlwrap

USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}
WRKSRC=		${WRKDIR}/clojure-tools

post-patch:
	@${REINPLACE_CMD} 's,PREFIX,${DATADIR},g' \
		${WRKSRC}/clojure

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/libexec ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/clojure-tools-${PORTVERSION}.jar \
		${STAGEDIR}${DATADIR}/libexec
	cd ${WRKSRC} && ${INSTALL_DATA} deps.edn example-deps.edn \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} clojure clj ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} clojure.1 clj.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
