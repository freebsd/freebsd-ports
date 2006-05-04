# Ports collection makefile for:	Fujaba
# Date created:			July 14, 2005
# Whom:				Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	fujaba
PORTVERSION=	4.3.1
CATEGORIES=	devel java
MASTER_SITES=	http://wwwcs.uni-paderborn.de/cs/fujaba/downloads/packages/Fujaba_4/
DISTNAME=	FujabaToolSuite_Developer${PORTVERSION:S/./_/g}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Another UML CASE tool

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Fujaba\ Tool\ Suite\ ${PORTVERSION}

DATAFILES=	DTDs Templates libs plugins stylesheets\
		GNULesserGeneralPublicLicense.txt api.zip fujaba.jar src.jar

PLIST_FILES=	bin/fujaba %%DATADIR%%/bin/fujaba.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	*
PLIST_FILES+=	%%DATADIR%%/doc
.endif

SUB_FILES=	fujaba.sh
SUB_LIST=	LOCALBASE="${LOCALBASE}" DATADIR="${DATADIR}"

do-install:
	${MKDIR} ${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/fujaba.sh ${DATADIR}/bin/
	${LN} -s ${DATADIR}/bin/fujaba.sh ${PREFIX}/bin/fujaba
	cd ${WRKSRC}/ \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${LN} -s ${DOCSDIR} ${DATADIR}/doc
	cd ${WRKSRC}/doc/ \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d \
	  | ${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S,^,${WRKSRC}/,} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DATADIR:S,^${PREFIX}/,,}/bin" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DATADIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}

.include <bsd.port.mk>
