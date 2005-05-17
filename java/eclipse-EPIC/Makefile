# New ports collection makefile for:	EPIC
# Date created:				28 Nov 2004
# Whom:					tux@pinguru.net
#
# $FreeBSD$
#

PORTNAME=	EPIC
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	java editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	e-p-i-c
PKGNAMEPREFIX=	eclipse-
DISTNAME=	${EPIC}_${PORTVERSION}_20040711

MAINTAINER=	tux@pinguru.net
COMMENT=	EPIC adds Perl support to the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${EPIC}

EPIC=		org.epic.updatesite
ECLIPSE=	${PREFIX}/eclipse
EPICFILES=	features/org.epic.feature.main_0.3.0 \
		plugins/org.epic.debug_0.2.0 \
		plugins/org.epic.ext.cbg.editor_0.3.0 \
		plugins/org.epic.perleditor_0.1.2 \
		plugins/org.epic.regexp_0.1.2

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
