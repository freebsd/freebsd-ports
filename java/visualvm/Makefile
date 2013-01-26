# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	visualvm
PORTVERSION=	1.3.5
CATEGORIES=	java devel
MASTER_SITES=	http://java.net/downloads/visualvm/release${PORTVERSION:S/.//g}/
DISTNAME=	visualvm_${PORTVERSION:S/.//g}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	GUI tool combining CLI JDK tools and profiling capabilities

LICENSE=	VISUALVM
LICENSE_NAME=	VISUALVM with ClassPath Exception
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

USE_ZIP=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

post-extract-script:
	@${FIND} ${WRKSRC} -type f \( -name '*.bak' -or -name '*.dll' -or -name '*.exe' \) -delete
	@${RM} -rf ${WRKSRC}/profiler/lib/deployed
	@${RM} -rf ${WRKSRC}/profiler/lib/jfluid-server-15.jar

post-patch-script:
	@${REINPLACE_CMD} 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/bin/visualvm

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/visualvm ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/visualvm

.for i in platform profiler visualvm
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${PREFIX}/share/visualvm/)
.endfor

.for file in visualvm.conf visualvm.clusters visualvm.icns
	@${INSTALL_DATA} ${WRKSRC}/etc/${file} ${PREFIX}/etc/${file}-dist
	@if [ ! -f ${PREFIX}/etc/${file} ] ; then \
		${INSTALL_DATA} ${WRKSRC}/etc/${file} ${PREFIX}/etc/${file} ; \
	fi
.endfor

.include <bsd.port.mk>
