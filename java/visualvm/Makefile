PORTNAME=	visualvm
PORTVERSION=	2.0.6
CATEGORIES=	java devel
MASTER_SITES=	https://github.com/visualvm/visualvm.src/releases/download/${PORTVERSION}/
DISTNAME=	visualvm_${PORTVERSION:S/.//g}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	GUI tool combining CLI JDK tools and profiling capabilities

LICENSE=	VISUALVM
LICENSE_NAME=	VISUALVM with ClassPath Exception
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		zip:infozip
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8+
WRKSRC=		${WRKDIR}/visualvm_${PORTVERSION:S/.//g}
SUB_FILES=	visualvm.desktop

post-extract:
	@${FIND} ${WRKSRC} -type f \( -name '*.bak' -or -name '*.dll' -or -name '*.exe' \) -delete

post-patch:
	@${REINPLACE_CMD} 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/bin/visualvm

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/visualvm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/visualvm
.for i in platform visualvm
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${PREFIX}/share/visualvm/)
.endfor
.for i in visualvm.conf visualvm.clusters visualvm.icns
	@${INSTALL_DATA} ${WRKSRC}/etc/${i} ${STAGEDIR}${PREFIX}/etc/${i}.sample
.endfor
	@${UNZIP_CMD} -q -j -d ${STAGEDIR}${DATADIR} ${WRKSRC}/visualvm/modules/org-graalvm-visualvm-application.jar org/graalvm/visualvm/application/resources/visualvm.png
	@${INSTALL_DATA} ${WRKDIR}/*.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
