# New ports collection makefile for:   maven
# Date created:        10 Dec 2003
# Whom:                jerry
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	2.0.2
CATEGORIES=	java
MASTER_SITES=	http://www.orionserver.com/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	unidevel@hotpop.com
COMMENT=	Orion 2.0.2 application server

RESTRICTED=	"Redistribution of binaries is not permitted"
NO_CDROM=	"Redistribution of binaries is not permitted"

USE_JAVA=	1.3+
NO_BUILD=	yes

USE_ZIP=	yes
ORION_DIR=	${PREFIX}/orion

WRKSRC=		${WRKDIR}/${PORTNAME}
CONTROLSCRIPT=	orion.sh
PKGMESSAGE=	pkg-message

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of licensing restrictions, you must fetch Orion binary distribution\n\
manually.  Please access \n\
http://www.orionserver.com/mirrordownload.jsp?file=orion2.0.2.zip \n\
with a web browser to download Orion 2.0.2 binary. Please place this file in\n\
${DISTDIR}.\n
.endif

pre-install:
	${SED} -e "s|%%JAVA_HOME%%|${JAVA_HOME}|g;" \
	       -e "s|%%ORION_HOME%%|${ORION_DIR}|g;" \
	       ${FILESDIR}/${CONTROLSCRIPT} > ${WRKSRC}/${CONTROLSCRIPT}

do-install:
	@${MKDIR} ${ORION_DIR}
	@cd ${WRKSRC} && ${FIND} . -type d -exec \
	    ${MKDIR} ${ORION_DIR}/\{} \;
	@cd ${WRKSRC} && ${FIND} . -type f -exec \
	    ${INSTALL} \{} ${ORION_DIR}/\{} \;

post-install:
	@if [ -f ${PREFIX}/bin/${CONTROLSCRIPT} ]; then \
		rm -f ${LOCALBASE}/bin/${CONTROLSCRIPT}; \
	fi
	@${LN} -sf ${ORION_DIR}/${CONTROLSCRIPT} ${LOCALBASE}/bin/${CONTROLSCRIPT}
	@${SED} -e "s|%%JAVA_HOME%%|${JAVA_HOME}|g;" \
		-e "s|%%ORION_HOME%%|${ORION_DIR}|g;" \
		${PKGMESSAGE}

.include <bsd.port.post.mk>
