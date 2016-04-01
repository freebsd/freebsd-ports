# Created by: tux@pinguru.net
# $FreeBSD$

PORTNAME=	EPIC
PORTVERSION=	0.6.35
PORTREVISION=	3
CATEGORIES=	java editors devel
MASTER_SITES=	SF/e-p-i-c/e-p-i-c/${PORTNAME}%20${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	${EPIC}_${PORTVERSION}_20090521

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EPIC adds Perl support to the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:java/eclipse

NO_BUILD=	yes
USES=		zip:infozip
WRKSRC=		${WRKDIR}/${EPIC}

EPIC=		org.epic.updatesite
ECLIPSE=	${PREFIX}/lib/eclipse
EPICFILES=	features/org.epic.feature.main_${PORTVERSION} \
		plugins/org.epic.debug_0.6.27 \
		plugins/org.epic.doc_0.6.2 \
		plugins/org.epic.lib_0.6.1 \
		plugins/org.epic.perleditor_0.6.24 \
		plugins/org.epic.regexp_0.6.1 \
		plugins/org.epic.source_${PORTVERSION}

post-extract:
.for file in ${EPICFILES}
	cd ${WRKSRC} \
	  && ${MKDIR} ${file} \
	  && ${UNZIP_CMD} ${file}.jar -d ${file}
.endfor

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${EPICFILES}" ${STAGEDIR}${ECLIPSE}

post-install:
.for file in ${EPICFILES}
	@${FIND} ${WRKSRC}/${file} -type f \
	  | ${SED} -ne 's,^${WRKSRC},${ECLIPSE:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d -empty \
	  | ${SED} -ne 's,^${WRKSRC},@dir ${ECLIPSE:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
