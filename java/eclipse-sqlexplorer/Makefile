# Created by: sugimura@jp.FreeBSD.org
# $FreeBSD$

PORTNAME=	sqlexplorer
PORTVERSION=	2.2.4
PORTREVISION=	5
CATEGORIES=	java
MASTER_SITES=	SF/eclipsesql/SQL%20Explorer%20Plugin/${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	net.sourceforge.${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	A visual database query tool for Eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/share/eclipse/dropins/gef:${PORTSDIR}/java/eclipse-gef

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

NO_STAGE=	yes
do-install:
		@${MKDIR} -p ${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/lib/eclipse
		@(cd ${WRKSRC}; ${FIND} -s plugins -not -type d) \
			| ${SED} -ne 's,^,lib/eclipse/,p' >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d plugins -type d) \
			| ${GREP} -vE '^plugins$$' \
			| ${SED} -ne 's,^,@dirrm lib/eclipse/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
