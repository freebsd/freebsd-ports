# $FreeBSD$

PORTNAME=	cytoscape
DISTVERSION=	3.6.1
CATEGORIES=	biology java
MASTER_SITES=	LOCAL/yuri/:maven \
		http://people.freebsd.org/~yuri/:maven
DISTFILES=	FreeBSD-${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz:maven

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software to visualize molecular interaction networks, gene expression

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/api/LICENSE

BROKEN_aarch64=		fails to build: Cytoscape Third-Party Dependencies (third-party): FAILURE
BROKEN_armv6=		fails to build: Cytoscape Third-Party Dependencies (third-party): FAILURE
BROKEN_armv7=		fails to build: Cytoscape Third-Party Dependencies (third-party): FAILURE

BUILD_DEPENDS=	mvn:devel/maven \
		bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix
SHEBANG_FILES=	gui-distribution/assembly/src/main/bin/cytoscape.sh
USE_JAVA=	yes
USE_GITHUB=	yes
GH_TUPLE=	${PORTNAME}:${PORTNAME}-parent:${DISTVERSION}:p/parent \
		${PORTNAME}:${PORTNAME}-api:${DISTVERSION}:a/api \
		${PORTNAME}:${PORTNAME}-impl:${DISTVERSION}:i/impl \
		${PORTNAME}:${PORTNAME}-support:${DISTVERSION}:s/support \
		${PORTNAME}:${PORTNAME}-gui-distribution:${DISTVERSION}:g/gui-distribution \
		${PORTNAME}:${PORTNAME}-app-template:${DISTVERSION}:d/app-developer
NO_ARCH=	yes

USER_WRKDIR=	~/.${PORTNAME}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn --offline \
		-fae install \
		-Dmaven.test.skip=true \
		-Duser.home=${WRKDIR}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} gui-distribution ${STAGEDIR}${DATADIR}
	# shouldn't be needed, but the executable bit sometimes isn't set
	@${CHMOD} +x ${STAGEDIR}${DATADIR}/gui-distribution/assembly/target/cytoscape/cytoscape.sh
	@${CHMOD} +x ${STAGEDIR}${DATADIR}/gui-distribution/assembly/target/cytoscape/framework/bin/karaf
	# create a shell executable calling the real command
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "cd ${DATADIR} && JAVA_HOME=${JAVA_HOME} ./gui-distribution/assembly/target/cytoscape/cytoscape.sh \"$@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# redirect user data to /tmp until they fix the location so that it would write under $HOME
	@${RM} -r ${STAGEDIR}${DATADIR}/gui-distribution/assembly/target/cytoscape/framework/instances
	@cd ${STAGEDIR}${DATADIR}/gui-distribution/assembly/target/cytoscape/framework && ${LN} -s /tmp instances
	# use the automatic plist: a few hundred files are under DATADIR
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | ${GREP} -v ^\/ | ${SED} -e 's|%%DATADIR%%|share/${PORTNAME}|' > ${TMPPLIST}

.include <bsd.port.mk>
