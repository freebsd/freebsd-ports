# New ports collection makefile for:	EPIC
# Date created:				28 Nov 2004
# Whom:					tux@pinguru.net
#
# $FreeBSD$
#

PORTNAME=	EPIC
PORTVERSION=	0.6.13
PORTREVISION=	1
CATEGORIES=	java editors devel
MASTER_SITES=	SF/e-p-i-c/e-p-i-c/${PORTNAME}%20${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	${EPIC}_${PORTVERSION}_20070808

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	EPIC adds Perl support to the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${EPIC}

EPIC=		org.epic.updatesite
ECLIPSE=	${PREFIX}/eclipse
EPICFILES=	features/org.epic.feature.main_${PORTVERSION} \
		plugins/org.epic.debug_${PORTVERSION} \
		plugins/org.epic.doc_0.6.1 \
		plugins/org.epic.lib_0.6.0 \
		plugins/org.epic.perleditor_0.6.6 \
		plugins/org.epic.regexp_0.6.0 \
		plugins/org.epic.source_${PORTVERSION}

post-extract:
.for file in ${EPICFILES}
	cd ${WRKSRC} \
	  && ${MKDIR} ${file} \
	  && ${UNZIP_CMD} ${file}.jar -d ${file}
.endfor

do-install:
.for file in ${EPICFILES}
	cd ${WRKSRC} \
	  && ${MKDIR} ${ECLIPSE}/${file} \
	  && ${FIND} ${file} -type d -exec ${MKDIR} ${ECLIPSE}/{} \; \
	  && ${FIND} ${file} -type f -exec ${INSTALL_DATA} {} ${ECLIPSE}/{} \;
.endfor

post-install:
.for file in ${EPICFILES}
	@${FIND} ${WRKSRC}/${file} -type f \
	  | ${SED} -ne 's,^${WRKSRC},${ECLIPSE:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${ECLIPSE:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
