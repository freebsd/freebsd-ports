# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smc
PORTVERSION=	4.3.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The State Machine Compiler

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/Smc.jar ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/statemap.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/statemap.jar ${JAVAJARDIR}
	${CP} -R ${WRKSRC}/lib/statemap1.0 ${PREFIX}/include
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
