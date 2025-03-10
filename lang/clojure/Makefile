PORTNAME=	clojure
DISTVERSION=	1.12.0.1488
CATEGORIES=	lang lisp java
MASTER_SITES=	https://download.clojure.org/install/
DISTNAME=	clojure-tools-${DISTVERSION}

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Dynamic programming language for the JVM
WWW=		https://clojure.org/

LICENSE=	EPL

RUN_DEPENDS=	bash:shells/bash \
		rlwrap:devel/rlwrap

USES=		java

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/clojure-tools

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} 's,BINDIR,${PREFIX}\/bin,g' \
		${WRKSRC}/clj
	@${REINPLACE_CMD} 's,PREFIX,${DATADIR},g' \
		${WRKSRC}/clojure

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/libexec ${STAGEDIR}${MANDIRS}/man1
	${INSTALL_DATA} ${WRKSRC}/clojure-tools-${DISTVERSION}.jar \
		${STAGEDIR}${DATADIR}/libexec
	${INSTALL_DATA} ${WRKSRC}/exec.jar ${STAGEDIR}${DATADIR}/libexec
	cd ${WRKSRC} && ${INSTALL_DATA} deps.edn example-deps.edn \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} clojure clj ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} clojure.1 clj.1 ${STAGEDIR}${MANDIRS}/man1

.include <bsd.port.mk>
