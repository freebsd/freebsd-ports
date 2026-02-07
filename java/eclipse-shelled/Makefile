PORTNAME=	ShellEd
PORTVERSION=	1.0.2a
PORTREVISION=	5
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/1.0.2
PKGNAMEPREFIX=	eclipse-
DISTNAME=	shelled_${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	Shell script editor for Eclipse
WWW=		https://sourceforge.net/projects/shelled/

RUN_DEPENDS=	eclipse:java/eclipse

USES=		java zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
JAVA_OS=	native

do-install:
	@${MKDIR} ${WRKSRC}/eclipse
	@${MV} ${WRKSRC}/plugins ${WRKSRC}/eclipse/plugins
	@${MV} ${WRKSRC}/features ${WRKSRC}/eclipse/features
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/eclipse/plugins ${STAGEDIR}${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/eclipse/features ${STAGEDIR}${PREFIX}/lib/eclipse
	@(cd ${WRKSRC}; ${FIND} -s eclipse/features eclipse/plugins -not -type d) | ${SED} -e 's,^eclipse,lib/eclipse,' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} -s -d eclipse/features eclipse/plugins -type d -empty) \
		| ${GREP} -vE 'eclipse/plugins$$|eclipse/features$$' \
		| ${SED} -ne 's,^,@dir lib/,p' >> ${TMPPLIST}
	@${MV} ${WRKSRC}/eclipse/plugins ${WRKSRC}/plugins
	@${MV} ${WRKSRC}/eclipse/features ${WRKSRC}/features
	@${RM} -r ${WRKSRC}/eclipse

.include <bsd.port.mk>
