# Created by: sugimura@jp.FreeBSD.org
# $FreeBSD$

PORTNAME=	sysdeo
PORTVERSION=	3.1.0
PORTREVISION=	4
CATEGORIES=	java
MASTER_SITES=	http://www.sysdeo.com/sysdeo/content/download/393/4930/file/
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-tomcat
DISTNAME=	tomcatPluginV31
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	Sysdeo Tomcat Launcher plugin for Eclipse

RUN_DEPENDS+=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

NO_STAGE=	yes
do-install:
		@${MKDIR} -p ${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/com.sysdeo.eclipse.tomcat_${PORTVERSION} ${PREFIX}/lib/eclipse/plugins
		@(cd ${WRKSRC}; ${FIND} -s com.sysdeo.eclipse.tomcat_${PORTVERSION} -not -type d) \
			| ${SED} -ne 's,^,lib/eclipse/plugins/,p' >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d com.sysdeo.eclipse.tomcat_${PORTVERSION} -type d) \
			| ${SED} -ne 's,^,@dirrm lib/eclipse/plugins/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
