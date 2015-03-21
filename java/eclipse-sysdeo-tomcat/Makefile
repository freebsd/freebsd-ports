# Created by: sugimura@jp.FreeBSD.org
# $FreeBSD$

PORTNAME=	sysdeo
PORTVERSION=	3.1.0
PORTREVISION=	5
CATEGORIES=	java
MASTER_SITES=	http://www.sysdeo.com/sysdeo/content/download/393/4930/file/
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-tomcat
DISTNAME=	tomcatPluginV31
DIST_SUBDIR=	eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sysdeo Tomcat Launcher plugin for Eclipse

BROKEN=		plugin is obsolete or malfunctioning with latest eclipse
DEPRECATED=	evaluation recommendation is to remove rather than update
EXPIRATION_DATE=	2015-04-18

RUN_DEPENDS+=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/eclipse/plugins
	@${CP} -r ${WRKSRC}/com.sysdeo.eclipse.tomcat_${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/eclipse/plugins
	@(cd ${WRKSRC}; ${FIND} -s com.sysdeo.eclipse.tomcat_${PORTVERSION} -not -type d) \
		| ${SED} -ne 's,^,lib/eclipse/plugins/,p' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} -s -d com.sysdeo.eclipse.tomcat_${PORTVERSION} -type d -empty) \
		| ${SED} -ne 's,^,@dir lib/eclipse/plugins/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
