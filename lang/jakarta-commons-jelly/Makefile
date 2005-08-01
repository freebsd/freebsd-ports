# Ports collection makefile for:	Jakarta Commons Jelly
# Date created:				29 July 2005
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	commons-jelly
PORTVERSION=	1.0
CATEGORIES=	lang devel java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	${PORTNAME:S,-,/,}/binaries
PKGNAMEPREFIX=	jakarta-

MAINTAINER=	hq@FreeBSD.org
COMMENT=	XML based scripting engine

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
READMES=	LICENSE.txt NOTICE.txt README.txt RELEASE-NOTES.txt
DATAFILES=	custom lib bin

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

SUB_FILES=	jelly.sh
PLIST_FILES=	bin/jelly

post-extract:
	${RM} -f ${WRKSRC}/bin/jelly.bat ${WRKSRC}/bin/jelly

do-install:
	cd ${WRKSRC} && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} ";"
	cd ${WRKSRC} && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} ";"
	${INSTALL_SCRIPT} ${WRKDIR}/jelly.sh ${PREFIX}/bin/jelly
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} ";"
	${INSTALL_DATA} ${READMES:S|^|${WRKSRC}/|} ${DOCSDIR}/
.endif

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S,^,${WRKSRC}/,} -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}

.include <bsd.port.mk>
