PORTNAME=	alienarena
DISTVERSION=    7.71.6
PORTEPOCH=	1
CATEGORIES=	games
PKGNAMESUFFIX=	-data

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Alien Arena (data)
WWW=		https://alienarena.org/

LICENSE=	AlienArena-Data
LICENSE_NAME=	Freely redistributable as a whole
LICENSE_FILE=	${WRKSRC}/docs/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
# See also http://red.planetarena.org/forum/showthread.php?tid=716 where fedora asked for clarification

USE_GITHUB=	yes

NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/data1/Makefile* ${WRKSRC}/data1/configure* ${WRKSRC}/data1/aclocal*

pre-install:
	@${RM} -f ${PLIST}

.	for DIRE in arena data1
		@cd ${WRKSRC} && \
			${FIND} ${DIRE} -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
				${FIND} ${DIRE} -type d | ${SORT} -r | ${SED} -e 's|^|@dir %%DATADIR%%/|' >> ${PLIST}
.	endfor

	@cd ${WRKSRC}/docs && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%PORTDOCS%%%%DOCSDIR%%/|' >> ${PLIST} && \
		${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|%%PORTDOCS%%@dir %%DOCSDIR%%/|' >> ${PLIST}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "arena data1" ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} "*" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
