PORTNAME=	artemis
DISTVERSIONPREFIX=	v
DISTVERSION=	18.2.0
CATEGORIES=	biology java

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DNA sequence viewer and annotation tool
WWW=		https://www.sanger.ac.uk/tool/artemis/ \
		https://github.com/sanger-pathogens/Artemis

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	maven310>0:devel/maven310
RUN_DEPENDS=	bash:shells/bash

USES=		java shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	sanger-pathogens
SHEBANG_FILES=	act art bamview dnaplotter test/*.sh etc/go_associations.pl
NO_ARCH=	yes

MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

.if (${DEV_UPDATE_MODE} != "yes")
MASTER_SITES+=	LOCAL/yuri/:deps
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:deps
MVN_ARGS=	--offline
.endif

post-extract:
	@cd ${WRKDIR} && ${MV} Artemis-${DISTVERSION} ${PORTNAME}-${DISTVERSION}

do-build: # validate installs the bundled legacy jars into the local repository and must run in a separate invocation
.for t in validate package
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${MVN_ARGS} \
		-Dmaven.test.skip=true \
		-Duser.home=${WRKDIR} \
		${t}
.endfor

.if (${DEV_UPDATE_MODE} == "yes")
post-build: do-test
	@cd ${WRKDIR} && ${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} .m2
	@${ECHO} "(!!!) Please upload the deps archive: ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.endif

# tests excluded below need network access, a display or EMBOSS
do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${MVN_ARGS} \
		-Duser.home=${WRKDIR} \
		-Dtest='!BamUtilsTest,!CircularGenomeControllerTest,!RunBlastAtNCBITest,!TestIbatisDAO,!TestJdbcDAO,!WriteVCFTest,!WriteVariantSitesTest' \
		test

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}-${PORTVERSION}/target
	@cd ${WRKSRC} && ${COPYTREE_SHARE} etc ${STAGEDIR}${PREFIX}/${PORTNAME}-${PORTVERSION}
	@cd ${WRKSRC}/target && ${COPYTREE_SHARE} jars ${STAGEDIR}${PREFIX}/${PORTNAME}-${PORTVERSION}/target
.for f in art act bamview dnaplotter
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${PORTNAME}-${PORTVERSION}/${f}
	@(${ECHO} "#!/bin/sh"; ${ECHO} ""; ${ECHO} "cd ${PREFIX}/${PORTNAME}-${PORTVERSION} && ./${f} \""$$"@\"") > ${STAGEDIR}${PREFIX}/bin/${f}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

# tests as of 18.2.0: Tests run: 281, Failures: 0, Errors: 0, Skipped: 1

.include <bsd.port.mk>
