# Created by: Sutra Zhou <zhoushuqun@gmail.com>
# $FreeBSD$

PORTNAME=	ShellEd
PORTVERSION=	1.0.2a
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/1.0.2
PKGNAMEPREFIX=	eclipse-
DISTNAME=	shelled_${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	ShellEd is a superb shell script editor for Eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native

NO_STAGE=	yes
do-install:
	@${MKDIR} ${WRKSRC}/eclipse
	@${MV} ${WRKSRC}/plugins ${WRKSRC}/eclipse/plugins
	@${MV} ${WRKSRC}/features ${WRKSRC}/eclipse/features
	@${MKDIR} ${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/lib/eclipse
	@(cd ${WRKSRC}; ${FIND} -s eclipse/features eclipse/plugins -not -type d) | ${SED} -e 's,^eclipse,lib/eclipse,' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} -s -d eclipse/features eclipse/plugins -type d) \
	| ${GREP} -vE 'eclipse/plugins$$|eclipse/features$$' \
	| ${SED} -ne 's,^,@dirrm lib/,p' >> ${TMPPLIST}
	@${MV} ${WRKSRC}/eclipse/plugins ${WRKSRC}/plugins
	@${MV} ${WRKSRC}/eclipse/features ${WRKSRC}/features
	@${RM} -rf ${WRKSRC}/eclipse

.include <bsd.port.mk>
