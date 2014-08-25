# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	eclemma
PORTVERSION=	1.5.3
CATEGORIES=	devel java editors
MASTER_SITES=	SF/${PORTNAME}/01_EclEmma_Releases/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java code coverage tool for Eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

PLUGIN_PATHS=	features plugins

USES=		zip
NO_BUILD=	yes

WRKSRC=		${WRKDIR}
ECLIPSE=	lib/eclipse

PLIST_SUB=	VER=${PORTVERSION} \
		ECLIPSE=${ECLIPSE}

NO_STAGE=	yes
do-install:
.for _path in ${PLUGIN_PATHS}
	@${MKDIR} ${PREFIX}/${ECLIPSE}/${_path}
	@${CP} -r ${WRKSRC}/${_path}/* ${PREFIX}/${ECLIPSE}/${_path}/
.endfor

plist: build
	@${ECHO} "===>  Rebuilding PLIST."
	@${TOUCH} ${PLIST}
	@${RM} ${PLIST}
.for _path in ${PLUGIN_PATHS}
	@${FIND} -ds ${WRKSRC}/${_path}/ -not -type d \
		| ${SED} "s|${WRKSRC}|%%ECLIPSE%%|1" \
		| ${SED} "s|${PORTVERSION}|%%VER%%|g" \
		>> ${PLIST}
	@${FIND} -ds ${WRKSRC}/${_path}/ -mindepth 1 -type d \
		| ${SED} "s|${WRKSRC}|@dirrm %%ECLIPSE%%|1" \
		| ${SED} "s|${PORTVERSION}|%%VER%%|g" \
		>> ${PLIST}
	@${ECHO} "@dirrmtry %%ECLIPSE%%/${_path}" >> ${PLIST}
.endfor
	@${ECHO} "@dirrmtry %%ECLIPSE%%" >> ${PLIST}

.include <bsd.port.mk>
