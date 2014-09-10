# Created by: gldisater@gldis.ca
# $FreeBSD$

PORTNAME=	uml
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/uml2/downloads/drops/${PORTVERSION}/R200509282050/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	uml2-SDK-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework creating UML diagrams in Eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/share/eclipse/dropins/emf:${PORTSDIR}/java/eclipse-emf

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/eclipse/plugins ${STAGEDIR}${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/eclipse/features ${STAGEDIR}${PREFIX}/lib/eclipse
	@(cd ${WRKSRC}; ${FIND} -s eclipse/features eclipse/plugins -not -type d) | ${SED} -e 's,^eclipse,lib/eclipse,' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} -s -d eclipse/features eclipse/plugins -type d) \
		| ${GREP} -vE 'eclipse/plugins$$|eclipse/features$$' \
		| ${SED} -ne 's,^,@dirrm lib/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
