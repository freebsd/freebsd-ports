# Ports collection makefile for:	Poseidon
# Date created:			February 28, 2004
# Whom:				Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	poseidon
PORTVERSION=	2.6.0
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.gentleware.org/ \
		http://download.gentleware.org/ \
		ftp://download.gentleware.biz/ \
		http://download.gentleware.biz/ \
		ftp://ftp.beine-computer.de/pub/distfiles/
DISTNAME=	${PORTNAME}${EDI}-${PORTVERSION}

MAINTAINER=	tux@pinguru.net
COMMENT=	A popular UML CASE tool

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_REINPLACE=	yes
NO_BUILD=	yes
NO_PACKAGE=	"Redistribution is not permitted"
NO_CDROM=	${NO_PACKAGE}
RESTRICTED=	${NO_PACKAGE}

.for edition in SE PE
. if defined(POSEIDON_${edition})
EDI=	${edition}
. endif
.endfor
.if !defined(EDI)
EDI=	CE
.endif

DATAFILES=	LICENSE.txt lib
.if defined(POSEIDON_PE)
DATAFILES+=	LICENSE-concurrent.txt
.endif
.if !defined(POSEIDON_SE) && !defined(POSEIDON_PE)
DATAFILES+=	license-keys.txt
.endif
PLIST_FILES=	bin/poseidon %%DATADIR%%/bin/poseidon.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	*
PLIST_FILES+=	%%DATADIR%%/docs %%DATADIR%%/examples
.endif

pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "There is a free usable edition of Poseidon for UML,"
	@${ECHO_MSG} "the Community Edition, which is installed by default."
	@${ECHO_MSG}
	@${ECHO_MSG} "If you like to install the Standard Edition or the Professional Edition"
	@${ECHO_MSG} "please specify POSEIDON_SE=yes for the Standard Edition"
	@${ECHO_MSG} "or POSEIDON_PE=yes for the Professional Edition."
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e "s,%%JAVA_HOME%%,${JAVA_HOME}," ${WRKSRC}/bin/poseidon.sh

do-install:
	${MKDIR} ${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/poseidon.sh ${DATADIR}/bin/
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
