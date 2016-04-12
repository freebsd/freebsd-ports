# Created by: sugimura@jp.FreeBSD.org
# $FreeBSD$

PORTNAME=	log4e
PORTVERSION=	1.5.1
CATEGORIES=	java
MASTER_SITES=	http://log4e.jayefem.de/download/eclipse3/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	de.jayefem.${PORTNAME}_free_${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eclipse plugin to use logger easily in Java projects

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:java/eclipse

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/plugins ${STAGEDIR}${PREFIX}/lib/eclipse
	@${CP} -r ${WRKSRC}/features ${STAGEDIR}${PREFIX}/lib/eclipse
	@(cd ${WRKSRC}; ${FIND} -s features plugins -not -type d) \
		| ${SED} -ne 's,^,lib/eclipse/,p' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} -s -d features plugins -type d -empty) \
		| ${GREP} -vE 'plugins$$|features$$' \
		| ${SED} -ne 's,^,@dir lib/eclipse/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
