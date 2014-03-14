# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	visualvm
PORTVERSION=	1.3.7
CATEGORIES=	java devel
MASTER_SITES=	https://java.net/downloads/visualvm/release${PORTVERSION:S/.//g}/
DISTNAME=	visualvm_${PORTVERSION:S/.//g}-ml

MAINTAINER=	swills@FreeBSD.org
COMMENT=	GUI tool combining CLI JDK tools and profiling capabilities

LICENSE=	VISUALVM
LICENSE_NAME=	VISUALVM with ClassPath Exception
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

USES=		zip:infozip
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}/visualvm_${PORTVERSION:S/.//g}
SUB_FILES=	visualvm.desktop

post-extract-script:
	@${FIND} ${WRKSRC} -type f \( -name '*.bak' -or -name '*.dll' -or -name '*.exe' \) -delete
	@${RM} -rf ${WRKSRC}/profiler/lib/deployed
	@${RM} -rf ${WRKSRC}/profiler/lib/jfluid-server-15.jar

post-patch-script:
	@${REINPLACE_CMD} 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/bin/visualvm

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/visualvm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/visualvm
.for i in platform profiler visualvm
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${PREFIX}/share/visualvm/)
.endfor
.for i in visualvm.conf visualvm.clusters visualvm.icns
	@${INSTALL_DATA} ${WRKSRC}/etc/${i} ${STAGEDIR}${PREFIX}/etc/${i}-dist
.endfor
	@${UNZIP_CMD} -q -j -d ${STAGEDIR}${DATADIR} ${WRKSRC}/visualvm/modules/com-sun-tools-visualvm-application.jar com/sun/tools/visualvm/application/resources/visualvm.png
	@${INSTALL_DATA} ${WRKDIR}/*.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
