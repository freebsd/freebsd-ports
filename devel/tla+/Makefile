PORTNAME=	tla+
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.4
CATEGORIES=	devel java

MAINTAINER=	patmaddox@FreeBSD.org
COMMENT=	TLC is a model checker for specifications written in TLA+
WWW=		https://www.tlapl.us

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		java:ant,run
USE_GITHUB=	yes
GH_ACCOUNT=	tlaplus
GH_PROJECT=	tlaplus
JAVA_VERSION=	11

MAKE_ARGS=	-f customBuild.xml
ALL_TARGET=	compile dist

NO_ARCH=	yes

_TLA_CMD=	exec ${JAVA} -classpath ${JAVAJARDIR}/tla2tools.jar

BUILD_WRKSRC=	${WRKSRC}/tlatools/org.lamport.tlatools

PLIST_FILES=	${JAVAJARDIR}/tla2tools.jar \
		bin/tla-pcal \
		bin/tla-sany \
		bin/tla-tla2sany \
		bin/tla-tla2tex \
		bin/tla-tlc

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/dist/tla2tools.jar ${STAGEDIR}${JAVAJARDIR}/tla2tools.jar
	@${PRINTF} '#!/bin/sh\n${_TLA_CMD} pcal.trans "$$@"\n' > ${WRKDIR}/tla-pcal
	${INSTALL_SCRIPT} ${WRKDIR}/tla-pcal ${STAGEDIR}${PREFIX}/bin/tla-pcal
	@${PRINTF} '#!/bin/sh\n${_TLA_CMD} tla2sany.SANY "$$@"\n' > ${WRKDIR}/tla-sany
	${INSTALL_SCRIPT} ${WRKDIR}/tla-sany ${STAGEDIR}${PREFIX}/bin/tla-sany
	@${PRINTF} '#!/bin/sh\n${_TLA_CMD} tla2sany.xml.XMLExporter "$$@"\n' > ${WRKDIR}/tla-tla2sany
	${INSTALL_SCRIPT} ${WRKDIR}/tla-tla2sany ${STAGEDIR}${PREFIX}/bin/tla-tla2sany
	@${PRINTF} '#!/bin/sh\n${_TLA_CMD} tla2tex.TLA "$$@"\n' > ${WRKDIR}/tla-tla2tex
	${INSTALL_SCRIPT} ${WRKDIR}/tla-tla2tex ${STAGEDIR}${PREFIX}/bin/tla-tla2tex
	@${PRINTF} '#!/bin/sh\n${_TLA_CMD} -XX:+UseParallelGC tlc2.TLC "$$@"\n' > ${WRKDIR}/tla-tlc
	${INSTALL_SCRIPT} ${WRKDIR}/tla-tlc ${STAGEDIR}${PREFIX}/bin/tla-tlc

.include <bsd.port.mk>
