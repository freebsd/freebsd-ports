PORTNAME=	kotlin
PORTVERSION=	1.5.20
CATEGORIES=	lang
MASTER_SITES=	https://github.com/JetBrains/kotlin/releases/download/v${PORTVERSION}/
DISTNAME=	kotlin-compiler-${PORTVERSION}

MAINTAINER=	mizhka@FreeBSD.org
COMMENT=	Kotlin Programming Language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/license/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash

USES=	zip

WRKSRC=	${WRKDIR}/kotlinc

USE_JAVA=	yes
NO_BUILD=	yes

KOTLIN_BIN=	kapt \
		kotlin \
		kotlin-dce-js \
		kotlinc \
		kotlinc-js \
		kotlinc-jvm

post-extract:
	${RM} ${WRKSRC}/bin/*.bat

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}/bin
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/lib
.for f in ${KOTLIN_BIN}
	${LN} -sf ${DATADIR}/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/build.txt ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
