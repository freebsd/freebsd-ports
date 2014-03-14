# Created by: Gerrit Beine (<tux@pinguru.net>)
# $FreeBSD$

PORTNAME=	poseidon
PORTVERSION=	6.0.2
CATEGORIES=	java devel
MASTER_SITES=	http://download.gentleware.com/ \
		ftp://gentleware.com/
DISTNAME=	${PORTNAME}${EDITION}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A popular UML CASE tool

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_VENDOR=	openjdk	# the port is broken with Sun JDKs
NO_BUILD=	yes
RESTRICTED=	Redistribution is not permitted

EDITION=	CE
.if defined(WITH_EDITION)
EDITION=	${WITH_EDITION}
.endif
DATAFILES=	LICENSE.txt lib licenses-3rdparty
.if ${EDITION} == "PE"
DATAFILES+=	LICENSE-concurrent.txt
.endif
PLIST_FILES=	bin/poseidon %%DATADIR%%/bin/poseidon.sh

.if make(makesum)
DISTFILES+=	${PORTNAME}CE-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}PE-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}SE-${PORTVERSION}${EXTRACT_SUFX}
.else
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
PLIST_FILES+=	%%DATADIR%%/docs %%DATADIR%%/examples
.endif

SUB_FILES=	poseidon.sh
SUB_LIST=	JAVA_HOME="${JAVA_HOME}" EDITION="${EDITION}"

NO_STAGE=	yes
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "There is a free usable edition of Poseidon for UML,"
	@${ECHO_MSG} "the Community Edition, which is installed by default."
	@${ECHO_MSG}
	@${ECHO_MSG} "If you like to install the Standard Edition or the Professional Edition"
	@${ECHO_MSG} "please specify WITH_EDITION=SE for the Standard Edition"
	@${ECHO_MSG} "or WITH_EDITION=PE for the Professional Edition."
	@${ECHO_MSG}

do-install:
	${MKDIR} ${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/poseidon.sh ${DATADIR}/bin/
	${LN} -s ${DATADIR}/bin/poseidon.sh ${PREFIX}/bin/poseidon
	cd ${WRKSRC}/ \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${LN} -s ${DOCSDIR} ${DATADIR}/docs
	cd ${WRKSRC}/docs/ \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	${MKDIR} ${EXAMPLESDIR}
	${LN} -s ${EXAMPLESDIR} ${DATADIR}/examples
	cd ${WRKSRC}/examples/ \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d \
	  | ${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S,^,${WRKSRC}/,} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DATADIR:S,^${PREFIX}/,,}/bin" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DATADIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${FIND} -s ${WRKSRC}/examples -not -type d \
	  | ${SED} -ne 's,^${WRKSRC}/examples,${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/examples -type d \
	  | ${SED} -ne 's,^${WRKSRC}/examples,@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
