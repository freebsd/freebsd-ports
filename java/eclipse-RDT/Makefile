# Created by: rehsack@web.de
# $FreeBSD$

PORTNAME=	RDT
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	java editors devel
MASTER_SITES=	SF/rubyeclipse/${PORTNAME:L}/${PORTNAME}%20${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	${RDT}-${RDTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RDT adds Ruby support to the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USES=		zip:infozip
USE_RUBY=	yes
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${RDT}

RDT=		org.rubypeople.rdt
RDTVERSION=	${PORTVERSION}.200711131528NGT
ECLIPSE=	${PREFIX}/lib/eclipse
RDTFILES=	features/org.rubypeople.rdt_${RDTVERSION} \
		features/com.aptana.rdt.mylyn_feature_${RDTVERSION} \
		plugins/com.aptana.rdt.mylyn_${RDTVERSION} \
		plugins/com.aptana.rdt.ui_${RDTVERSION} \
		plugins/com.aptana.rdt_${RDTVERSION} \
		plugins/org.epic.regexp_0.1.4 \
		plugins/org.jruby_1.0.1.4620p \
		plugins/org.kxml2_2.1.5 \
		plugins/org.rubypeople.rdt.branding_${RDTVERSION} \
		plugins/org.rubypeople.rdt.core_${RDTVERSION} \
		plugins/org.rubypeople.rdt.debug.core_${RDTVERSION} \
		plugins/org.rubypeople.rdt.debug.ui_${RDTVERSION} \
		plugins/org.rubypeople.rdt.doc.user_${RDTVERSION} \
		plugins/org.rubypeople.rdt.launching_${RDTVERSION} \
		plugins/org.rubypeople.rdt.refactoring_${RDTVERSION} \
		plugins/org.rubypeople.rdt.testunit_${RDTVERSION} \
		plugins/org.rubypeople.rdt.ui_${RDTVERSION}

post-extract:
	${MKDIR} ${WRKSRC}
.for FILE in ${RDTFILES}
	cd ${WRKSRC} \
	  && ${MKDIR} ${FILE} \
	  && ${UNZIP_CMD} ${WRKDIR}/${FILE}.jar -d ${FILE}
.endfor

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${RDTFILES}" ${STAGEDIR}${ECLIPSE}

post-install:
.for FILE in ${RDTFILES}
	@${FIND} ${WRKSRC}/${FILE} -type f \
	  | ${SED} -ne 's,^${WRKSRC},${ECLIPSE:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${FILE} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${ECLIPSE:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
