PORTNAME=	dbeaver
DISTVERSION=	25.1.3
PORTREVISION=	1
CATEGORIES=	databases java

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Free universal database tool and SQL client
WWW=		https://dbeaver.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	maven39>0:devel/maven39

USES=		dos2unix java
DOS2UNIX_GLOB=	*.MF *.css *.exsd *.java *.properties *.txt *.xml
USE_GITHUB=	yes
GH_TUPLE=	dbeaver:dbeaver-common:1379027:common/../dbeaver-common \
		dbeaver:dbeaver-jdbc-libsql:a2c75c1:jdbc/../dbeaver-jdbc-libsql
JAVA_VERSION=	21+

SUB_FILES=	${PORTNAME} ${PORTNAME}.desktop

.include <bsd.port.pre.mk>

# For create local maven repository (m2) run: make -DMAINTAINER_MODE
.if !defined(MAINTAINER_MODE)
MASTER_SITES+=	LOCAL/vvd:deps
DISTFILES+=	${PORTNAME}-${PORTVERSION}-deps.tar.xz:deps
OFFLINE=	-o
.endif # !defined(MAINTAINER_MODE)

MAVEN_ENV=	MAVEN_OPTS=-Xmx2048m JAVA_HOME=${JAVA_HOME}

# To make the build working, set the (maven) architecture to x86_64 instead of amd64
# Finally there are problems with amd64
MAVEN_ARCH=	${ARCH:S|amd64|x86_64|}

MAVEN_PARAMS=	${OFFLINE} \
		-Dmaven.repo.local=${WRKDIR}/m2 \
		-Dnative=gtk.freebsd.${MAVEN_ARCH} \
		-DskipTests clean verify \
		-T ${MAKE_JOBS_NUMBER}

DBEAVER_PATH=	product/community/target/products/org.jkiss.dbeaver.core.product/freebsd/gtk/${MAVEN_ARCH}/dbeaver

do-build:
	@(cd ${WRKSRC}/product/aggregate && \
		${SETENV} ${MAVEN_ENV} ${LOCALBASE}/bin/mvn ${MAVEN_PARAMS})

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/${DBEAVER_PATH} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/${DBEAVER_PATH}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/dbeaver \
		${STAGEDIR}${DATADIR}/plugins/org.eclipse.equinox.launcher.gtk.freebsd.x86_64_1.2.1400.v20250607-0038/eclipse_11911.so
	@(cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s "share/dbeaver" -not -type d >> ${TMPPLIST} && \
		${FIND} -s -d "share/dbeaver" -type d -empty | ${SED} -ne 's,^,@dir ,p' >> ${TMPPLIST})
	${ECHO} "bin/${PORTNAME}" >> ${TMPPLIST}
	${ECHO} "share/applications/${PORTNAME}.desktop" >> ${TMPPLIST}

.include <bsd.port.post.mk>
